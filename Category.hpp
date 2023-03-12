#ifndef __CATEGORY_HPP__
#define __CATEGORY_HPP__

#include <vector>
#include <string>

#include "Movie.hpp"
#include "Media.hpp"

using namespace std; 

class Category : public Media {
  private: 
    vector<Movie *> movie_List; 
    vector<Category *> category_List; 

  public: 
    Category() : Media() {};
    Category(string title, vector<string> genres): Media(title, genres){}; 
    void setTitle(string title_rwto_add); 

    /*virtual functions to implement:*/
    string getTitle(); 
    vector<string> getGenres();
    int getType(); 

    /*functions unique to Category class*/
    void addMovie(Movie* movie_to_add);
    void addCategory(Category* category_to_add); 
};
#endif