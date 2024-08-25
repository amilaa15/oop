#include <iostream>
#include <list>
#include <functional>
#include <iterator>

std::list<int> partition(std::list<int>::iterator pocetak, std::list<int>::iterator kraj,
    std::function<bool(int)> predicate){
  std::list<int> rezultat;
  for(auto it=pocetak; it!=kraj; ++it){
    try{
      if(predicate(*it))
        rezultat.push_back(*it);
      else
        rezultat.push_front(*it);
    }
    catch(int iznimka){
      rezultat.clear();
      for(auto it=pocetak; it!=kraj; ++it){
        rezultat.push_back(*it);
      }
    }
  }
  return rezultat;
}

int main(void)
{
  std::list<int> lista={15,20,25,-10,-75,100,-255,430,200};
  auto lambda=[](int num){if(num>400) throw 5; return num>0;};
  auto rez=partition(begin(lista), end(lista), lambda);
  for(auto& el : rez)
    std::cout << el << " ";
  std::cout << std::endl;

  return 0;
}

