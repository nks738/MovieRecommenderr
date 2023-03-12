#ifndef __MEDIA_HPP__
#define __MEDIA_HPP__

#include <string>
#include <vector>

using namespace std; 

class Media {
  protected: 
    string title; 
    vector<string> genres; 

  public: 
    Media() : title(""), genres() {};
    Media(string title, vector<string>genres) : title(title), genres(genres){};
    virtual string getTitle() = 0; 
    virtual void setTitle(string title_to_add) = 0; 
    virtual int getType() = 0; /*1 for movie, 2 for category*/


};

#endif