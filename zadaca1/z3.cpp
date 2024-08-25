#include <iostream>
#include <algorithm>
#include <math.h>
int main(void)
{
  int str1, str2, str3;
  int cijelibr;
  int i, j, k; //brojaci za for petlju
  std::cout << "Unesi tri cijela broja: " << std::endl;
  std::cout << "Prvi broj: ";
  std::cin >> str1;
  std::cout << "Drugi broj: ";
  std::cin >> str2;
  std::cout << "Treci broj: ";
  std::cin >> str3;


  if((str1=sqrt(str2*str2+str3*str3)) || (str2=sqrt(str1*str1+str3*str3)) || (str3=sqrt(str2*str2+str1*str1)))
    std::cout << "Brojevi su stranice pravouglog trougla." << std::endl;
  else
    std::cout << "Brojevi nisu stranice pravouglog trougla." << std::endl;

  std::cout << "Unesite cijeli broj: ";
  std::cin >> cijelibr;

  for(i=1; i<=cijelibr; ++i){
    for(j=i+1; j<=cijelibr; ++j){
      for(k=j+1; k<=cijelibr; ++k){
        if((i*i+j*j==k*k) /*|| (j*j=i*i+k*k) || (k*k=i*i+j*j)*/)
          std::cout << "(" << i << ", " << j << ", " << k << ")" << std::endl;
      }
    }
  }


  return 0;
}
