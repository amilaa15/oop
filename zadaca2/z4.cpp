#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using Funkcije=std::vector<std::function<bool(int)>>;

void default_of_not(std::vector<int>& vec, Funkcije funk, int def=-1){

  for(auto& br : vec){
    for(auto& f : funk){
      if(!(f(br)))
        br=def;
    }
  }
}

int main(void)
{
  std::vector<int> vec={1,2,3,4,5,6,7,8,9};
  Funkcije funk={[](int a){return a>0;}, [](int a){return a%2;}};
  default_of_not(vec, funk);
  for(auto& br:vec)
    std::cout << br << " ";
  std::cout << std::endl;

  return 0;
}
