#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <cmath>

int main(void)
{
  std::vector<int> vec;
  int broj;
  int sum=0;
  int proizvod=1;
  std::cout << "Unesi broj: " << std::endl;
  std::cin >> broj;

  while(broj!=0){
    vec.push_back(broj%10);
    broj/=10;
  }

  for(auto i=0; i<vec.size(); ++i){
    std::cout << vec[i];
  }

  std::cout << std::endl;


//  for(auto i=vec.size()-1; i>=0; --i){
//    std::cout << vec[i];
//  }

  std::sort(vec.begin(), vec.end());
  auto najmanja=vec.front();
  auto najveca=vec.back();

  for(auto i=0; i<vec.size(); ++i){
    sum+=vec[i];
  }


  for(auto i=0; i<vec.size(); ++i){
    proizvod*=vec[i];
  }

  std::cout << najmanja << std::endl;
  std::cout << najveca << std::endl;
  std::cout << sum << std::endl;
  std::cout << proizvod << std::endl;



  return 0;
}
