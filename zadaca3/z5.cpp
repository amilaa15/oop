#include <iostream>
#include <iterator>
#include <vector>
#include <list>

//123456 lista sa iteratorom It1
//123456 vektor sa iteratorom It2

template <typename It1, typename It2>
bool jednako(It1 begin1, It1 end1, It2 begin2){
  bool rez=true;
  while(begin1!=end1){
    if(*begin1!=*begin2){
      rez=false;
    }
    ++begin1;
    ++begin2;
  }
  return rez;
}

bool palindrom(const std::string& s){
  return jednako(s.begin(), s.end(), s.rbegin());
  // auto begin=s.begin();
  // auto end=s.end();
  // while(begin!=end){
  //   if(*begin==*end)
  //     return true;
  //   ++begin;
  //   --end;
  // }
  // return false;
}




int main(void)
{
  std::vector<int> vec={1,2,3,4,5};
  std::list<int> l={1,2,3,4,5};
  std::string s="anavolimilovana";
  bool rezpal=palindrom(s);
  if(rezpal==true)
    std::cout << "palindrom" << std::endl;
  else
    std::cout << "nije palindrom" << std::endl;


  bool rez=jednako(vec.begin(), vec.end(), l.begin());
  if(rez==true)
    std::cout << "iste su" << std::endl;
  else
    std::cout << "nisu iste" << std::endl;

  return 0;
}





