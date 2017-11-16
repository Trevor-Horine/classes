#include<iostream>
#include<cstring>
#include"music.h"

using namespace std;

//music metiod
music::music(char* newTitle, char* newArtist, int newYear, int newType, float newDur, char* newPub):dm(newTitle, newYear, newType){
  artist = newArtist;
  dur = newDur;
  pub = newPub;
}
//to get artist
char* music::getArtist(){
  return artist;
}
//to get duration
float music::getDur(){
  return dur;
}
//to get publisher
char* music::getPub(){
  return pub;
}
//destructor
music::~music(){
  delete artist;
  delete pub;
}
