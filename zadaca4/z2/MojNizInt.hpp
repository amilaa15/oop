#pragma once
#include <iostream>
#include <initializer_list>
#include <exception>
#include <functional>

class MojNizInt{
  private:
    unsigned long capacity_;
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
    void pop_back();
    int size() const;
    int capacity();
    const int& at(int) const;
    int& at(int);
    int& front();
    int& back();
};

MojNizInt::MojNizInt() : capacity_{1}, arr_{new int[capacity_]}, size_{0} {};

MojNizInt::MojNizInt(const MojNizInt& o) : capacity_{o.capacity_}, arr_{new int[capacity_]}, size_{o.size_} {
  std::copy(o.arr_, o.arr_+o.size_, arr_);
}

MojNizInt& MojNizInt::operator=(const MojNizInt& o){
  if(this!=&o){
    delete[] arr_;
    capacity_=o.capacity_;
    size_=o.size_;
    arr_=new int[capacity_];
    std::copy(o.arr_, o.arr_+size_, arr_);
  }
  return *this;
}

MojNizInt::MojNizInt(MojNizInt&& o){
  capacity_=o.capacity_;
  arr_=o.arr_;
  size_=o.size_;
  o.capacity_=0;
  o.arr_=nullptr;
  o.size_=0;
}

MojNizInt& MojNizInt::operator=(MojNizInt&& o){
  if(this!=&o){
    delete[] arr_;
    capacity_=o.capacity_;
    size_=o.size_;
    arr_=o.arr_;
    o.capacity_=0;
    o.size_=0;
    o.arr_=nullptr;
  }
  return *this;
}

MojNizInt::~MojNizInt(){
  delete[] arr_;
  size_=0;
  capacity_=0;
}

MojNizInt::MojNizInt(std::initializer_list<int> l) : capacity_{l.size()}, arr_{new int[capacity_]}, size_{l.size()}{
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
  if(size_==capacity_){
    capacity_=2*capacity_;
    auto temp=new int[capacity_];
    for(auto i=0; i<size_; ++i){
      temp[i]=arr_[i];
    }
    delete[] arr_;
    arr_=temp;
    //temp=nullptr;
  }
  arr_[size_]=broj;
  ++size_;
}

void MojNizInt::pop_back(){
  --size_;
}


int MojNizInt::size() const{ 
  return size_;
}

int MojNizInt::capacity(){
  return capacity_;
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

int& MojNizInt::front(){
  return arr_[0];
}

int& MojNizInt::back(){
  return arr_[size_-1];
}


  
