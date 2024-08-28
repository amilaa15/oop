#pragma once
#include <iostream>
#include <initializer_list>
#include <exception>
#include <algorithm>

template <typename T>
class MojNiz{
  private:
    unsigned long capacity_;
    T* arr_;
    unsigned long size_;
    

  public:
    MojNiz();
    template <typename U>
    MojNiz(const MojNiz<U>&);
    template <typename U>
    MojNiz& operator=(const MojNiz<U>&);
    MojNiz(MojNiz&&);
    MojNiz& operator=(MojNiz&&);
    ~MojNiz();
    MojNiz(std::initializer_list<T>);
    const T& operator[](int) const;
    T& operator[](int);
    MojNiz operator*(T) const;
    MojNiz operator*(T);
    template <typename U>
    MojNiz operator+(const MojNiz<U>&) const;
    template <typename U>
    MojNiz operator+(const MojNiz<U>&);
    MojNiz operator++(int);
    MojNiz& operator++();
    void push_back(T);
    void pop_back();
    int size() const;
    int capacity() const;
    const T* arr() const;
    const T& at(int) const;
    T& at(int);
    T& front();
    T& back();
};

template <typename T>
MojNiz<T>::MojNiz() : capacity_{1}, arr_{new T[capacity_]}, size_{0} {};

template <typename T>
template <typename U>
MojNiz<T>::MojNiz(const MojNiz<U>& o) : capacity_{o.capacity()}, arr_{new T[capacity_]}, size_{o.size()} {
  //std::copy(o.arr(), o.arr()+size_, arr_);
  for(auto i=0; i<size_; ++i){
    arr_[i]=static_cast<T>(o[i]);
  }
}

template <typename T>
template <typename U>
MojNiz<T>& MojNiz<T>::operator=(const MojNiz<U>& o){
  if(this!=static_cast<const void*>(&o)){
    delete[] arr_;
    capacity_=o.capacity();
    size_=o.size();
    arr_=new T[capacity_];
    //std::copy(o.arr(), o.arr()+size_, arr_);
    for(auto i=0; i<size_; ++i){
      arr_[i]=static_cast<T>(o[i]);
    }
  }
  return *this;
}

template <typename T>
MojNiz<T>::MojNiz(MojNiz<T>&& o){
  capacity_=o.capacity_;
  arr_=o.arr_;
  size_=o.size_;
  o.capacity_=0;
  o.arr_=nullptr;
  o.size_=0;
}

template <typename T>
MojNiz<T>& MojNiz<T>::operator=(MojNiz<T>&& o){
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

template <typename T>
MojNiz<T>::~MojNiz(){
  delete[] arr_;
  size_=0;
  capacity_=0;
}

template <typename T>
MojNiz<T>::MojNiz(std::initializer_list<T> l) : capacity_{size_}, arr_{new T[capacity_]}, size_{l.size()}{
  std::copy(l.begin(), l.end(), arr_);
}

template <typename T>
const T& MojNiz<T>::operator[](int a) const{
  return arr_[a];
}

template <typename T>
T& MojNiz<T>::operator[](int a){
  return arr_[a];
}

template <typename T>
MojNiz<T> MojNiz<T>::operator*(T a) const{
  MojNiz<T> noviNiz(size_);
  for(auto i=0; i<size_; ++i){
    noviNiz[i]=noviNiz[i]*a;
  }
  return noviNiz;
}

template <typename T>
MojNiz<T> MojNiz<T>::operator*(T a){
  MojNiz<T> noviNiz(size_);
  for(auto i=0; i<size_; ++i){
    noviNiz[i]=noviNiz[i]*a;
  }
  return noviNiz;
}

template <typename T>
template <typename U>
MojNiz<T> MojNiz<T>::operator+(const MojNiz<U>& o) const{
  MojNiz<T> noviNiz(*this);
  if(o.size()!=size_)
    throw std::invalid_argument("moraju imati isti size");
  for(auto i=0; i<o.size(); ++i){
    noviNiz[i]=static_cast<T>(arr_[i])+static_cast<T>(o[i]);
  }
  return noviNiz;
}

template <typename T>
template <typename U>
MojNiz<T> MojNiz<T>::operator+(const MojNiz<U>& o){
  MojNiz<T> noviNiz(*this);
  if(o.size()!=size_)
    throw std::invalid_argument("moraju imati isti size");
  for(auto i=0; i<o.size(); ++i){
    noviNiz[i]=static_cast<T>(arr_[i])+static_cast<T>(o[i]);
  }
  return noviNiz;
}

template <typename T>
MojNiz<T> MojNiz<T>::operator++(int){
  MojNiz<T> stariNiz(size_);
  for(auto i=0; i<size_; ++i){
    ++arr_[i];
  }
  return stariNiz;
}

template <typename T>
MojNiz<T>& MojNiz<T>::operator++(){
  for(auto i=0; i<size_; ++i){
    ++arr_[i];
  }
  return *this;
}

template <typename T>
void MojNiz<T>::push_back(T broj){
  if(size_==capacity_){
    capacity_=2*capacity_;
    auto temp=new T[capacity_];
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

template <typename T>
void MojNiz<T>::pop_back(){
  --size_;
}

template <typename T>
int MojNiz<T>::size() const{ 
  return size_;
}

template <typename T>
int MojNiz<T>::capacity() const{
  return capacity_;
}

template <typename T>
const T* MojNiz<T>::arr() const {
  return arr_;
}

template <typename T>
const T& MojNiz<T>::at(int index) const{
  if(index<0 || index>=size_)
    throw std::out_of_range("nevalidan index");
  return arr_[index];
}

template <typename T>
T& MojNiz<T>::at(int index) {
  if(index<0 || index>=size_)
    throw std::out_of_range("nevalidan index");
  return arr_[index];
}

template <typename T>
T& MojNiz<T>::front(){
  return arr_[0];
}

template <typename T>
T& MojNiz<T>::back(){
  return arr_[size_-1];
}

