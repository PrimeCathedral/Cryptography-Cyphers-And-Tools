//
// Created by Jimmy on 1/9/25.
//

#include "../ciphers/des.hpp"
#include "../ciphers/des.cpp"
#include <gtest/gtest.h>

using namespace DataEncryptionStandard;

// Fixture class for DES testing
class DESFixture : public ::testing::Test {
protected:
  DES *desEncryptor{nullptr};

  // Setup before each test
  void SetUp() override {
    constexpr uint64_t sampleKey = 0x133457799BBCDFF1; // Example 64-bit key
    desEncryptor = new DES(sampleKey);
  }

  // Teardown after each test
  void TearDown() override { delete desEncryptor; }
};

TEST(BoxPermute, IdentityPermutation) {
  constexpr std::bitset<8> input{0b10000000};
  const std::vector<int> identityBox = {1, 2, 3, 4,
                                        5, 6, 7, 8}; // Identity permutation

  const auto output = boxPermute<8, 8>(identityBox, input);

  EXPECT_EQ(input, output); // Output should match the input
}

TEST(BoxPermute, ReversePermutation) {
  constexpr std::bitset<8> input{0b00000001};
  const std::vector<int> reverseBox = {8, 7, 6, 5,
                                       4, 3, 2, 1}; // Reverses the bit order

  constexpr std::bitset<8> expected{0b10000000}; // Reversed input

  const auto output = boxPermute<8, 8>(reverseBox, input);

  EXPECT_EQ(expected, output); // Output should be reversed
}

TEST(BoxPermute, PartialPermutation) {
  constexpr std::bitset<8> input{0b01010101};
  const std::vector<int> partialBox = {2, 4, 6,
                                       8}; // Maps bits 1, 4, 6, 8 to the output

  constexpr std::bitset<4> expected{
      0b1111}; // Bits from 1, 4, 6, 8 (from right to left)

  const auto output = boxPermute<4, 8>(partialBox, input);

  EXPECT_EQ(expected, output); // Output should match the selected bits
}

TEST(BoxPermute, LargerOutput) {
  constexpr std::bitset<2> input{0b10};
  const std::vector<int> largerBox = {1, 2, 1,
                                      2, 1, 2}; // Repeats some input bits

  constexpr std::bitset<6> expected{
      0b101010}; // From repeated and reordered bits

  const auto output = boxPermute<6, 2>(largerBox, input);

  EXPECT_EQ(expected, output); // Output should match the specified mapping
}

TEST(BoxPermute, IPAndFPBoxTest) {

  // First half of the box
  constexpr bitset<64> p1{
      0b1111111111111111111111111111111100000000000000000000000000000000};
  constexpr bitset<64> e1{
      0b0000111100001111000011110000111100001111000011110000111100001111};
  const auto a1{boxPermute<64, 64>(IP, p1)};

  EXPECT_EQ(e1, a1);

  // Second half of the box
  constexpr bitset<64> p2{
      0b0000000000000000000000000000000011111111111111111111111111111111};
  constexpr bitset<64> e2{
      0b1111000011110000111100001111000011110000111100001111000011110000};
  const auto a2{boxPermute<64, 64>(IP, p2)};

  EXPECT_EQ(e2, a2);

  // Reverse first half
  const auto r1{boxPermute<64, 64>(FP, a1)};
  EXPECT_EQ(p1, r1);

  // Reverse second half
  const auto r2{boxPermute<64, 64>(FP, a2)};
  EXPECT_EQ(p2, r2);
}

TEST(rotateBits, PositiveShift) {
  bitset<5> original{0b10101};
  constexpr bitset<5> expected{0b11010}; // Rotate right by 1 bit
  EXPECT_EQ(rotateBits(original, 1), expected);
}
TEST(rotateBits, NegativeShift) {
  bitset<5> original{0b10101};
  constexpr bitset<5> expected{
      0b01011}; // Rotate left by 1 bit (equivalent to -1)
  EXPECT_EQ(rotateBits(original, -1), expected);
}
TEST(rotateBits, ShiftTwice) {
  bitset<4> original{0b1101};
  constexpr bitset<4> shifted{0b0111};
  EXPECT_EQ(rotateBits(original, 2), shifted);
}
TEST(rotateBits, LargePositiveShift) {
  bitset<4> original{0b1101};
  constexpr bitset<4> expected{0b0111}; // Rotate right by 6 (6 % 4 = 2)
  EXPECT_EQ(rotateBits(original, 6), expected);
}
TEST(rotateBits, LargeNegativeShift) {
  bitset<4> original{0b1101};
  constexpr bitset<4> expected{0b0111}; // Rotate left by 6 (6 % 4 = 2)
  EXPECT_EQ(rotateBits(original, -6), expected);
}
TEST(rotateBits, ShiftZeroBits) {
  bitset<4> original{0b1101};
  constexpr bitset<4> shifted{0b1101};
  EXPECT_EQ(rotateBits(original, 0), shifted);
}
TEST(rotateBits, FullRotation) {
  bitset<4> original{0b1101};
  constexpr bitset<4> shifted{0b1101};
  EXPECT_EQ(rotateBits(original, -4), shifted);
}
TEST(rotateBits, NegativeRotationEqualToSize) {
  bitset<4> original{0b1011};
  constexpr bitset<4> expected{
      0b1011}; // Rotate left by 4 (equivalent to no change)
  EXPECT_EQ(rotateBits(original, -4), expected);
}
TEST(rotateBits, RotateByOneLessThanSize) {
  bitset<4> original{0b1011};
  constexpr bitset<4> expected{0b0111}; // Rotate right by 3
  EXPECT_EQ(rotateBits(original, 3), expected);
}
TEST(rotateBits, RotateMoreThanSize) {
  bitset<4> original{0b1101};
  constexpr bitset<4> shifted{0b1110}; // 1-bit left rotation (5 % 4 = 1)
  EXPECT_EQ(rotateBits(original, 5), shifted);
}
TEST(rotateBits, AllBitsSet) {
  bitset<4> original{0b1111};
  constexpr bitset<4> shifted{0b1111};
  EXPECT_EQ(rotateBits(original, 2), shifted);
}
TEST(rotateBits, SingleBitSet) {
  bitset<4> original{0b0001};
  constexpr bitset<4> shifted{0b1000}; // Rotate left 1 bit
  EXPECT_EQ(rotateBits(original, 1), shifted);
}
TEST(rotateBits, NoBitsSet) {
  bitset<4> original{0b0000};
  constexpr bitset<4> shifted{0b0000};
  EXPECT_EQ(rotateBits(original, 3), shifted);
}
TEST(rotateBits, LargeBitset) {
  bitset<16> original{0b11111001101010111};
  constexpr bitset<16> shifted{0b11111100110101011};
  EXPECT_EQ(rotateBits(original, 1), shifted);
}
TEST(rotateBits, LargeBitsetFullRotation) {
  bitset<16> original{0b1010101010101010};
  constexpr bitset<16> shifted{0b1010101010101010}; // No change expected
  EXPECT_EQ(rotateBits(original, 16), shifted);
}
TEST(rotateBits, NegativeRotation) {
  bitset<4> original{0b1101};
  constexpr bitset<4> shifted{0b1011};
  EXPECT_EQ(rotateBits(original, -1), shifted);
}
TEST(concatenateBitsets, SmallBitsets) {
  constexpr bitset<4> B1{0b1010};
  constexpr bitset<4> B2{0b0101};
  constexpr bitset<8> expected{0b10100101};

  EXPECT_EQ(concatenateBitsets(B1, B2), expected);
}
TEST(concatenateBitsets, DifferentSizes) {
  constexpr bitset<5> B1{0b10101};
  constexpr bitset<3> B2{0b110};
  constexpr bitset<8> expected{0b10101110};

  EXPECT_EQ(concatenateBitsets(B1, B2), expected);
}
TEST(concatenateBitsets, ZeroBitset) {
  constexpr bitset<4> B1{0b0000};
  constexpr bitset<4> B2{0b0000};
  constexpr bitset<8> expected{0b00000000};

  EXPECT_EQ(concatenateBitsets(B1, B2), expected);
}
TEST(concatenateBitsets, LargeBitsets) {
  constexpr bitset<16> B1{0b1111000011110000};
  constexpr bitset<16> B2{0b0000111100001111};
  constexpr bitset<32> expected{0b11110000111100000000111100001111};

  EXPECT_EQ(concatenateBitsets(B1, B2), expected);
}
TEST(concatenateBitsets, SingleBitset) {
  constexpr bitset<4> B1{0b1010};
  constexpr bitset<0> B2{}; // Empty bitset
  constexpr bitset<4> expected{0b1010};

  EXPECT_EQ(concatenateBitsets(B1, B2), expected);
}

// Main entry point for the test runner
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}