#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "dm.h"

using namespace std;

//movie class
class movie: public dm{
 public:
  movie(char* newTitle, int newYear, int newType, char* newDir, float newDur, float newRat);
  //vertual methods
  virtual char* getDir();
  virtual float getDur();
  virtual float getRat();
  //destructor
  ~movie();
 private:
  //varabels
  char* dir;
  float dur;
  float rat;
};
#endif
