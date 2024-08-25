#include <iostream>
#include "stud.hpp"
#include "find.cpp"

Student& Student::promijeniBrojIndeksa(){
  std::string noviIndeks;
  std::cout << "Unesi novi broj indeksa: ";
  std::cin >> noviIndeks;
  brojIndeksa=noviIndeks;
  return *this;
}

Student& Student::promijeniIme(){
  std::string novoIme;
  std::cout << "Unesi novo ime: ";
  std::getline(std::cin, novoIme);
  ime=novoIme;
  return *this;
}

Student& Student::promijeniPrezime(){
  std::string novoPrezime;
  std::cout << "Unesi novo prezime: ";
  std::getline(std::cin, novoPrezime);
  prezime=novoPrezime;
  return *this;
}

Student& Student::promijeniGrad(){
  std::string noviGrad;
  std::cout << "Unesi novi grad: ";
  std::getline(std::cin, noviGrad);
  grad=noviGrad;
  return *this;
}

Student& Student::dodajOcjenu(std::list<Predmet>::const_iterator predmetIt){
  auto traziOcjenu=findy::findif(ocjene.begin(), ocjene.end(),
      [predmetIt](OcjenaIzPredmeta o){
        if(o.predmet==predmetIt) return true;
        else return false;
        });
  if(traziOcjenu!=ocjene.end())
    std::cout << "Ocjena je vec unesena." << std::endl;
  else{
    int ocjena=0;
    std::cout << "Unesi ocjenu za predmet " << predmetIt->naziv << ": ";
    std::cin >> ocjena;
    while(ocjena<5 || ocjena>10){
      std::cout << "Nevalidna ocjena." << std::endl;
      std::cout << "Unesi ocjenu za predmet " << predmetIt->naziv << ": ";
      std::cin >> ocjena;
    }
    OcjenaIzPredmeta ocj;
    ocj.ocjena=ocjena;
    ocj.predmet=predmetIt;
    ocjene.push_back(ocj);
  }
  return *this;
}

Student& Student::izbrisiOcjene(){
  ocjene.clear();
  return *this;
}


   













