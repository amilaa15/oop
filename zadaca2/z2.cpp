#include <iostream>
#include <list>
#include <iterator>
#include <functional>

std::list<int> partition(std::list<int>::const_iterator pocetak, std::list<int>::const_iterator kraj, 
    std::function<bool(int)> predicate){
  std::list<int> rezultat;
  for(auto it=pocetak; it!=kraj; ++it){
    if(predicate(*it)){
      rezultat.push_front(*it);
    }
    else
      rezultat.push_back(*it);
  }
  return rezultat;
}

int main(void)
{
  std::list<int> nums{15,20,25,-10,-75,100,-255,430,200};
  auto rez=partition(nums.cbegin(), nums.cend(), [](int num){return !(num%2);});
  for(auto num : rez){
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}

