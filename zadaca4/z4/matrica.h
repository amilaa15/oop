#pragma once
#include <iostream>
#include <initializer_list>
#include <exception>

template <typename T>
class Matrica{
  private:
    size_t m_;
    size_t n_;
    T* arr_;

  public:
    Matrica();
    Matrica(size_t, size_t);
    Matrica(const Matrica&);
    Matrica& operator=(const Matrica&);
    Matrica(Matrica&&);
  Matrica& operator=(Matrica&&);
    ~Matrica();
    Matrica(std::initializer_list<T>);
    T& operator()(size_t, size_t); //dodjeljivanje
    T operator()(size_t, size_t) const; //citanje
    Matrica operator+(const Matrica&) const;
    Matrica operator-(const Matrica&) const;
    Matrica& operator+=(const Matrica&);
    Matrica& operator-=(const Matrica&);
    Matrica operator*(T) const;
    Matrica& operator*=(T);
    Matrica operator/(T) const;
    Matrica& operator/=(T);
    int size() const;
    size_t getM() const;
    size_t getN() const;
    //friend std::ostream& operator<<(std::ostream&, const Matrica&);
};

template <typename T>
Matrica<T>::Matrica() : m_{0}, n_{0}, arr_{nullptr} {}

template <typename T>
Matrica<T>::Matrica(size_t m, size_t n) : m_{m}, n_{n}, arr_{new T[m_*n_]} {}

template <typename T>
Matrica<T>::Matrica(const Matrica& o) : m_{o.m_}, n_{o.n_}, arr_{new T[m_*n_]} {
  std::copy(o.arr_, o.arr_+o.m_*o.n_, arr_);
}

template <typename T>
Matrica<T>& Matrica<T>::operator=(const Matrica& o){
  if(this!=&o){
    delete[] arr_;
    m_=o.m_;
    n_=o.n_;
    arr_=new T[m_*n_];
  }
  return *this;
}

template <typename T>
Matrica<T>::Matrica(Matrica&& o) : m_{o.m_}, n_{n_}, arr_{new T[m_*n_]}{
  o.m_=0;
  o.n_=0;
  o.arr_=nullptr;
}

template <typename T>
Matrica<T>& Matrica<T>::operator=(Matrica&& o){
  if(this!=&o){
    delete[] arr_;
    m_=o.m_;
    n_=o.n_;
    arr_=o.arr_;
    o.m_=0;
    o.n_=0;
    o.arr_=nullptr;
  }
  return *this;
}

template <typename T>
Matrica<T>::~Matrica(){
  delete[] arr_;
  m_=0;
  n_=0;
}

template <typename T>
Matrica<T>::Matrica(std::initializer_list<T> l) //: m_{*l.begin()}, n_{*(l.begin()+1)},
  //arr_{new T[m_*n_]}{
{
    if((l.size()-2)>(m_*n_))
      throw std::domain_error("broj elemenata veci od dimenzija marice");
    auto it=l.begin();
    size_t m=*it++;
    size_t n=*it++;
    m_=m;
    n_=n;
    arr_=new T[m*n];

    std::copy(it, l.end(), arr_);
  }

template <typename T>
T& Matrica<T>::operator()(size_t i, size_t j){
  return arr_[i*m_+j];
}

template <typename T>
T Matrica<T>::operator()(size_t i, size_t j) const{
  return arr_[i*m_+j];
}

template <typename T>
Matrica<T> Matrica<T>::operator+(const Matrica<T>& o) const{
  if(m_!=o.m_ || n_!=o.n_)
    throw std::domain_error("Moraju biti iste dimenzije matrica");
  Matrica<T> novaMatrica(*this);
  for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      novaMatrica(i,j)+=o(i,j);
    }
  }
  return novaMatrica;
}

template <typename T>
Matrica<T> Matrica<T>::operator-(const Matrica<T>& o) const{
  if(m_!=o.m_ || n_!=o.n_)
    throw std::domain_error("Moraju biti iste dimenzije matrica");
  Matrica<T> novaMatrica(*this);
  for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      novaMatrica(i,j)-=o(i,j);
    }
  }
  return novaMatrica;
}

template <typename T>
Matrica<T>& Matrica<T>::operator+=(const Matrica<T>& o) {
  if(m_!=o.m_ || n_!=o.n_)
    throw std::domain_error("Moraju biti iste dimenzije matrica");
   for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      (*this)(i,j)+=o(i,j);
    }
  }
  return *this;
}

template <typename T>
Matrica<T>& Matrica<T>::operator-=(const Matrica<T>& o) {
  if(m_!=o.m_ || n_!=o.n_)
    throw std::domain_error("Moraju biti iste dimenzije matrica");
   for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      (*this)(i,j)-=o(i,j);
    }
  }
  return *this;
}

template <typename T>
Matrica<T> Matrica<T>::operator*(T a) const{
  Matrica<T> novaMatrica(*this);
   for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      novaMatrica(i,j)*=a;
    }
  }
  return novaMatrica;
}

template <typename T>
Matrica<T>& Matrica<T>::operator*=(T a) {
   for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      (*this)(i,j)*=a;
    }
  }
  return *this;
}

template <typename T>
Matrica<T> Matrica<T>::operator/(T a) const{
  Matrica<T> novaMatrica(*this);
   for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      novaMatrica(i,j)/=a;
    }
  }
  return novaMatrica;
}

template <typename T>
Matrica<T>& Matrica<T>::operator/=(T a) {
   for(auto i=0; i<m_; ++i){
    for(auto j=0; j<n_; ++j){
      (*this)(i,j)/=a;
    }
  }
  return *this;
}

template <typename T>
int Matrica<T>::size() const{
  return m_*n_;
}

template <typename T>
size_t Matrica<T>::getM() const{
  return m_;
}

template <typename T>
size_t Matrica<T>::getN() const{
  return n_;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrica<T>& matrica){
  for(auto i=0; i<matrica.getM(); ++i){
    for(auto j=0; j<matrica.getN(); ++j){
      os << matrica(i,j) << " ";
    }
    os << '\n';
  }
  return os;
}


















