#ifndef _BASE_CLASSES_TEST_HPP_
#define _BASE_CLASSES_TEST_HPP_

#include "gtest/gtest.h"
#include "Factory.hpp"
#include "Movie.hpp"
#include "DisplayStrategy.hpp"
#include "Category.hpp"
#include "Media.hpp"
#include <vector>
#include <string>
using namespace std;

TEST(BaseClassTests, TestMovieConstructor){
  string title_temp = "The Bee Movie";
  vector<string> randomStrings = {"comedy", "horror", "action"};
  Movie* temp = new Movie(title_temp, randomStrings);
  EXPECT_TRUE(temp->getTitle() == title_temp); 
  EXPECT_TRUE(temp->getGenres() == randomStrings); 
}
TEST(BaseClassTests, TestMovieSetTitle){
  Movie* temp = new Movie(); 
  temp->setTitle("the Bees movie");
  EXPECT_TRUE(temp->getTitle() == "the Bees movie");
}
TEST(BaseClassTests, TestMovieAddActors){
  vector<string> randomStrings = {"john","bill","doe"};
  Movie* temp = new Movie(); 
  temp->addActors(randomStrings);
  EXPECT_TRUE(temp->getActors() == randomStrings);
  
}
TEST(BaseClassTests, TestMovieSetGenres){
  vector<string> randomStrings = {"comedy", "drama"};
  Movie* temp = new Movie(); 
  temp->setGenres(randomStrings);
  EXPECT_TRUE(temp->getGenres() == randomStrings);

  
}
TEST(BaseClassTests, TestMovieAddDirector){
  Movie* temp = new Movie(); 
  temp->addDirector("ronny"); 
  EXPECT_TRUE(temp->getDirector() == "ronny");
  
}
TEST(BaseClassTests, TestMovieAddProdYear){
  Movie* temp = new Movie(); 
  int num = 2020; 
  temp->addProdYear(num); 
  EXPECT_TRUE(temp->getYear() == 2020);
}
TEST(BaseClassTests, TestMovieaddDescription){
  Movie* temp = new Movie(); 
  string descrip = "blah blah blah blah radnom lots of tests"; 
  temp->addDescription(descrip);
  EXPECT_TRUE(temp->getDescription() == "blah blah blah blah radnom lots of tests");
  
}
TEST(BaseClassTests, TestMoviesAddRating){
   Movie* temp = new Movie();
   double score  = 5.5; 
   temp->addRating(score);
   EXPECT_EQ(temp->getRating(), 5.5); 
  
}



#endif