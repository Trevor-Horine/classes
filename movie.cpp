#include<iostream>
#include<cstring>
#include"movie.h"

using namespace std;

//movie method
movie::movie(char* newTitle, int newYear, int newType, char* newDir, float newDur, float newRat):dm(newTitle, newYear, newType){
  dir = newDir;
  dur = newDur;
  rat = newRat;
}
//to get director
char* movie::getDir(){
  return dir;
}
//to get duration
float movie::getDur(){
  return dur;
}
//to get rating
float movie::getRat(){
  return rat;
}
//destructor
movie::~movie(){
  delete dir;
}
