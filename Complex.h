#pragma once
#include <iostream>
using namespace std;

class TComplex
{
public:
  TComplex();
  TComplex(float _re, float _im);
  TComplex(TComplex &z);

  float GetIm() const;
  float GetRe() const;
  float GetAbs() const;
  float GetArg() const;
  void SetIm(float im);
  void SetRe(float re);
 
  void Update();
  void PrintTrig();
  TComplex Pow(float p);
  TComplex operator +(const TComplex& z) const; 
  TComplex operator -(const TComplex& z) const;
  TComplex operator +=(const TComplex& z);
  TComplex operator -=(const TComplex& z);
  TComplex operator *(const TComplex& z) const;
  TComplex operator /(const TComplex& z) const;
  TComplex operator =(const TComplex& z);
  bool operator ==(const TComplex& z) const;
  friend istream& operator>>(istream& istr, TComplex& z);
  friend ostream& operator << (ostream& str, const TComplex& z);
protected:
  float Im;
  float Re;
  float abs;
  float arg;
};