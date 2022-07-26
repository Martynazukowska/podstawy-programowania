#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
using namespace std;




int main(int argc, char **argv)
{



  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odp;
  int licznik=0;

   while(PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) // petla while pobierajaca kolejne pytania testu
   {
     Wyswietl(WyrZ_PytanieTestowe);    //funkcja wyswietlajaca pytanie
     cout << "Twoja odpowiedz: ";
     cin >> Odp; 

    while(cin.fail())   //petla sprawdzajaca poprawnosc zapisu liczby zespolonej
     {
       cin.clear();
       cout << "Blad liczby zespolonej - sprobuj ponownie" << endl;
       cout << "Twoja odpowiedz: " << endl;
       cin.ignore(10000,'\n');
       cin >> Odp;
     }

     if (Odp==Oblicz(WyrZ_PytanieTestowe)) //sprawdzenie poprawnosci odpowiedzi
     {
       cout << "Poprawna odpowiedz" << endl;
       licznik++;
     }
     
      if(Odp!=Oblicz(WyrZ_PytanieTestowe))     
     {
       cout << "Bledna odpowiedz" << endl;
       cout << "Poprawna odpowiedz:" << Oblicz(WyrZ_PytanieTestowe) << endl; //wypisanie poprawdnej odpowiedzi w przypadku podania zlego wyniku
     } 
   }

  
  cout << endl;
  cout << " Koniec testu" << endl;                                  // wypisanie wynikow koncowych
  cout << " Ilosc dobrych odpowiedzi: " << licznik << endl;
  cout << " Ilosc blednych odpowiedzi: " << 4 - licznik << endl;
  cout << " Wynik procentowy: " << licznik * 25 << "%" << endl;
  cout << endl;

}
