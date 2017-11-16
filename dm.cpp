#include <iostream>
#include <cstring>
#include "dm.h"
#include "movie.h"
#include "vg.h"
#include "music.h"

using namespace std;

//dm method
dm::dm(char* newTitle, int newYear, int newType){
  title = newTitle;
  year = newYear;
  type = newType;
}
//to get title
char* dm::getTitle(){
  return title;
}
//to get year
int dm::getYear(){
  return year;
}
//to get type
int dm::getType(){
  return type;
}
//to get director
char* dm::getDir(){
  return NULL;
}
//to get duration
float dm::getDur(){
  return NULL;
}
//to get rating
float dm::getRat(){
  return NULL;
}
//to get publisher
char* dm::getPub(){
  return NULL;
}
//to get artist
char* dm::getArtist(){
  return NULL;
}
//destructor
dm::~dm(){
  delete title;
}
