#include <iostream>
#include "stud.hpp"
#include "find.cpp"
#include <vector>
#include <list>
#include <functional>


void printStudentMenu() {
  std::cout << "1. Mijenjanje broja indeksa studenta" << std::endl;
  std::cout << "2. Mijenjanje imena studenta" << std::endl;
  std::cout << "3. Mijenjanje prezimena studenta" << std::endl;
  std::cout << "4. Mijenjanje grada studenta" << std::endl;
  std::cout << "5. Dodavanje novih ocjena studentu" << std::endl;
  std::cout << "6. Brisanje svih ocjena studenta" << std::endl;
  std::cout << "7. Izlaz" << std::endl;
}

void printMainMenu() {
  std::cout << "1. Dodavanje predmeta" << std::endl;
  std::cout << "2. Dodavanje studenta" << std::endl;
  std::cout << "3. Uredivanje studenta" << std::endl;
  std::cout << "4. Ispis studenata za predmet" << std::endl;
  std::cout << "5. Izlaz" << std::endl;
}


