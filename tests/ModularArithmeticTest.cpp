//
// Created by Jimmy on 12/22/24.
//
#include <gtest/gtest.h>
#include "../Utilities/ModularArithmetic.h"

TEST(TestModularExponentiation, PowersOfTwo) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Power of 2
    ASSERT_EQ(ModularArithmetic.modularExponentiation(2, 10, 1024), 0);
}

TEST(TestModularExponentiation, ZeroToTheZero) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // 0^0 = 1 by programming convention
    EXPECT_EQ(ModularArithmetic.modularExponentiation(0,0,2), 1);
}

TEST(TestModularExponentiation, PowerIsZero) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // a^0
    ASSERT_EQ(ModularArithmetic.modularExponentiation(2,0,2), 1);
}

TEST(TestModularExponentiation, BaseIsZero) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // 0^a
    ASSERT_EQ(ModularArithmetic.modularExponentiation(0,2,2), 0);
}

TEST(TestModularExponentiation, BaseGreaterThanModulus) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Base > Mod
    ASSERT_EQ(ModularArithmetic.modularExponentiation(17,3,5), 3);
}

TEST(TestModularExponentiation, PowerGreaterThanModulus) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Power > Mod
    ASSERT_EQ(ModularArithmetic.modularExponentiation(3,12,7), 1);
}

TEST(TestModularExponentiation, LE20Digit) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Large numbers
    cpp_int base {"123456789012345678901234567890123456789"};
    cpp_int power {"98765432109876543210987654321"};
    cpp_int modulus {"1000000007"};
    cpp_int result {"837711231"};
    ASSERT_EQ(ModularArithmetic.modularExponentiation(base, power, modulus), result);

    // TODO add more cases here. Test the limits on digit length

}

TEST(TestModularExponentiation, FiveHundredDigitBaseAndExponent) {
    Crypto::ModularArithmetic ModularArithmetic{};
    cpp_int base    {"86968662036672408100060847287298373941136888195852052166606174830968239446843218517669723073856097544489812276497194099159804492276171396144141863566699564402357295746480341033315354796150134620755571081374336051196606108220824056030938690033071230634715848882704218660231554867218646661686334784198933506555487533306548875196372165810324961986791259244788619657772384433117287575455206164822239315948809749993849884487806534212880632907100008644808735503631550721979540282354265287063266531370638231"};
    cpp_int power   {"16239148709356929650097859653634587684174379919425259180147315709821016414695031672321703430670304762717707513967173937965356581108743287185942539588439391056673153400845379471958124100641693799015864973900620190932841765017171435099955747511491831933822053341353789338931910608646821024720551770938025965920077223099920383441706164472852923000789133871499056933378724102317071058551984438345932360401122262000887150779942983210867139271987447556414720608291802483053210027281312128641210286405704066"};
    cpp_int modulus {"462567718062290590610719764009575956736052022994017267242205938939857700977343742099606005214022899217935079856284164164321143630995428578934247698652340585218538185741256903085185053691735998197368115110605012998226052392281128268795431344250996440606510499847178681148610363340302241413356337303320"};
    cpp_int result  {"27175039440128612809635265455985693032179389430855059849121660004157508589491447940847198345031558285217799054920339719162637189638398253015927908507755559768220490612492334072029763134083118724428529643518222939651707791821506440665254778849449661531628126824080223174182212959356294578580275761641"};
    EXPECT_EQ(ModularArithmetic.modularExponentiation(base, power, modulus), result);
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
    EXPECT_THROW(ModularArithmetic.modularMultiplicativeInverse(4, 8), std::runtime_error);
}

TEST(TestModularMultiplicativeInverse, LE20Digit) {
    Crypto::ModularArithmetic ModularArithmetic{};
    cpp_int a {cpp_int("12345678901234567890")};
    cpp_int mod {cpp_int("98765432109876543211")};
    EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(a, mod), cpp_int("94316753668893093070")); // Precomputed result
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
    EXPECT_THROW(ModularArithmetic.modularMultiplicativeInverse(12, 15), std::runtime_error);
}

// Extended Euclidean Algorithm: https://www.dcode.fr/gcd


TEST(TestExtendedGCD, BaseCase) {
    cpp_int x, y;
    cpp_int base = 10, modulus = 0;
    cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 10);  // GCD should be 10
    EXPECT_EQ(x, 1);     // x should be 1
    EXPECT_EQ(y, 0);     // y should be 0
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
    cpp_int base    {"12345678901234567890"};
    cpp_int modulus {"9876543210987654321"};
    cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 90000000009);
    EXPECT_EQ(base * x + modulus * y, gcd); // Verify the linear combination
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}