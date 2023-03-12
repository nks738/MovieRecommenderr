#include "DisplayStrategy.hpp"
#include <string>
#include <iostream>
#include "Category.hpp"
#include "Movie.hpp"
#include <vector>

#include "Factory.hpp"

using namespace std; 
/*
*NOTE*
------
These functions assume that the vector of movies is already sorted!
------
*/
/*FilterTop*/
void FilterTopTen::filter(Factory* movie){
  vector<Movie*> temp = movie->getMovieVec();
  for(unsigned int i = 0; i < 10; ++i){
    cout << i+1 << ") " << temp.at(i)->getTitle() << ": " << temp.at(i)->getRating() << endl << temp.at(i)->getDescription() << endl << endl; 
  }
  return;
}


void FilterTopTenRecent::filter(Factory* movie) {
    int year = this->year; 
    vector<Movie*> temp = movie->getMovieVec();
    vector<Movie*> top_10_recent; 
    int counter = 0;
      for(unsigned int i = 0; i < temp.size() && top_10_recent.size() < 10; ++i){
        if(temp.at(i)->getYear() == year) {
            top_10_recent.push_back(temp.at(i));
            cout << counter+1 << ") " << temp.at(i)->getTitle() << ": " << temp.at(i)->getRating() << endl << temp.at(i)->getDescription() << endl << endl; 
            counter++;
        }
       
      }
}
int FilterTopTenRecent::getYear(){
  return this->year; 
}

void FilterActor::filter(Factory* movie) {
    string actor = this->actor;
    vector<Movie*> temp = movie->getMovieVec();
    int i = 0;
    int counter = 0;
    while(i < 10 && counter <= temp.size() - 1) {
      vector<string>temp1 = temp.at(counter)->getActors(); 
      for(int j = 0; j < temp1.size(); j++) {
          if(temp1.at(j) == actor) {
              cout << counter+1 << ") " << temp.at(counter)->getTitle() << ": " << temp.at(counter)->getRating()  << endl << temp.at(counter)->getDescription() << endl << endl; 
              i++;
              break;
          } 
      }
      counter++;
    }
 }

 string FilterActor::getActor(){
  return this->actor; 
}

 void FilterGenre::filter(Factory* movie){
  string genre = this->genre;
  vector<Movie*> temp = movie->getMovieVec();
   int counter = 0; 
   
   for(unsigned int i = 0; i < temp.size() && counter < 10; ++i){
     Movie* current_movie = temp.at(i);
     vector<string> temp_genres = temp.at(i)->getGenres(); 
     for(unsigned int j = 0; j < temp_genres.size(); ++j){
       if(temp_genres.at(j) == genre){
         cout << counter+1 << ") " << current_movie->getTitle()<< ": " << current_movie->getRating()  << endl << current_movie->getDescription() << endl << endl; 
         counter++; 
         break; 
       }
     }
   }
 }

string FilterGenre::getGenre(){
  return this->genre; 
}

void FilterDirector::filter(Factory* movie){
  string director = this->director; 
  vector<Movie*> temp = movie->getMovieVec();
  int cntr = 0;
  for(int i = 0; i < temp.size() && cntr < 10; ++i){
    if(temp.at(i)->getDirector() == director){
      cout  << cntr+1 << ") " << temp.at(i)->getTitle() << ": " << temp.at(i)->getRating() << endl << temp.at(i)->getDescription() << endl << endl;
      cntr++;
    }
  }
}

string FilterDirector::getDirector(){
  return this->director; 
}
