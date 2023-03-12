#ifndef __MOVIE_HPP__
#define __MOVIE_HPP__

#include "Media.hpp"
#include <string>
#include <vector>

using namespace std; 

class Movie : public Media {
  private:
    vector<string> castList;
    string director; 
    string description;
    int prodYear; 
    double rating;

  public: 
    
    Movie() : Media(){}
    Movie(string title, vector<string>genres) : Media(title, genres){}
  
   
    
    /*helper functions:*/ 
    void setTitle(string title_to_add); 
    void addActors(vector<string> actors_to_add); 
    void addGenre(string genre_to_add); 
    void setGenres(vector<string> genres_to_add);
    void addDirector(string director);  
    void addProdYear(int prod_year); 
    void addDescription(string description);  
    void addRating(double rating); 
    
    void print();

     /*getter functions */
    double getRating();
    vector<string> getActors();
    int getType();
    int getYear(); 
    string getDescription();
    string getDirector();
     /*virtual functions to implement:*/
    string getTitle(); 
    vector<string> getGenres(); 
};

#endif




