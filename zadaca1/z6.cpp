#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


int errA=0, errB=0;

int stringuint(const std::string& v, int b){
  int k=0;
  try{
    k=stoi(v);
  }
  catch(std::invalid_argument& q){
    if(b==1)
      ++errB;
    else
      ++errA;
  }
  return k;
}



int main(void)
{
  
  std::string s1, s2;
  int prvibr, drugibr;
  char operacija;

for(; std::cin>>s1>>operacija>>s2;)
{
  prvibr=stringuint(s1, 0);
  drugibr=stringuint(s2,1);

  if(errA==1 && errB==1){
    errA=0;
    errB=0;
    std::cout << "Nevalidan unos: '" << s1  << "' i '" << s2 <<"' nisu brojevi." << std::endl;
    continue;
  }else if(errA==1) {
    errA=0;
    std::cout << "Nevalidan unos: " << "'" << s1 << "'" << "nije broj." << std::endl;
    continue;
  }else if(errB==1){
    errB=0;
    std::cout << "Nevalidan unos: '" << s2  << "' nisu brojevi." << std::endl;
    continue;
   }
    if (operacija== '+'){
          std::cout << prvibr+drugibr<< std::endl;
    } 
    else if(operacija=='-'){
      std::cout << prvibr-drugibr << std::endl;
    }
    else if (operacija=='*'){
      std::cout << prvibr*drugibr << std::endl;
    }
    else if (operacija=='/'){
      if (drugibr=='0')
      {
        std::cout << "Dijeljenje sa nulom je nedefinirana operacija." << std::endl;
      }
      else
      {
        std::cout << (1.0*prvibr)/drugibr << std::endl;
      }
    }
    else if(operacija=='%'){
      std::cout << prvibr%drugibr << std::endl;
    }
    else if(operacija=='^'){
      std::cout << std::pow(prvibr, drugibr) << std::endl;
    }
}


  return 0; 
}



















