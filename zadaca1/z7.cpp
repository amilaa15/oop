#include <iostream>
#include <vector>
#include <algorithm>


std::string najduzarijec(const std::vector<std::string> & vec){
  std::string najduza=vec[0];
  for(auto i=1; i<vec.size(); ++i){
    if(vec[i].size()>najduza.size()){
      najduza=vec[i];
    }
  }
  return najduza;
}




int main(void)
{
  std::vector<std::string> vec;
  std::string rijec;
  std::cout << "Unesi rijec: ";
  while(std::cin>>rijec){
    vec.push_back(rijec);
    std::cout << "Unesi rijec: ";
  }
  
  std::cout << std::endl;

  std::sort(vec.begin(), vec.end());

  std::string najduza=najduzarijec(vec);

  std::string plusevi(najduza.size()+4, '+');
  std::string plusic(1, '+');
  std::string prazno1(1, ' ');
  std::string prazno(najduza.size()+2, ' ');

  std::cout << plusevi<< std::endl;
  std::cout << plusic+prazno+plusic << std::endl;

  for(auto i=0; i<vec.size(); ++i){
    std::cout << plusic+prazno1+vec[i]+std::string(najduza.size()-vec[i].size()+1, ' ')+plusic << std::endl;
  }

  std::cout << plusic+prazno+plusic << std::endl;
  std::cout << plusevi<< std::endl;
    



  return 0;
}
