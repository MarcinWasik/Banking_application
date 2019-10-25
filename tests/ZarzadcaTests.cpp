#include <gtest/gtest.h>
#include "Klient.hpp"
#include "Zarzadca.hpp"

struct ZarzadcaTests : public ::testing::Test {
  Zarzadca zarzadca;
};

TEST_F(ZarzadcaTests, pobierzKwoteZaProwadzenieKonta) {
  std::vector<Klient> klienci;
  Klient a;
  a.setStanKonta(100);
  Klient b;
  b.setStanKonta(20);
  Klient c;
  c.setStanKonta(2345);
  Klient d;
  d.setStanKonta(-10);
  klienci.push_back(a);
  klienci.push_back(b);
  klienci.push_back(c);
  klienci.push_back(d);

  zarzadca.pobierzKwoteZaProwadzenieKonta(klienci, 20);
  ASSERT_EQ(80, klienci[0].getStanKonta());
  ASSERT_EQ(0, klienci[1].getStanKonta());
  ASSERT_EQ(2325, klienci[2].getStanKonta());
  ASSERT_EQ(-30, klienci[3].getStanKonta());
}
