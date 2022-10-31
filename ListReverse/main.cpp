#include <stdexcept>
#include <assert.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "list.h"
#include "student.h"
#include <vector>

int main(){
  CP::list<int> a;
  CP::list<int> b;
  std::vector<CP::list<int>> v;
  for(int i = 0; i < 5; i++){
    a.push_back(i);
    b.push_back(i+10);
  }
  v.push_back(a);
  v.push_back(b);
  CP::list<int> ans;
  for(int i = 0; i < v.size(); i++){
    
  }
}

