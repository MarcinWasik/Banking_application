#include <gtest/gtest.h>
#include "Narzedzia.hpp"

struct NarzedziaTests : public ::testing::Test {
  Narzedzia narzedzia;
};

TEST_F(NarzedziaTests, sprawdzeniePoprawnosciWalidacjiPeselu) {
  std::string peselOk1("16292365763");
  std::string peselOk2("61033077085");
  std::string peselOk3("22012629718");
  std::string peselNok1("1031090375");
  std::string peselNok2("98101abc877");
  std::string peselNok3("12345678912");
  // THEN
  ASSERT_EQ(true, narzedzia.czyPeselJestPrawidlowy(peselOk1));
  ASSERT_EQ(true, narzedzia.czyPeselJestPrawidlowy(peselOk2));
  ASSERT_EQ(true, narzedzia.czyPeselJestPrawidlowy(peselOk3));
  ASSERT_EQ(false, narzedzia.czyPeselJestPrawidlowy(peselNok1));
  ASSERT_EQ(false, narzedzia.czyPeselJestPrawidlowy(peselNok2));
  ASSERT_EQ(false, narzedzia.czyPeselJestPrawidlowy(peselNok3));
}

TEST_F(NarzedziaTests, sprawdzeniePoprawnosciZamianyGroszowek) {
  long long int liczbaGroszy1 = 16292365763;
  long long int liczbaGroszy2 = 12345;
  long long int liczbaGroszy3 = 4563456847;

  long int oczekiwanaLiczbaZlotowek1 = 162923657;
  int oczekiwanaLiczbaGroszy1 = 63;

  long int oczekiwanaLiczbaZlotowek2 = 123;
  int oczekiwanaLiczbaGroszy2 = 45;

  long int oczekiwanaLiczbaZlotowek3 = 45634568;
  int oczekiwanaLiczbaGroszy3 = 47;

  std::pair<long int, int> paraWynik1 =
      narzedzia.zamianaGroszyNaZlotowkiIGrosze(liczbaGroszy1);
  std::pair<long int, int> paraWynik2 =
      narzedzia.zamianaGroszyNaZlotowkiIGrosze(liczbaGroszy2);
  std::pair<long int, int> paraWynik3 =
      narzedzia.zamianaGroszyNaZlotowkiIGrosze(liczbaGroszy3);

  // THEN
  ASSERT_EQ(oczekiwanaLiczbaZlotowek1, paraWynik1.first);
  ASSERT_EQ(oczekiwanaLiczbaGroszy1, paraWynik1.second);

  ASSERT_EQ(oczekiwanaLiczbaZlotowek2, paraWynik2.first);
  ASSERT_EQ(oczekiwanaLiczbaGroszy2, paraWynik2.second);

  ASSERT_EQ(oczekiwanaLiczbaZlotowek3, paraWynik3.first);
  ASSERT_EQ(oczekiwanaLiczbaGroszy3, paraWynik3.second);
}

TEST_F(NarzedziaTests, sprawdzeniePoprawnosciRegex) {
  ASSERT_EQ(true, narzedzia.czyWyrazenieZgodneZRegexem("ABCD", "[A-Z]{4}"));
  ASSERT_EQ(true,
            narzedzia.czyWyrazenieZgodneZRegexem("12345678901", "[0-9]{11}"));
  ASSERT_EQ(false, narzedzia.czyWyrazenieZgodneZRegexem("aBCD", "[A-Z]{4}"));
  ASSERT_EQ(false,
            narzedzia.czyWyrazenieZgodneZRegexem("123456789a1", "[0-9]{11}"));
}

TEST_F(NarzedziaTests, zamianaBialychZnakowNaPodloge) {
  std::string test1("za narty");
  std::string test2("Ala ma kota, a moze nie");
  std::string test3(" w");
  narzedzia.zamianaBialychZnakowNaPodloge(test1);
  narzedzia.zamianaBialychZnakowNaPodloge(test2);
  narzedzia.zamianaBialychZnakowNaPodloge(test3);
  ASSERT_EQ("za_narty", test1);
  ASSERT_EQ("Ala_ma_kota,_a_moze_nie", test2);
  ASSERT_EQ("_w", test3);
}
