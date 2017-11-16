#ifndef VG_H
#define VG_H
#include <iostream>
#include <cstring>
#include "dm.h"

using namespace std;

//video game class
class vg: public dm{
 public:
  vg(char* newTitle, int newYear, int newType, char* newPub, float newRat);
  //virtual methods
  virtual char* getPub();
  virtual float getRat();
  //destructor
  ~vg();
 private:
  //varables
  char* pub;
  float rat;
};
#endif
