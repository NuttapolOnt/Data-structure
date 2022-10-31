#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
bool comp1(Song a, Song b){
  if(a.artist < b.artist){
    return false;
  }
  else if(a.artist == b.artist){
    if(a.title < b.title){
      return false;
    }
    else if(a.title == b.title){
      if(a.count < b.count){
        return false;
      }
      else{
        return true;
      }
    }
    else{
      return true;
    }
  }
  return true;
}

bool comp2(Song a, Song b){
  if(a.count < b.count){
    return true;
  }
  else if(a.count == b.count){
    if(a.artist < b.artist){
      return false;
    }
    else if(a.artist == b.artist){
      if(a.title < b.title){
        return false;
      }
      else{
        return true;
      }
    }
    else{
      return true;
    }
  }
  return false;
}
typedef bool(*myComp)(Song,Song);
CP::priority_queue<Song,myComp> pq1(comp1);
CP::priority_queue<Song,myComp> pq2(comp2);

#endif
