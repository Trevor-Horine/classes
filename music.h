#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "dm.h"

using namespace std;

//music class
class music: public dm{
public:
music (char* newTitle, char* newArtist, int newYear, int newType, float newDur, char* newPub);
//virtual methods
  virtual char* getArtist();
  virtual float getDur();
  virtual char* getPub();
  //destructor
  ~music();
 private:
  //varables
  char* artist;
  char* pub;
  float dur;
};
#endif
