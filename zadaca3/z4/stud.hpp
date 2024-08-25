#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

struct Predmet{
  std::string naziv;
  std::string odsijek;
};

struct OcjenaIzPredmeta{
  int ocjena;
  std::list<Predmet>::const_iterator predmet;
};

struct Student{
  std::string brojIndeksa;
  std::string ime;
  std::string prezime;
  std::string grad;
  std::vector<OcjenaIzPredmeta> ocjene;

  Student& promijeniBrojIndeksa();
  Student& promijeniIme();
  Student& promijeniPrezime();
  Student& promijeniGrad();
  Student& dodajOcjenu(std::list<Predmet>::const_iterator);
  Student& izbrisiOcjene();
};





