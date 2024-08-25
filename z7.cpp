#include <iostream>
#include <list>
#include <functional>

int reduce(std::list<int>& lista, std::function<int(int, int)> funk, int pocetna=0){
  for(auto& i : lista){
    pocetna=funk(pocetna,i);
  }
  return pocetna;
}

int main(void)
{
  std::list<int> lista={11,4,5,12,6,8,9};
  auto lam=[](int a, int b){return a+b+1;};
  int rez=reduce(lista, lam, -12);
  std::cout << rez << std::endl;
  return 0;
}
