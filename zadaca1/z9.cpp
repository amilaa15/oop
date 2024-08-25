#include <iostream>
#include <vector>

std::string najduzarijec(const std::vector<std::string>& vec){
  std::string najduza=vec[0];
  for(auto i=1; i<vec.size(); ++i){
    if(vec[i].size()>najduza.size()){
      najduza=vec[i];
    }
  }
  return najduza;
}

int brojKaraktera(const std::vector<std::string>& vec){
  int broj=0;
  for(auto i=0; i<vec.size(); ++i){
    broj+=vec[i].size();
  }
  return broj;
}



int main(void)
{
  std::vector<std::string> lista;
  std::string rijec;
  std::cout << "Unesi rijec: ";
  while (std::cin>>rijec){
    lista.push_back(rijec);
    std::cout << "Unesi rijec: ";
  }

  std::cout << std::endl;

  std::cout << "================================================" << std::endl;
  std::cout << "Lista rijeci" << std::endl;
  for(auto i=0; i<lista.size(); ++i){
    std::cout << lista[i] << " ";
  }

  int brojKar=brojKaraktera(lista);
  std::cout << "\n Ukupan broj karaktera: " << brojKar << std::endl;
  std::cout << "================================================" << std::endl;

  std::string najRijec=najduzarijec(lista);
  std::string plusevi(najRijec.size()+4, '+');
  std::string prazno(najRijec.size()+2, ' ');
  std::string prazno1(1, ' ');
  std::string plusic(1, '+');

  std::cout << "Najduza rijec" << std::endl;
  std::cout << plusevi << std::endl;
  std::cout << plusic+prazno+plusic << std::endl;
  std::cout << plusic+prazno1+najRijec+prazno1+plusic << std::endl;
  std::cout << plusic+prazno+plusic << std::endl;
  std::cout << plusevi << std::endl;
  
  return 0;
}

