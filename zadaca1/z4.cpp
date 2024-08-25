#include <iostream>
#include <vector>


int hamming(const std::string& a, const std::string& b){    
  int ham=0;
  if(a.size()!=b.size()){
    std::cout << "Rijeci nisu iste duzine! " << std::endl;
    return -1;
  }
  
  for(auto i=0; i<a.size(); ++i){
    if (a[i]!=b[i]){
      ++ham;
    }
  }
  return ham;
}


int main(void)
{
  std::string prva;
  std::string druga;
  std::cout << "Unesite dvije rijeci: " << std::endl;
  std::cin >> prva;
  std::cin >> druga;
  int ham=hamming(prva, druga);
  std::cout << ham << std::endl;
  return 0;
}
