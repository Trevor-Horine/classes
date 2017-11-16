/* This is a media database for movies, music, and video games.
 *Author: Trevor Horine
 *November 11 2017
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "dm.h"
#include "movie.h"
#include "vg.h"
#include "music.h"

using namespace std;

void add(vector<dm*> &media);
void search(vector<dm*> &media);
void remove(vector<dm*> &media);

//main
int main(){
  char operation[10];
  bool working = true;
  //vector to store media
  vector<dm*> media;
  //allows to contine
  while(working == true){
    cout << "Do you want to Add, Search, Delete, or Quit?" << endl;
    cin >> operation;
    for(int i = 0; i < 11; i++){
      operation[i] = toupper(operation[i]);
    }
    //to add
    if(strcmp(operation, "ADD") == 0){
      add(media);
    }
    //to search
    else if(strcmp(operation, "SEARCH") == 0){
      search(media);
    }
    //to delete
    else if(strcmp(operation, "DELETE") == 0){
      remove(media);
    }
    //to quit
    else if(strcmp(operation, "QUIT") == 0){
      working = false;
    }
    else{
      cout << "Pick Add, Search, Delete, or Quit." << endl;
    }
  }
}
//adding to vector
void add(vector<dm*> & media){
  char ty[20];
  cout << "Are you adding a Movie, Music, Video Game?" << endl;
  cin.ignore();
  cin.getline(ty, 20);
  for(int i = 0; i < 20; i++){
    ty[i] = toupper(ty[i]);
  }
  //if movie
  if(strcmp(ty, "MOVIE") == 0){
    int type = 0;
    char* title =  new char[100];
    int year;
    char* dir = new char[100];
    float dur;
    float rat;
    cout << "what is the Title?" << endl;
    cin.getline(title,100);
    for(int i = 0; i < 20; i++){
      title[i] = toupper(title[i]);
    }
    cout << "What year was it published in?" << endl;
    cin >> year;
    cout << "Who is the Director?" <<endl;
    cin.ignore();
    cin.getline(dir, 100);
    for(int i = 0; i < 20; i++){
      dir[i] = toupper(dir[i]);
    }
    cout << "How long is it in minutes?" << endl;
    cin >> dur;
    cout << "what is it's rating out of 5?" << endl;
    cin >> rat;
    dm* m = new movie(title, year, type, dir, dur, rat);
    media.push_back(m);
    }
  //if video game
  else if(strcmp(ty, "VIDEO GAME") == 0){
    int type = 1;
    char* title =  new char[100];
    int year;
    char* pub = new char[100];
    float rat;
    cout << "what is the Title?" << endl;
    cin.getline(title,100);
    for(int i = 0; i < 20; i++){
      title[i] = toupper(title[i]);
    }
    cout << "What year was it published in?" << endl;
    cin >> year;
    cout << "Who published it?" <<endl;
    cin.ignore();
    cin.getline(pub, 100);
    for(int i = 0; i < 20; i++){
      pub[i] = toupper(pub[i]);
    }
    cout << "what is it's rating out of 5?" << endl;
    cin >> rat;
    dm* m = new vg(title, year, type, pub, rat);
    media.push_back(m);
    }
  //if music
  else if(strcmp(ty, "MUSIC") == 0){
    int type = 2;
    char* title =  new char[100];
    char* artist = new char[100];
    int year;
    float dur;
    char* pub = new char[100];
    cout << "what is the Title?" << endl;
    cin.getline(title,100);
    for(int i = 0; i < 20; i++){
      title[i] = toupper(title[i]);
    }
    cout << "Who is the artist?" <<endl;
    cin.getline(artist,100);
    for(int i = 0; i < 20; i++){
      artist[i] = toupper(artist[i]);
    }
    cout << "What year was it published in?" << endl;
    cin >> year;
    cout << "How long is it in minutes?" << endl;
    cin >> dur;
    cout << "Who published it?" <<endl;
    cin.ignore();
    cin.getline(pub, 100);
    for(int i = 0; i < 20; i++){
      pub[i] = toupper(pub[i]);
    }
    dm* m = new music(title, artist, year, type, dur, pub);
    media.push_back(m);
  }
  else{
    cout << "Pick Movie, Music, or Video game" << endl;
  }
}
//to search
void search(vector<dm*> &media){
  char search[20];
  char objective[100];
  int object;
  cout << "Would you like to search by title or by year?" << endl;
  cin >> search;
  for(int i = 0; i < 20; i++){
    search[i] = toupper(search[i]);
  }
  //search by title
  if(strcmp(search,"TITLE") == 0){
    cout << "What is the title?" << endl;
    cin.ignore();
    cin.getline(objective, 100);
    for(int i = 0; i < 20; i++){
      objective[i] = toupper(objective[i]);
    }
    for(vector<dm*>::iterator it = media.begin(); it != media.end(); it++){
      if(strcmp(objective, (*it)-> getTitle()) == 0){
	//print movies
	if((*it)-> getType() == 0){
	  cout << endl;
	  cout << "Movie" << endl;
	  cout << "Title: " << (*it)-> getTitle() << endl;
	  cout << "Published in: " << (*it)-> getYear() << endl;
	  cout << "Director: " << (*it)-> getDir() << endl;
	  cout << "Duration: " << (*it)-> getDur() << " Minutes" << endl;
	  cout << "Rating out of 5: " << (*it)-> getRat() << endl;
	  cout << endl;
	}
	//print video game
	if((*it)-> getType() == 1){
	  cout << endl;
	  cout << "Video Game" << endl;
	  cout << "Title: " << (*it)-> getTitle() << endl;
	  cout << "Published in: " << (*it)-> getYear() << endl;
	  cout << "Publisher: " << (*it)-> getPub() << endl;
	  cout << "Rating out of 5: " << (*it)-> getRat() << endl;
	  cout << endl;
	}
	//print music
	if((*it)-> getType() == 2){
	  cout << endl;
	  cout << "Music" << endl;
	  cout << "Title: " << (*it)-> getTitle() << endl;
	  cout << "Artist: " << (*it)-> getArtist() << endl;
	  cout << "Published in: " << (*it)-> getYear() << endl;
	  cout << "Duration: " << (*it)-> getDur() << " Minutes" << endl;
	  cout << "Publisher: " << (*it)-> getPub() << endl;
	  cout << endl;
	}
      }
    }
  }
  //search by year
  if(strcmp(search,"YEAR") == 0){
     cout << "What is the year?" << endl;
     cin >> object;
     for(vector<dm*>::iterator it = media.begin(); it != media.end(); it++){
       if(object == (*it)-> getYear()){
	 //print movie
	 if((*it)-> getType() == 0){
	   cout << endl;
	   cout << "Movie" << endl;
	   cout << "Title: " << (*it)-> getTitle() << endl;
	   cout << "Published in: " << (*it)-> getYear() << endl;
	   cout << "Director: " << (*it)-> getDir() << endl;
	   cout << "Duration: " << (*it)-> getDur() << " Minutes" << endl;
	   cout << "Rating out of 5: " << (*it)-> getRat() << endl;
	   cout << endl;
	 }
	 //print video game
	 if((*it)-> getType() == 1){
	   cout << endl;
	   cout << "Video Game" << endl;
	   cout << "Title: " << (*it)-> getTitle() << endl;
	   cout << "Published in: " << (*it)-> getYear() << endl;
	   cout << "Publisher: " << (*it)-> getPub() << endl;
	   cout << "Rating out of 5: " << (*it)-> getRat() << endl;
	   cout << endl;
	 }
	 //print music
	 if((*it)-> getType() == 2){
	   cout << endl;
	   cout << "MUsic" << endl;
	   cout << "Title: " << (*it)-> getTitle() << endl;
	   cout << "Artist: " << (*it)-> getArtist() << endl;
	   cout << "Published in: " << (*it)-> getYear() << endl;
	   cout << "Duration: " << (*it)-> getDur() << " Minutes" << endl;
	   cout << "Publisher: " << (*it)-> getPub() << endl;
	   cout << endl;
	 }
       }
     }
  }
}
//to delete
void remove(vector<dm*> &media){
  char search[20];
  char objective[100];
  int object;
  int times = 0;
  cout << "Would you like to remove a title or a year?" << endl;
  cin >> search;
  for(int i = 0; i < 20; i++){
    search[i] = toupper(search[i]);
  }
  //delete by title
  if(strcmp(search,"TITLE") == 0){
    cout << "What is the title?" << endl;
    cin.ignore();
    cin.getline(objective, 100);
    for(int i = 0; i < 20; i++){
      objective[i] = toupper(objective[i]);
    }
    for(vector<dm*>::iterator it = media.begin(); it != media.end(); it++){
      if(strcmp(objective, (*it)-> getTitle()) == 0){
     	times++;
      }
    }
    while(times > 0){
      for(vector<dm*>::iterator it = media.begin(); it != media.end(); it++){
     	if(strcmp(objective, (*it)-> getTitle()) == 0){
     	  if((*it)-> getType() == 0){
     	    delete static_cast<movie*>(*it);
     	  }
     	  if((*it)-> getType() == 1){
     	    delete static_cast<vg*>(*it);
     	  }
     	  if((*it)-> getType() == 2){
     	    delete static_cast<music*>(*it);
     	  }
     	  media.erase(it);
	  times = times - 1;
	  if (times == 0){
	    break;
	  }
	}
      }
    }
  }
  //delete by year
  if(strcmp(search,"YEAR") == 0){
    cout << "What is the year?" << endl;
    cin >> object;
    for(vector<dm*>::iterator it = media.begin(); it != media.end(); it++){
      if(object == (*it)-> getYear()){
	times++;
      }
    }
    while(times > 0){
      for(vector<dm*>::iterator it = media.begin(); it != media.end(); it++){
	if(object == (*it)-> getYear()){
	  if((*it)-> getType() == 0){
	    delete static_cast<movie*>(*it);
	  }
	  if((*it)-> getType() == 1){
	    delete static_cast<vg*>(*it);
	  }
	  if((*it)-> getType() == 2){
	    delete static_cast<music*>(*it);
	  }
	  media.erase(it);
	  times = times - 1;
	  if (times == 0){
	    break;
	  }
	}
      }
    }
  }
}
# classes
