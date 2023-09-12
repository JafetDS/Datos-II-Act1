#include <gtest/gtest.h>
#include "Verification.cpp"
#include <string>
using namespace std;

// Demonstrate some basic assertions.
TEST(VerificationTest, verification) {

  char pruv = 'a';
  char *p = &pruv;
  // Expect equality.
  EXPECT_EQ(verification(3, &p), true)<<"Fallo la carga del arrchivo";
}

