#include <iostream>
#include<cstring>
#include"vg.h"

using namespace std;

//video game method
vg::vg(char* newTitle, int newYear, int newType, char* newPub, float newRat):dm(newTitle, newYear, newType){
  pub = newPub;
  rat = newRat;
}
//to get publisher
char* vg::getPub(){
  return pub;
}
//to get rating
float vg::getRat(){
  return rat;
}
//destructor
vg::~vg(){
  delete pub;
}
