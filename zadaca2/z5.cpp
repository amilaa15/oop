#include <iostream>
#include <list>
#include <functional>

std::list<int> filter(std::list<int>& lista, std::function<bool(int)> predicate){
  std::list<int> nova_lista;
  for(auto& el : lista){
    if(predicate(el))
      nova_lista.push_back(el);
  }
  return nova_lista;
}

int main(void)
{
  std::list<int> l={1,9,8,4,11,0,2,6,15,3,10};
  auto pred=[](int n){return n%2==0;};
  std::list<int> rez=filter(l, pred);
  for(auto& el : rez)
    std::cout << el << " ";
  std::cout  << std::endl;
  return 0;
}


