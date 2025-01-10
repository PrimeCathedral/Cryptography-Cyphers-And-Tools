//
// Created by Jimmy on 12/22/24.
//
#include "../Utilities/ModularArithmetic.hpp"
#include <gtest/gtest.h>

using cpp_int = boost::multiprecision::cpp_int;

TEST(TestModularExponentiation, PowersOfTwo) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // Power of 2
  ASSERT_EQ(ModularArithmetic.modularExponentiation(2, 10, 1024), 0);
}

TEST(TestModularExponentiation, ZeroToTheZero) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // 0^0 = 1 by programming convention
  EXPECT_EQ(ModularArithmetic.modularExponentiation(0, 0, 2), 1);
}

TEST(TestModularExponentiation, PowerIsZero) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // a^0
  ASSERT_EQ(ModularArithmetic.modularExponentiation(2, 0, 2), 1);
}

TEST(TestModularExponentiation, BaseIsZero) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // 0^a
  ASSERT_EQ(ModularArithmetic.modularExponentiation(0, 2, 2), 0);
}

TEST(TestModularExponentiation, BaseGreaterThanModulus) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // Base > Mod
  ASSERT_EQ(ModularArithmetic.modularExponentiation(17, 3, 5), 3);
}

TEST(TestModularExponentiation, PowerGreaterThanModulus) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // Power > Mod
  ASSERT_EQ(ModularArithmetic.modularExponentiation(3, 12, 7), 1);
}

TEST(TestModularExponentiation, LE20Digit) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // Large numbers
  cpp_int base{"123456789012345678901234567890123456789"};
  cpp_int power{"98765432109876543210987654321"};
  cpp_int modulus{"1000000007"};
  cpp_int result{"837711231"};
  ASSERT_EQ(ModularArithmetic.modularExponentiation(base, power, modulus),
            result);

  // TODO add more cases here. Test the limits on digit length
}

TEST(TestModularExponentiation, FiveHundredDigitBaseAndExponent) {
  Crypto::ModularArithmetic ModularArithmetic{};
  cpp_int base{
      "869686620366724081000608472872983739411368881958520521666061748309682394"
      "468432185176697230738560975444898122764971940991598044922761713961441418"
      "635666995644023572957464803410333153547961501346207555710813743360511966"
      "061082208240560309386900330712306347158488827042186602315548672186466616"
      "863347841989335065554875333065488751963721658103249619867912592447886196"
      "577723844331172875754552061648222393159488097499938498844878065342128806"
      "32907100008644808735503631550721979540282354265287063266531370638231"};
  cpp_int power{
      "162391487093569296500978596536345876841743799194252591801473157098210164"
      "146950316723217034306703047627177075139671739379653565811087432871859425"
      "395884393910566731534008453794719581241006416937990158649739006201909328"
      "417650171714350999557475114918319338220533413537893389319106086468210247"
      "205517709380259659200772230999203834417061644728529230007891338714990569"
      "333787241023170710585519844383459323604011222620008871507799429832108671"
      "39271987447556414720608291802483053210027281312128641210286405704066"};
  cpp_int modulus{
      "462567718062290590610719764009575956736052022994017267242205938939857700"
      "977343742099606005214022899217935079856284164164321143630995428578934247"
      "698652340585218538185741256903085185053691735998197368115110605012998226"
      "052392281128268795431344250996440606510499847178681148610363340302241413"
      "356337303320"};
  cpp_int result{"2717503944012861280963526545598569303217938943085505984912166"
                 "0004157508589491447940847198345031558285217799054920339719162"
                 "6371896383982530159279085077555597682204906124923340720297631"
                 "3408311872442852964351822293965170779182150644066525477884944"
                 "9661531628126824080223174182212959356294578580275761641"};
  EXPECT_EQ(ModularArithmetic.modularExponentiation(base, power, modulus),
            result);
}

TEST(TestModularExponentiation, ModulusIsOne) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // Small modulus (anything modulo 1 is 0)
  ASSERT_EQ(ModularArithmetic.modularExponentiation(5, 10, 1), 0);
}

TEST(TestModularExponentiation, PowerIsOne) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // Power = 1
  ASSERT_EQ(ModularArithmetic.modularExponentiation(45, 1, 7), 45 % 7);
}

// Modular inverse: https://www.dcode.fr/modular-inverse

TEST(TestModularMultiplicativeInverse, ModularInverseExists) {
  Crypto::ModularArithmetic ModularArithmetic{};
  EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(3, 7), 5);
}

TEST(TestModularMultiplicativeInverse, ModularInverseDoesNotExist) {
  Crypto::ModularArithmetic ModularArithmetic{};
  EXPECT_THROW(ModularArithmetic.modularMultiplicativeInverse(4, 8),
               std::runtime_error);
}

TEST(TestModularMultiplicativeInverse, LE20Digit) {
  Crypto::ModularArithmetic ModularArithmetic{};
  cpp_int a{cpp_int("12345678901234567890")};
  cpp_int mod{cpp_int("98765432109876543211")};
  EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(a, mod),
            cpp_int("94316753668893093070")); // Precomputed result
}

TEST(TestModularMultiplicativeInverse, NegativeBase) {
  Crypto::ModularArithmetic ModularArithmetic{};

  EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(-5, 7), 3);
  // TODO add better testcases. Code handles this by swapping symbols
}

TEST(TestModularMultiplicativeInverse, BaseIsOne) {
  Crypto::ModularArithmetic ModularArithmetic{};

  EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(1, 13), 1);
}

TEST(TestModularMultiplicativeInverse, ModulusIsOne) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // Modular inverse does not exist when the modulus is 1
  EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(5, 1), 0);
}

TEST(TestModularMultiplicativeInverse, NotCoprime) {
  Crypto::ModularArithmetic ModularArithmetic{};

  // GCD is not 1
  EXPECT_THROW(ModularArithmetic.modularMultiplicativeInverse(12, 15),
               std::runtime_error);
}

// Extended Euclidean Algorithm: https://www.dcode.fr/gcd

TEST(TestExtendedGCD, BaseCase) {
  cpp_int x, y;
  cpp_int base = 10, modulus = 0;
  cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

  EXPECT_EQ(gcd, 10); // GCD should be 10
  EXPECT_EQ(x, 1);    // x should be 1
  EXPECT_EQ(y, 0);    // y should be 0
}

TEST(TestExtendedGCD, CoprimeNumbers) {
  cpp_int x, y;
  cpp_int base = 17, modulus = 13;
  cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

  EXPECT_EQ(gcd, 1);
  EXPECT_EQ(17 * x + 13 * y, gcd);
}

TEST(TestExtendedGCD, NonCoprimeNumbers) {
  cpp_int x, y;
  cpp_int base = 12, modulus = 8;
  cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

  EXPECT_EQ(gcd, 4);
  EXPECT_EQ(12 * x + 8 * y, gcd);
}

TEST(TestExtendedGCD, NegativeBase) {
  cpp_int x, y;
  cpp_int base = -3, modulus = 7;
  cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

  EXPECT_EQ(gcd, 1);
  EXPECT_EQ(-3 * x + 7 * y, gcd);
}

TEST(TestExtendedGCD, LE20Digit) {

  cpp_int x, y;
  cpp_int base{"12345678901234567890"};
  cpp_int modulus{"9876543210987654321"};
  cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

  EXPECT_EQ(gcd, 90000000009);
  EXPECT_EQ(base * x + modulus * y, gcd); // Verify the linear combination
}

// Main entry point for the test runner
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}