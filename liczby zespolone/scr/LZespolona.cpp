#include "LZespolona.hh"





/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2) // przeciezenie operatora dodawania dla liczby zespolonej
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2) //  przeciazenie operatora odejmowania dla liczby zespolonej
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2) //  przeciezenie operatora mnozenia dla liczby zespolonej
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.im * Skl2.re) + (Skl1.re * Skl2.im);
  return Wynik;
}

LZespolona  Sprzezenie (LZespolona  Skl1) // funkcja zwracajaca sprzezenie liczby zespolonej
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = - Skl1.im;
  return Wynik;
}
float Modulbezpierw (LZespolona Skl1) // funkcja obliczajaca modul liczby zespolonej bez pierwiastka
{
  float wynik;
  wynik = Skl1.re * Skl1.re + Skl1.im * Skl1.im;
  return wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2) // przeciazenie operatora dzielenia dla liczby zespolonej
{
  LZespolona  Wynik1,Wynik2, Sprz;
  float Mianownik;
  Mianownik = Modulbezpierw(Skl2);
  Sprz = Sprzezenie(Skl2);
  Wynik1 = Skl1 * Sprz;
  Wynik2.re = Wynik1.re / Mianownik;
  Wynik2.im = Wynik1.im / Mianownik;
  
  return Wynik2;
}

ostream & operator << (ostream & StrmWy, LZespolona Skl1) // przeciazenie operatora wypisania liczby zespolonej
{
  return StrmWy << Skl1.re << showpos << Skl1.im << noshowpos << "i";
}
istream & operator >> (istream & StrmWe, LZespolona& Skl1) // przeciazenie operatora wczytania liczby zespolonej
{
StrmWe.ignore();
StrmWe >> Skl1.re >> Skl1.im;
StrmWe.ignore();
StrmWe.ignore();
StrmWe.ignore();
return StrmWe;
}

bool operator == (LZespolona Skl1, LZespolona Skl2) // przeciazenie operatora porownania dla liczby zespolonej
{
  if((Skl1.re==Skl2.re)&&(Skl1.im==Skl2.im))
    return 1;
  else
    return 0;
  
}
bool operator != (LZespolona Skl1, LZespolona Skl2) // przeciazenie operatora nie rownownosci dla liczby zespolonej
{
  if((Skl1.re==Skl2.re)&&(Skl1.im==Skl2.im))
    return 0;
  else
    return 1;
  
}
