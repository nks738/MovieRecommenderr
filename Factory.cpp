nclude "Movie.hpp"
#include "Category.hpp"
#include "Media.hpp"
#include "Factory.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

void Factory::parseMovieData(){

    string line = "";
    
    string inputFile = "OGmoviedata.csv";

    /*inputting from the .csv movie data file */
    ifstream myFile;
    myFile.open(inputFile);

    /*All variables needed to make each movie object */
    string movieTitle = "";
    string  descrip = "";
    string director = ""; 
    string dumGenre = "";
    string dumActor = "";
    
    int year;
    double score;
    vector<string> actors;
    vector<string> genres;

    /*file guard*/
    if (!myFile.is_open()) {
      cout << "Error couldnt open " << inputFile << endl;
      return;
    }


    while(getline(myFile, line)){
        tokenizer<escaped_list_separator<char> > tok(line);
        tokenizer<escaped_list_separator<char> >::iterator beg = tok.begin();
        
        Movie* currMovie = new Movie();
        
        /*movietitle*/
        movieTitle = *beg;
        ++beg;


        /*create genre list*/
        for(int i =0; i < beg->size(); i++){
            if(beg->at(i) != ','){
                dumGenre+= beg->at(i);
            }
            if(beg->at(i) == ','){
                genres.push_back(dumGenre);
                dumGenre = "";
            }
        }
        genres.push_back(dumGenre);
        dumGenre = "";
        ++beg;

        /*descript*/
        descrip = *beg;
        ++beg;

        /*director*/
        director = *beg;
        ++beg;
        
        /*actors*/
        for(int i =0; i < beg->size(); i++){
            if(beg->at(i) != ','){
                dumActor+= beg->at(i);
            }
            if(beg->at(i) == ','){
                actors.push_back(dumActor);
                dumActor = "";
            }
        }
        actors.push_back(dumActor);
        dumActor = "";
        ++beg;

        /*year*/
        year = stoi(*beg);
        ++beg;

        score = stod(*beg);
        
        /*REMEMBER TO USE THE MOVIE OBJECT AND VARIABLES TO ASSIGN THEM TO THE OBJECT AT THE END OF THE WHILE LOOP*/

        currMovie->setTitle(movieTitle);
        currMovie->setGenres(genres);
        currMovie->addDescription(descrip);
        currMovie->addDirector(director);
        currMovie->addActors(actors);
        currMovie->addProdYear(year);
        currMovie->addRating(score);

        /*add & creat currMovie to movieMap*/
        movieMap.emplace(movieTitle, currMovie);
        movieVec.push_back(currMovie);

        genres.clear();
        actors.clear();
        descrip = "";
        movieTitle = "";
        year = 0;
        score = 0.0;

    }
        
    myFile.close();

    return;
}

vector<Movie*> Factory::getMovieVec(){
  
  return this->movieVec;
}

void Factory::filter(){
  filter_functions->filter(this);
  
}

void Factory::setMovieVec(vector<Movie*> movVec){
    this->movieVec = movVec;
}

bool Factory::movieExists(string movName){
  map<string, Movie*>::iterator it;
  it = movieMap.find(movName);
  if(it == movieMap.end()){
    return false;
  }
  return true;
}

 map<string, Movie*> Factory::getMovieMap(){
   return this->movieMap;
 }
