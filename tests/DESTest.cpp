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

  const std::bitset<8> input{0b10000000};
  const std::vector<int> identityBox = {1, 2, 3, 4,
                                        5, 6, 7, 8}; // Identity permutation

  const auto output = boxPermute<8, 8>(identityBox, input);

  EXPECT_EQ(input, output); // Output should match the input
}

TEST(BoxPermute, ReversePermutation) {

  const std::bitset<8> input{0b00000001};
  const std::vector<int> reverseBox = {8, 7, 6, 5,
                                       4, 3, 2, 1}; // Reverses the bit order

  const std::bitset<8> expected{0b10000000}; // Reversed input

  const auto output = boxPermute<8, 8>(reverseBox, input);

  EXPECT_EQ(expected, output); // Output should be reversed
}

TEST(BoxPermute, PartialPermutation) {

  const std::bitset<8> input{0b01010101};
  const std::vector<int> partialBox = {2, 4, 6,
                                       8}; // Maps bits 1, 4, 6, 8 to the output

  const std::bitset<4> expected{
      0b1111}; // Bits from 1, 4, 6, 8 (from right to left)

  const auto output = boxPermute<4, 8>(partialBox, input);

  EXPECT_EQ(expected, output); // Output should match the selected bits
}

TEST(BoxPermute, LargerOutput) {

  const std::bitset<2> input{0b10};
  const std::vector<int> largerBox = {1, 2, 1,
                                      2, 1, 2}; // Repeats some input bits

  const std::bitset<6> expected{0b101010}; // From repeated and reordered bits

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
      0b1111111111111111111111111111111100000000000000000000000000000000};
  constexpr bitset<64> e2{
      0b0000111100001111000011110000111100001111000011110000111100001111};
  const auto a2{boxPermute<64, 64>(IP, p2)};

  EXPECT_EQ(e2, a2);

  // Reverse first half
  const auto r1{boxPermute<64, 64>(FP, a1)};
  EXPECT_EQ(p1, r1);

  // Reverse second half
  const auto r2{boxPermute<64, 64>(FP, a2)};
  EXPECT_EQ(p2, r2);
}

// Main entry point for the test runner
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}