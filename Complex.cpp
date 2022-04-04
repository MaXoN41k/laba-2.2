#include "Complex.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

TComplex::TComplex()
{
  Re = 0.0;
  Im = 0.0;
  Update();
}

TComplex::TComplex(float _re, float _im)
{
  Re = _re;
  Im = _im;
  Update();
}

TComplex::TComplex(TComplex& z)
{
  Im = z.Im;
  Re = z.Re;
  Update();
}

float TComplex::GetIm() const
{
  return Im;
}

float TComplex::GetRe() const
{
  return Re;
}

float TComplex::GetAbs() const
{
  return abs;
}

float TComplex::GetArg() const
{
  return arg;
}

void TComplex::SetIm(float im)
{
  Im = im;
  Update();
}

void TComplex::SetRe(float re)
{
  Re = re;
  Update();
}

void TComplex::Update()
{
  abs = sqrt((Im * Im) + (Re * Re));
  if (Im>=0)
  {
    arg = acos(Re / abs);
  }
  else 
  {
    if (Re >= 0)
    {
      arg = 2 * M_PI + asin(Im / abs);
    }
    else
    {
      arg = acos(-Re / abs) + M_PI ;
    }
  }
}

void TComplex::PrintTrig()
{
  cout << "z=" << abs << "(cos(" << (arg/M_PI)*180 << ") + i*sin(" << (arg / M_PI) * 180 << ")" << endl;
}

TComplex TComplex::Pow(float p)
{
  abs = pow(abs, p);
  arg = p * arg;
  float tmp=arg/(2*M_PI);
  arg = arg - floor(tmp)*2*M_PI;
  Re = cos(arg) * abs;
  Im = sin(arg) * abs;
  return *this;
}

TComplex TComplex::operator+(const TComplex& z) const
{
  TComplex res;
  res.Im = Im + z.Im;
  res.Re = Re + z.Re;
  return res;
}

TComplex TComplex::operator-(const TComplex& z) const
{
  TComplex res;
  res.Im = Im - z.Im;
  res.Re = Re - z.Re;
  return res;
}

TComplex TComplex::operator+=(const TComplex& z)
{
  Im = Im + z.Im;
  Re = Re + z.Re;
  Update();
  return *this;
}

TComplex TComplex::operator-=(const TComplex& z)
{
  Im = Im - z.Im;
  Re = Re - z.Re;
  Update();
  return *this;
}

TComplex TComplex::operator*(const TComplex& z) const
{
  TComplex res;
  res.Re = Re * z.Re - Im * z.Im;
  res.Im = Re * z.Im + Im * z.Re;
  return res;
}

TComplex TComplex::operator/(const TComplex& z) const
{
  TComplex res;
  res.Re = ((Re * z.Re) + (Im * z.Im))/((z.Re * z.Re) + (z.Im * z.Im));
  res.Re = ((Im * z.Re) - (Re * z.Im)) / ((z.Re * z.Re) + (z.Im * z.Im));
  return res;
}

TComplex TComplex::operator=(const TComplex& z)
{
  Im = z.Im;
  Re = z.Re;
  Update();
  return *this;
}

bool TComplex::operator==(const TComplex& z) const
{
  return Im == z.Im && Re == z.Re;
}

ostream& operator << (ostream& str,const TComplex& z)
{
  str << "(Re=" << z.Re << " ";
  str << "Im=" << z.Im << " ";
  str << "Abs=" << z.abs << " ";
  str << "Arg=Rad:" << z.arg << " Deg:" << (z.arg/M_PI)*180 << ")";
  return str;
}


istream& operator>>(istream& istr, TComplex& z)
{
  istr >> z.Re;
  istr >> z.Im;
  z.Update();
  return istr;
}




