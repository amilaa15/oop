#pragma once
#include <iostream>
#include <functional>

namespace my{

  template <typename It, typename P>
  void sort(It p, It k, P f){
    for(auto i=p; i!=k; ++i){
      for(auto j=i; j!=k; ++j){
        if(f(*j, *i))
          std::swap(*i, *j);
      }
    }
  }


  template <typename It>
  void sort(It p, It k){
    for(auto i=p; i!=k; ++i){
      for(auto j=i; j!=k; ++j){
        if(*j>*i)
          std::swap(*i, *j);
      }
    }
  }


}

//v= 356 83 2 67 854
//std::sort (v.begin(), v.end()) ---> 2 67 83 356 854
//std::sort (v.begin(), v.end(),
//    [](int a, int b){return a>b;}) ---> 854 356 83 67 2
//
//
//int a;
//a=7
