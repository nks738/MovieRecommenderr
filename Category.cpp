#include "Category.hpp"
#include "Movie.hpp"

#include <vector>
#include <string>

using namespace std; 

string Category::getTitle(){
  return this->title; 
}

vector<string> Category::getGenres(){
  return this->genres; 
}

int Category::getType(){
  return 2; 
}

void Category::addMovie(Movie* movie_to_add){
  this->movie_List.push_back(movie_to_add);
}

void Category::addCategory(Category* category_to_add){
  this->category_List.push_back(category_to_add);
}

void Category::setTitle(string title_to_add){
  this->title =  title_to_add; 
}