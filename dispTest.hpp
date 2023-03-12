#ifndef _DISPLAY_TEST_HPP_
#define _DISPLAY_TEST_HPP_

#include "gtest/gtest.h"
#include "DisplayStrategy.hpp"
#include "Strategy.hpp"
#include "Movie.hpp"
#include "Factory.hpp"
#include "Media.hpp"
#include "Movie.hpp"
using namespace std;

TEST(DisplayTest, FilterTopTenRecentConstructor) {
  int test_year = 2012;
  FilterTopTenRecent *temp = new FilterTopTenRecent(test_year);
  int value_to_test = temp->getYear(); 
  EXPECT_EQ(value_to_test, test_year);  
}

TEST(DisplayTest, FilterActorConstructor) {
  string test_actor = "George Michael";
  FilterActor *temp = new FilterActor(test_actor);
  string value_to_test = temp->getActor(); 
  EXPECT_TRUE(test_actor == value_to_test); 
}

TEST(DisplayTest, FilterGenreConstructor) {
  string genre = "Comedy";
  FilterGenre *temp = new FilterGenre(genre);
  string value_to_test = temp->getGenre(); 
  EXPECT_TRUE(value_to_test == genre); 
}

TEST(DisplayTest, FilterDirectorConstructor) {
  string director = "Michael Bay";
  FilterDirector *temp = new FilterDirector(director);
  string value_to_test = temp->getDirector(); 
  EXPECT_TRUE(value_to_test==director); 
}



#endif