#pragma once
#include <iostream>
#include <initializer_list>
#include <exception>
#include <functional>

class MojNizInt{
  private:
    int* arr_;
    unsigned long size_;

  public:
    MojNizInt();
    MojNizInt(const MojNizInt&);
    MojNizInt& operator=(const MojNizInt&);
    MojNizInt(MojNizInt&&);
    MojNizInt& operator=(MojNizInt&&);
    ~MojNizInt();
    MojNizInt(std::initializer_list<int>);
    const int& operator[](int) const;
    int& operator[](int);
    MojNizInt operator*(int) const;
    MojNizInt operator*(int);
    MojNizInt operator+(const MojNizInt&) const;
    MojNizInt operator+(const MojNizInt&);
    MojNizInt operator++(int);
    MojNizInt& operator++();
    void push_back(int);
    int size() const;
    const int& at(int) const;
    int& at(int);
};

MojNizInt::MojNizInt() : arr_{nullptr}, size_{0} {};

MojNizInt::MojNizInt(const MojNizInt& o) : arr_{new int[o.size_]}, size_{o.size_} {
  std::copy(o.arr_, o.arr_+o.size_, arr_);
}

MojNizInt& MojNizInt::operator=(const MojNizInt& o){
  if(this!=&o){
    delete[] arr_;
    size_=o.size_;
    arr_=new int[size_];
    std::copy(o.arr_, o.arr_+size_, arr_);
  }
  return *this;
}

MojNizInt::MojNizInt(MojNizInt&& o){
  arr_=o.arr_;
  size_=o.size_;
  o.arr_=nullptr;
  o.size_=0;
}

MojNizInt& MojNizInt::operator=(MojNizInt&& o){
  if(this!=&o){
    delete[] arr_;
    size_=o.size_;
    arr_=o.arr_;
    o.size_=0;
    o.arr_=nullptr;
  }
  return *this;
}

MojNizInt::~MojNizInt(){
  delete[] arr_;
  size_=0;
}

MojNizInt::MojNizInt(std::initializer_list<int> l) : arr_{new int[l.size()]}, size_{l.size()}{
  std::copy(l.begin(), l.end(), arr_);
}

const int& MojNizInt::operator[](int a) const{
  return arr_[a];
}

int& MojNizInt::operator[](int a){
  return arr_[a];
}

MojNizInt MojNizInt::operator*(int a) const{
  MojNizInt noviNiz(*this);
  for(auto i=0; i<size_; ++i){
    noviNiz[i]=noviNiz[i]*a;
  }
  return noviNiz;
}

MojNizInt MojNizInt::operator*(int a){
  MojNizInt noviNiz(*this);
  for(auto i=0; i<size_; ++i){
    noviNiz[i]=noviNiz[i]*a;
  }
  return noviNiz;
}

MojNizInt MojNizInt::operator+(const MojNizInt& o) const{
  MojNizInt noviNiz(*this);
  if(o.size_!=noviNiz.size_)
    throw std::invalid_argument("moraju imati isti size");
  for(auto i=0; i<o.size_; ++i){
    noviNiz[i]+=o[i];
  }
  return noviNiz;
}

MojNizInt MojNizInt::operator+(const MojNizInt& o){
  MojNizInt noviNiz(*this);
  if(o.size_!=noviNiz.size_)
    throw std::invalid_argument("moraju imati isti size");
  for(auto i=0; i<o.size_; ++i){
    noviNiz[i]+=o[i];
  }
  return noviNiz;
}

MojNizInt MojNizInt::operator++(int){
  MojNizInt stariNiz(*this);
  for(auto i=0; i<size_; ++i){
    ++arr_[i];
  }
  return stariNiz;
}

MojNizInt& MojNizInt::operator++(){
  for(auto i=0; i<size_; ++i){
    ++arr_[i];
  }
  return *this;
}

void MojNizInt::push_back(int broj){
  int* noviArr=new int[size_+1];
  std::copy(arr_, arr_+size_, noviArr);
  noviArr[size_]=broj;
  delete[] arr_;
  arr_=noviArr;
  size_++;
}

int MojNizInt::size() const{ 
  return size_;
}

const int& MojNizInt::at(int index) const{
  if(index<0 || index>=size_)
    throw std::out_of_range("nevalidan index");
  return arr_[index];
}

int& MojNizInt::at(int index) {
  if(index<0 || index>=size_)
    throw std::out_of_range("nevalidan index");
  return arr_[index];
}

  





 


