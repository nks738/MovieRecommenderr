#include <iostream>

#include "Movie.hpp"
#include "Media.hpp"
#include "Category.hpp"
#include "Factory.hpp"
#include "DisplayStrategy.hpp"
#include <vector>
#include <map>
#include <string>
using namespace std; 
class Movie; 
/*function signatures*/

void menu(Factory*);
void sortMovies(vector<Movie*> &vec);
int partition(vector<Movie*> &values, int left, int right);
void quicksort(vector<Movie*> &values, int left, int right);
void recMovie(vector<Movie*> values, string movie_name, map<string, Movie*> movMap);


int main() {
  
  /*Create factory object and parse data*/  
  Factory* movieParse = new Factory();
  movieParse->parseMovieData();

  /*sorting movies by score*/
  vector<Movie*> temp = movieParse->getMovieVec();
  sortMovies(temp);
  movieParse->setMovieVec(temp);
  
  menu(movieParse);
  
  
  return 0; 
  
}

void menu(Factory* movie) {
    int choice;
     
  do{
      cout << "Please enter your choice: " << endl << endl;
      cout << "Print by Score - 1" << endl;
      cout << "Print by Actor - 2" << endl;
      cout << "Print by Genre - 3" << endl;
      cout << "Recommend Movie - 4" << endl;
      cout << "Print Most Recent - 5" << endl;
      cout << "Print by Director - 6" << endl; 
      cout << "Quit - 9" << endl;
      
      cin >> choice;

      if(choice == 1) {
          movie->setFilterFunction(new FilterTopTen());
          movie->filter();
      }

      else if (choice == 2) {
          string actor;
          cout << "Enter actor/actress name." << endl;
          cin.ignore();
          getline(cin, actor);
          movie->setFilterFunction(new FilterActor(actor));
          movie->filter();
      }
      else if (choice == 5){
        int year;
        cout << "Enter year of production." << endl;
        cin >> year;
        movie->setFilterFunction(new FilterTopTenRecent(year));
        movie->filter();
      }
      
      else if(choice == 3) {
          string genre;
          cout << "Please enter the genre." << endl;
          cin >> genre;
          movie->setFilterFunction(new FilterGenre(genre));
          movie->filter();
      }
      else if(choice == 6) {
          string director;
          cout << "Please enter the director." << endl;
          cin.ignore();
          getline(cin, director);
          movie->setFilterFunction(new FilterDirector(director));
          movie->filter();
      }

      else if(choice ==4){
        string movName;
        cout << "What movies do you like?\nWe will find some others you might like!" << endl;
        cin.ignore();
        getline(cin, movName);

        /*check if movie is in dataset*/
       if(!(movie->movieExists(movName))){
          cout << "Sorry, we do not have any records of this movie." << endl << endl;
       }
       else{
          
          recMovie(movie->getMovieVec(), movName, movie->getMovieMap());
          
       }
        
      }
      else{
        if (choice !=9){
        cout << "Invalid Input: Choose 1-5" << endl << endl;
        }
      }
  }while(choice != 9);
}

       
void sortMovies(vector<Movie*> &vec){
  quicksort(vec, 0, vec.size()-1);
}

int partition(vector<Movie*> &values, int left, int right) {
    double pivotIndex = left + (right - left) / 2;
    double pivotValue = values.at(pivotIndex)->getRating();
    double i = left, j = right;
    Movie* temp;
    while(i <= j) {
        while(values.at(i)->getRating() > pivotValue) {
            i++;
        }
        while(values.at(j)->getRating() < pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<Movie*> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}


void recMovie(vector<Movie*> values, string movie_name, map<string, Movie*> movMap){
 
  Movie* origMovie =  movMap.find(movie_name)->second;

  /*-------------------------------*/
  /*Start checking for similarities*/
  /*-------------------------------*/
  
  
  int movieCounter = 0;
  int whileCounter = 0;
  vector<string> origMovieActors = origMovie->getActors();
  vector<string> origMovieGenres = origMovie->getGenres();
  cout << endl<< "We think you would enjoy:" << endl << endl;
  
  for(unsigned int i = 0; i < values.size() && movieCounter < 3; ++i){
      int similarity_count = 0; 
    if(movie_name == values.at(i)->getTitle()){
      i++;
    }
    vector<string> temp = values.at(i)->getActors();
    for(int j = 0; j < origMovieActors.size(); j++){
      for(int k = 0; k < temp.size(); k++ ) {
          if(origMovieActors.at(j) == temp.at(k)){
                similarity_count++; 
          }
      }
    }

    if(values.at(i)->getDirector() == origMovie->getDirector()){
      similarity_count++;
    }

     vector<string> temp2 = values.at(i)->getGenres();
    for(int j = 0; j < origMovieGenres.size(); j++){
      for(int k = 0; k < temp2.size(); k++ ) {
          if(origMovieGenres.at(j) == temp2.at(k)){
                similarity_count++; 
          }
      }
    }

    if(similarity_count >= 3) {
      values.at(i)->print();
      cout << endl;
      movieCounter++;
    }
  
  }
  
  
}
