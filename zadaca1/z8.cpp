#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main(void)
{
  srand(time(NULL));

  int ukupnoKuglica;
  int izvuceneKuglice;
  std::vector<int> kuglice;

  std::cout << "Unesite ukupan broj kuglica: ";
  std::cin >> ukupnoKuglica;

  std::cout << "Unesite broj izucenih kuglica: ";
  std::cin >> izvuceneKuglice;

  for(auto i=0; i<izvuceneKuglice; ++i){
    int izvucenibr=rand()%ukupnoKuglica+1;
    kuglice.push_back(izvucenibr);
  }

  std::vector<int> sortiraneKuglice(kuglice);

  std::sort(sortiraneKuglice.begin(), sortiraneKuglice.end());

  std::cout << "\n Izvuceno \t Sortirano " << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
  for(auto i=0; i<izvuceneKuglice; ++i){
    std::cout << kuglice[i] << "\t\t" << sortiraneKuglice[i] << std::endl;
  }

  std::vector<int> parne;
  std::vector<int> neparne;
  for(int kuglica : sortiraneKuglice){
    if(kuglica%2==0){
      parne.push_back(kuglica);
    }
    else{
      neparne.push_back(kuglica);
    }
  }

  std::cout << std::endl;

  parne.insert(parne.end(), neparne.begin(), neparne.end());
  
  for(int k : parne){
    std::cout << k << std::endl;
  }

  return 0;
}

