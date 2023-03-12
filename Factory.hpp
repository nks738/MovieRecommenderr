#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_

#include <string>
#include <vector>
#include <map>
#include "Movie.hpp"
#include "Strategy.hpp"

using namespace std; 

class Strategy; 

class Factory {
  private: 
    map<string, Movie*> movieMap;
    
    Strategy* filter_functions; 

  public: 
  vector<Movie*> movieVec;
    void setFilterFunction(Strategy* filterType){ filter_functions = filterType;}
    void parseMovieData(); 
    void parseVideoData();
    vector<Movie*> getMovieVec();
    void setMovieVec(vector<Movie*> movVec);
    void filter();
    bool movieExists(string movName);
    map<string, Movie*> getMovieMap();
    
    
};
#endif
