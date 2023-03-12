#include "Movie.hpp"

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

string Movie::getTitle(){
  return this->title; 
}

vector<string> Movie::getActors() {
  return this->castList;
}
int Movie::getYear(){
  return this->prodYear;
}
int Movie::getType(){
  return 1; /*return 1 for Movie*/
}

double Movie::getRating(){
  return rating; 
}

void Movie::setTitle(string title_to_add){
  this->title = title_to_add; 
}
void Movie::addActors(vector<string> actors_to_add){
  castList = actors_to_add; 
} 

void Movie::addGenre(string genre_to_add){
  this->genres.push_back(genre_to_add);
}

void Movie::setGenres(vector<string> genres_to_add){
  this->genres = genres_to_add;
} 

void Movie::addDirector(string director){
  this->director = director; 
}  

void Movie::addProdYear(int prod_year){
  this->prodYear = prod_year; 
} 

void Movie::addDescription(string description){
  this->description = description; 
}  

void Movie::addRating(double rating){
  this->rating = rating; 
} 

string Movie::getDirector(){
  return this->director;
}

string Movie::getDescription(){
  return this->description;
}
vector<string> Movie::getGenres(){
  return this->genres; 
}

void Movie::print(){
    cout << endl << this->title << ": " << rating << endl <<  "Director: " << director << endl << "Genres: ";
    
    for(int i = 0; i < genres.size(); i++){
        cout << genres.at(i) << " ";
    }
    cout << endl << "Description: " << description << endl << "Cast: ";
    for(int j = 0; j < castList.size(); j++){
        cout << castList.at(j) << " ";
    }
    cout << endl << prodYear << endl;

    return;
}
