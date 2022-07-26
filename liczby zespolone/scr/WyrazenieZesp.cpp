#include "WyrazenieZesp.hh"

using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Wyswietl(WyrazenieZesp  WyrZ) //funkcja wyswietlajaca pytanie z wyrazeniem zespolonym
{
    char znak;
    switch (WyrZ.Op)
    {
    case 0:
        znak = '+';
        break;
    case 1:
        znak = '-';
        break;
    case 2:
        znak = '*';
        break;
    case 3:
        znak = '/';
        break;
    }
cout << "Podaj wynik operacji: " << "(" << WyrZ.Arg1 << ") " << znak << " (" << WyrZ.Arg2 << ") "<< "=" << endl;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ) // funkcja obliczajaca wartosc wyrazenia zalezenie do operatora
{
    LZespolona Wynik;
    switch (WyrZ.Op)
    {
    case 0:
        Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;
        case 1:
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;
    case 2:
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;
    case 3:
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }
    return Wynik;
}