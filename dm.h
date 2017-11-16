#ifndef DM_H
#define DM_H
#include <iostream>
#include <cstring>

using namespace std;

class dm{
 public:
  dm(char* newTitle, int year, int newType);
  char* getTitle();
  int getYear();
  int getType();
  virtual char* getDir();
  virtual float getDur();
  virtual float getRat();
  virtual char* getPub();
  virtual char* getArtist();
  ~dm();
 private:
  char* title;
  int year;
  int type;
};
#endif
