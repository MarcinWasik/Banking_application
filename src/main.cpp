#include <iostream>
#include "Bank.hpp"
#include "Narzedzia.hpp"
#include "Osoba.hpp"
#include "Transakcje.hpp"

using namespace std;

int main() {
  std::string plikKlienci = "/home/marcin/Pulpit/Bank/klienci.txt";
  std::string plikKasjerzy = "/home/marcin/Pulpit/Bank/kasjerzy.txt";
  std::string plikZarzadcy = "/home/marcin/Pulpit/Bank/zarzadcy.txt";
  Bank ing(plikKlienci, plikKasjerzy, plikZarzadcy);
  ing.operacjeUzytkownika();
}
