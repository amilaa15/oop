#include <iostream>
#include <iterator>
#include <list>


std::list<int> parni_neparni(std::list<int>::iterator pocetak, std::list<int>::iterator kraj){
  std::list<int> rezultat;
  for(auto it=pocetak; it!=kraj; ++it){
    if((*it)%2==0){
      rezultat.push_front(*it);
    }
    else{
      rezultat.push_back(*it);
    }
  }
  return rezultat;
}

int main(void)
{
  std::list<int> brojevi={1,2,3,4,5,6,7,8,9};
  std::list<int> rezultat=parni_neparni(begin(brojevi), end(brojevi));
  for(auto& br : rezultat)
    std::cout << br << " ";
  std::cout << std::endl;
  
  return 0;
}
  
