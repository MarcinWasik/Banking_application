#include <gtest/gtest.h>
#include "Bank.hpp"

struct BankTests : public ::testing::Test {
  std::string plikKlienci = "/home/marcin/Pulpit/Bank/tests/klienciTest.txt";
  std::string plikKasjerzy = "/home/marcin/Pulpit/Bank/tests/kasjerzyTest.txt";
  std::string plikZarzadcy = "/home/marcin/Pulpit/Bank/tests/zarzadcyTest.txt";
};

TEST_F(BankTests, wczytywanieZapisywanieTest) {
  Bank bank(plikKlienci, plikKasjerzy, plikZarzadcy);

  std::vector<Klient> klienci = bank.getKlienci();

  ASSERT_EQ("123", klienci[0].getPesel());
  ASSERT_EQ("Łukasz", klienci[0].getImie());
  ASSERT_EQ("Elo", klienci[0].getNazwisko());
  ASSERT_EQ("Wrocław", klienci[0].getAdres());
  ASSERT_EQ("login", klienci[0].getLogin());
  ASSERT_EQ("haslo", klienci[0].getHaslo());
  ASSERT_EQ(12, klienci[0].getNumerKonta());
  ASSERT_EQ(123, klienci[0].getStanKonta());

  ASSERT_EQ("222", klienci[1].getPesel());
  ASSERT_EQ("Mariola", klienci[1].getImie());
  ASSERT_EQ("Stan", klienci[1].getNazwisko());
  ASSERT_EQ("Lubin", klienci[1].getAdres());
  ASSERT_EQ("mariola", klienci[1].getLogin());
  ASSERT_EQ("haslo1", klienci[1].getHaslo());
  ASSERT_EQ(33, klienci[1].getNumerKonta());
  ASSERT_EQ(12312, klienci[1].getStanKonta());

  std::vector<Kasjer> kasjerzy = bank.getKasjerzy();
  ASSERT_EQ("456", kasjerzy[0].getPesel());
  ASSERT_EQ("Marek", kasjerzy[0].getImie());
  ASSERT_EQ("Boczek", kasjerzy[0].getNazwisko());
  ASSERT_EQ("Wroclaw", kasjerzy[0].getAdres());
  ASSERT_EQ("Login", kasjerzy[0].getLogin());
  ASSERT_EQ("Haslo", kasjerzy[0].getHaslo());
  ASSERT_EQ("321", kasjerzy[0].getIdKasjera());

  ASSERT_EQ("789", kasjerzy[1].getPesel());
  ASSERT_EQ("Beata", kasjerzy[1].getImie());
  ASSERT_EQ("Koza", kasjerzy[1].getNazwisko());
  ASSERT_EQ("Olesnica", kasjerzy[1].getAdres());
  ASSERT_EQ("mala", kasjerzy[1].getLogin());
  ASSERT_EQ("byk", kasjerzy[1].getHaslo());
  ASSERT_EQ("634", kasjerzy[1].getIdKasjera());

  std::vector<Zarzadca> zarzadcy = bank.getZarzadcy();
  ASSERT_EQ("951", zarzadcy[0].getPesel());
  ASSERT_EQ("Bartek", zarzadcy[0].getImie());
  ASSERT_EQ("Nowak", zarzadcy[0].getNazwisko());
  ASSERT_EQ("Nysa", zarzadcy[0].getAdres());
  ASSERT_EQ("login", zarzadcy[0].getLogin());
  ASSERT_EQ("haslo", zarzadcy[0].getHaslo());
  ASSERT_EQ("852", zarzadcy[0].getIdZarzadcy());

  ASSERT_EQ("753", zarzadcy[1].getPesel());
  ASSERT_EQ("Sylwia", zarzadcy[1].getImie());
  ASSERT_EQ("Nowa", zarzadcy[1].getNazwisko());
  ASSERT_EQ("Poznan", zarzadcy[1].getAdres());
  ASSERT_EQ("dom", zarzadcy[1].getLogin());
  ASSERT_EQ("tamara", zarzadcy[1].getHaslo());
  ASSERT_EQ("761", zarzadcy[1].getIdZarzadcy());
}

TEST_F(BankTests, czyIstniejeLogin) {
  Bank bank(plikKlienci, plikKasjerzy, plikZarzadcy);

  ASSERT_EQ(false, bank.czyIstniejeLogin("bleble"));
  ASSERT_EQ(false, bank.czyIstniejeLogin("test"));
  ASSERT_EQ(true, bank.czyIstniejeLogin("Login"));
  ASSERT_EQ(true, bank.czyIstniejeLogin("mariola"));
}

TEST_F(BankTests, czyHasloJestPoprawneDlaLoginu) {
  Bank bank(plikKlienci, plikKasjerzy, plikZarzadcy);

  ASSERT_EQ(false, bank.czyHasloJestPoprawneDlaLoginu("okno", "koza"));
  ASSERT_EQ(false, bank.czyHasloJestPoprawneDlaLoginu("lego", "klocki"));
  ASSERT_EQ(true, bank.czyHasloJestPoprawneDlaLoginu("login", "haslo"));
  ASSERT_EQ(true, bank.czyHasloJestPoprawneDlaLoginu("dom", "tamara"));
}

// t
