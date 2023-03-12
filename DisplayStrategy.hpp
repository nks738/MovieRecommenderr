#ifndef _DISPLAY_SRATEGIES_HPP_
#define _DISPLAY_SRATEGIES_HPP_

#include "Category.hpp"
#include "Movie.hpp"
#include "Strategy.hpp"
#include "Factory.hpp"
#include "Media.hpp"

#include <string>

using namespace std; 

class Category; 

class FilterTopTen : public Strategy {
  public:
    FilterTopTen():Strategy(){};
    void filter(Factory* movie);
};

class FilterTopTenRecent : public Strategy{
  private:
    int year;

  public:
    FilterTopTenRecent():Strategy(){};
    FilterTopTenRecent(int year) {this->year = year;}
    int getYear(); 
    void filter(Factory* movie);
};

class FilterActor : public Strategy{
  private:
    string actor;

  public:
    FilterActor():Strategy(){};
    FilterActor(string actor) {this->actor= actor;}
    string getActor(); 
    void filter(Factory* movie);
};

class FilterGenre : public Strategy{
  private:
    string genre;

  public:
    FilterGenre():Strategy(){};
    FilterGenre(string genre) {this->genre = genre;}
    string getGenre();
    void filter(Factory* movie);
};

class FilterDirector : public Strategy {
  private:
    string director;

  public:
    FilterDirector():Strategy(){};
    FilterDirector(string director) {this->director = director;} 
    string getDirector(); 
    void filter(Factory* movie);
};

#endif