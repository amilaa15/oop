#include <iostream>
#include <list>
#include <functional>

std::list<int> map_funk(std::list<int>& lista, std::function<int(int)> transf){
  std::list<int> nova_lista;
  for(auto el : lista){
    nova_lista.push_back(transf(el));
  }
  return nova_lista;
}


int main(void)
{
  std::list<int> l={7,2,-4,5,0,6,3};
  auto lamb=[](int n){return n*2+1;};
  auto rez=map_funk(l, lamb);
  for(auto& el : rez){
    std::cout << el << " ";
  }
  std::cout << std::endl;
  return 0;
}
