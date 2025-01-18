//
// Created by Jimmy on 1/9/25.
//

#include "../ciphers/des.hpp"
#include "../ciphers/des.cpp"
#include <gtest/gtest.h>

using namespace DataEncryptionStandard;

// // Fixture class for DES testing
// class DESFixture : public ::testing::Test {
// protected:
//   DES *desEncryptor{nullptr};
//
//   // Setup before each test
//   void SetUp() override { desEncryptor = new DES(0); }
//
//   // Teardown after each test
//   void TearDown() override { delete desEncryptor; }
// };

TEST(applyPermutation, IdentityPermutation) {
  const ByteArray input{{0b10000000}};
  const std::vector<int> identityBox = {1, 2, 3, 4,
                                        5, 6, 7, 8}; // Identity permutation

  const auto output {applyPermutation(identityBox, input).to_cpp_int()};

  EXPECT_EQ(input.to_cpp_int(), output); // Output should match the input
}


// TEST(BoxPermute, IdentityPermutation) {
//   constexpr std::bitset<8> input{0b10000000};
//   const std::vector<int> identityBox = {1, 2, 3, 4,
//                                         5, 6, 7, 8}; // Identity permutation
//
//   const auto output = boxPermute<8, 8>(identityBox, input);
//
//   EXPECT_EQ(input, output); // Output should match the input
// }
//
// TEST(BoxPermute, ReversePermutation) {
//   constexpr std::bitset<8> input{0b00000001};
//   const std::vector<int> reverseBox = {8, 7, 6, 5,
//                                        4, 3, 2, 1}; // Reverses the bit order
//
//   constexpr std::bitset<8> expected{0b10000000}; // Reversed input
//
//   const auto output = boxPermute<8, 8>(reverseBox, input);
//
//   EXPECT_EQ(expected, output); // Output should be reversed
// }
//
// TEST(BoxPermute, PartialPermutation) {
//   constexpr std::bitset<8> input{0b01010101};
//   const std::vector<int> partialBox = {2, 4, 6,
//                                        8}; // Maps bits 1, 4, 6, 8 to the output
//
//   constexpr std::bitset<4> expected{
//       0b1111}; // Bits from 1, 4, 6, 8 (from right to left)
//
//   const auto output = boxPermute<4, 8>(partialBox, input);
//
//   EXPECT_EQ(expected, output); // Output should match the selected bits
// }
//
// TEST(BoxPermute, LargerOutput) {
//   constexpr std::bitset<2> input{0b10};
//   const std::vector<int> largerBox = {1, 2, 1,
//                                       2, 1, 2}; // Repeats some input bits
//
//   constexpr std::bitset<6> expected{
//       0b101010}; // From repeated and reordered bits
//
//   const auto output = boxPermute<6, 2>(largerBox, input);
//
//   EXPECT_EQ(expected, output); // Output should match the specified mapping
// }
//
// TEST(BoxPermute, IPAndFPBoxTest) {
//
//   // First half of the box
//   constexpr bitset<64> p1{
//       0b1111111111111111111111111111111100000000000000000000000000000000};
//   constexpr bitset<64> e1{
//       0b0000111100001111000011110000111100001111000011110000111100001111};
//   const auto a1{boxPermute<64, 64>(kInitialPermutationBox, p1)};
//
//   EXPECT_EQ(e1, a1);
//
//   // Second half of the box
//   constexpr bitset<64> p2{
//       0b0000000000000000000000000000000011111111111111111111111111111111};
//   constexpr bitset<64> e2{
//       0b1111000011110000111100001111000011110000111100001111000011110000};
//   const auto a2{boxPermute<64, 64>(kInitialPermutationBox, p2)};
//
//   EXPECT_EQ(e2, a2);
//
//   // Reverse first half
//   // TODO: remove auto
//   const auto r1{boxPermute<64, 64>(kFinalPermutationBox, a1)};
//   EXPECT_EQ(p1, r1);
//
//   // Reverse second half
//   const auto r2{boxPermute<64, 64>(kFinalPermutationBox, a2)};
//   EXPECT_EQ(p2, r2);
// }
//
// // Test: Splitting a 16-bit bitset into 4-bit segments
// TEST(SplitBitset, SplitIntoEqualSegments) {
//   constexpr bitset<16> original{0b1111000011110000};
//   const auto result = splitBitset<4>(original);
//
//   ASSERT_EQ(result.size(), 4); // Should produce 4 segments
//   EXPECT_EQ(result[0], bitset<4>{0b1111});
//   EXPECT_EQ(result[1], bitset<4>{0b0000});
//   EXPECT_EQ(result[2], bitset<4>{0b1111});
//   EXPECT_EQ(result[3], bitset<4>{0b0000});
// }
//
// // Test: Splitting a 12-bit bitset into 4-bit segments
// TEST(SplitBitset, SplitUnevenSegments) {
//   constexpr bitset<12> original{0b101010111100};
//   const auto result{splitBitset<4>(original)};
//
//   ASSERT_EQ(result.size(), 3); // Should produce 3 segments
//   EXPECT_EQ(result[0], bitset<4>{0b1010});
//   EXPECT_EQ(result[1], bitset<4>{0b1011});
//   EXPECT_EQ(result[2], bitset<4>{0b1100});
// }
//
// // Test: Splitting a 64-bit bitset into 8-bit segments
// TEST(SplitBitset, LargeBitsetSplit) {
//   constexpr bitset<64> original{
//       0x0123456789ABCDEF}; // Hexadecimal initialization
//   const auto result = splitBitset<8>(original);
//
//   ASSERT_EQ(result.size(), 8);                 // Should produce 8 segments
//   EXPECT_EQ(result[7], bitset<8>{0b11101111}); // Least significant 8 bits
//   EXPECT_EQ(result[6], bitset<8>{0b11001101}); //
//   EXPECT_EQ(result[5], bitset<8>{0b10101011}); //
//   EXPECT_EQ(result[4], bitset<8>{0b10001001}); //
//   EXPECT_EQ(result[3], bitset<8>{0b01100111}); //
//   EXPECT_EQ(result[2], bitset<8>{0b01000101}); //
//   EXPECT_EQ(result[1], bitset<8>{0b00100011}); //
//   EXPECT_EQ(result[0], bitset<8>{0b00000001}); // Most significant 8 bits
// }
//
// // Test: Edge case with 1-bit splits
// TEST(SplitBitset, SingleBitSegments) {
//   constexpr bitset<8> original{0b10110011};
//   const auto result = splitBitset<1>(original);
//
//   ASSERT_EQ(result.size(), 8); // Should produce 8 segments
//   EXPECT_EQ(result[7], bitset<1>{1});
//   EXPECT_EQ(result[6], bitset<1>{1});
//   EXPECT_EQ(result[5], bitset<1>{0});
//   EXPECT_EQ(result[4], bitset<1>{0});
//   EXPECT_EQ(result[3], bitset<1>{1});
//   EXPECT_EQ(result[2], bitset<1>{1});
//   EXPECT_EQ(result[1], bitset<1>{0});
//   EXPECT_EQ(result[0], bitset<1>{1});
// }
//
// // Test: Throwing an exception for invalid split sizes
// TEST(SplitBitset, InvalidSplitSize) {
//   constexpr bitset<10> original{0b1111000000};
//
//   // 3 is not a divisor fo 10
//   EXPECT_THROW(splitBitset<3>(original), std::invalid_argument);
// }
//
// // Test: No-op with the same split size as original size
// TEST(SplitBitset, SplitSameAsOriginalSize) {
//   constexpr bitset<8> original{0b11001010};
//   ASSERT_THROW(splitBitset<8>(original), std::invalid_argument);
// }
//
// TEST(rotateBits, PositiveShift) {
//   bitset<5> original{0b10101};
//   constexpr bitset<5> expected{0b11010}; // Rotate right by 1 bit
//   EXPECT_EQ(rotateBits(original, 1), expected);
// }
// TEST(rotateBits, NegativeShift) {
//   bitset<5> original{0b10101};
//   constexpr bitset<5> expected{
//       0b01011}; // Rotate left by 1 bit (equivalent to -1)
//   EXPECT_EQ(rotateBits(original, -1), expected);
// }
// TEST(rotateBits, ShiftTwice) {
//   bitset<4> original{0b1101};
//   constexpr bitset<4> shifted{0b0111};
//   EXPECT_EQ(rotateBits(original, 2), shifted);
// }
// TEST(rotateBits, LargePositiveShift) {
//   bitset<4> original{0b1101};
//   constexpr bitset<4> expected{0b0111}; // Rotate right by 6 (6 % 4 = 2)
//   EXPECT_EQ(rotateBits(original, 6), expected);
// }
// TEST(rotateBits, LargeNegativeShift) {
//   bitset<4> original{0b1101};
//   constexpr bitset<4> expected{0b0111}; // Rotate left by 6 (6 % 4 = 2)
//   EXPECT_EQ(rotateBits(original, -6), expected);
// }
// TEST(rotateBits, ShiftZeroBits) {
//   bitset<4> original{0b1101};
//   constexpr bitset<4> shifted{0b1101};
//   EXPECT_EQ(rotateBits(original, 0), shifted);
// }
// TEST(rotateBits, FullRotation) {
//   bitset<4> original{0b1101};
//   constexpr bitset<4> shifted{0b1101};
//   EXPECT_EQ(rotateBits(original, -4), shifted);
// }
// TEST(rotateBits, NegativeRotationEqualToSize) {
//   bitset<4> original{0b1011};
//   constexpr bitset<4> expected{
//       0b1011}; // Rotate left by 4 (equivalent to no change)
//   EXPECT_EQ(rotateBits(original, -4), expected);
// }
// TEST(rotateBits, RotateByOneLessThanSize) {
//   bitset<4> original{0b1011};
//   constexpr bitset<4> expected{0b0111}; // Rotate right by 3
//   EXPECT_EQ(rotateBits(original, 3), expected);
// }
// TEST(rotateBits, RotateMoreThanSize) {
//   bitset<4> original{0b1101};
//   constexpr bitset<4> shifted{0b1110}; // 1-bit left rotation (5 % 4 = 1)
//   EXPECT_EQ(rotateBits(original, 5), shifted);
// }
// TEST(rotateBits, AllBitsSet) {
//   bitset<4> original{0b1111};
//   constexpr bitset<4> shifted{0b1111};
//   EXPECT_EQ(rotateBits(original, 2), shifted);
// }
// TEST(rotateBits, SingleBitSet) {
//   bitset<4> original{0b0001};
//   constexpr bitset<4> shifted{0b1000}; // Rotate left 1 bit
//   EXPECT_EQ(rotateBits(original, 1), shifted);
// }
// TEST(rotateBits, NoBitsSet) {
//   bitset<4> original{0b0000};
//   constexpr bitset<4> shifted{0b0000};
//   EXPECT_EQ(rotateBits(original, 3), shifted);
// }
// TEST(rotateBits, LargeBitset) {
//   bitset<16> original{0b11111001101010111};
//   constexpr bitset<16> shifted{0b11111100110101011};
//   EXPECT_EQ(rotateBits(original, 1), shifted);
// }
// TEST(rotateBits, LargeBitsetFullRotation) {
//   bitset<16> original{0b1010101010101010};
//   constexpr bitset<16> shifted{0b1010101010101010}; // No change expected
//   EXPECT_EQ(rotateBits(original, 16), shifted);
// }
// TEST(rotateBits, NegativeRotation) {
//   bitset<4> original{0b1101};
//   constexpr bitset<4> shifted{0b1011};
//   EXPECT_EQ(rotateBits(original, -1), shifted);
// }
// TEST(concatenateBitsets, SmallBitsets) {
//   constexpr bitset<4> B1{0b1010};
//   constexpr bitset<4> B2{0b0101};
//   constexpr bitset<8> expected{0b10100101};
//
//   EXPECT_EQ(concatenateBitsets(B1, B2), expected);
// }
// TEST(concatenateBitsets, DifferentSizes) {
//   constexpr bitset<5> B1{0b10101};
//   constexpr bitset<3> B2{0b110};
//   constexpr bitset<8> expected{0b10101110};
//
//   EXPECT_EQ(concatenateBitsets(B1, B2), expected);
// }
// TEST(concatenateBitsets, ZeroBitset) {
//   constexpr bitset<4> B1{0b0000};
//   constexpr bitset<4> B2{0b0000};
//   constexpr bitset<8> expected{0b00000000};
//
//   EXPECT_EQ(concatenateBitsets(B1, B2), expected);
// }
// TEST(concatenateBitsets, LargeBitsets) {
//   constexpr bitset<16> B1{0b1111000011110000};
//   constexpr bitset<16> B2{0b0000111100001111};
//   constexpr bitset<32> expected{0b11110000111100000000111100001111};
//
//   EXPECT_EQ(concatenateBitsets(B1, B2), expected);
// }
// TEST(concatenateBitsets, SingleBitset) {
//   constexpr bitset<4> B1{0b1010};
//   constexpr bitset<0> B2{}; // Empty bitset
//   constexpr bitset<4> expected{0b1010};
//
//   EXPECT_EQ(concatenateBitsets(B1, B2), expected);
// }
//
// const std::vector<bitset<48>> expectedRoundKeys{
//          {0b000110110000001011101111111111000111000001110010},  // Key 00
//          {0b011110011010111011011001110110111100100111100101},  // Key 01
//          {0b010101011111110010001010010000101100111110011001},  // Key 02
//          {0b011100101010110111010110110110110011010100011101},  // Key 03
//          {0b011111001110110000000111111010110101001110101000},  // Key 04
//          {0b011000111010010100111110010100000111101100101111},  // Key 05
//          {0b111011001000010010110111111101100001100010111100},  // Key 06
//          {0b111101111000101000111010110000010011101111111011},  // Key 07
//          {0b111000001101101111101011111011011110011110000001},  // Key 08
//          {0b101100011111001101000111101110100100011001001111},  // Key 09
//          {0b001000010101111111010011110111101101001110000110},  // Key 10
//          {0b011101010111000111110101100101000110011111101001},  // Key 11
//          {0b100101111100010111010001111110101011101001000001},  // Key 12
//          {0b010111110100001110110111111100101110011100111010},  // Key 13
//          {0b101111111001000110001101001111010011111100001010},  // Key 14
//          {0b110010110011110110001011000011100001011111110101}   // Key 15
//       };
//
// TEST_F(DESFixture, generateRoundKeys_CorrectNumberOfKeys) {
//   desEncryptor->setKey(0x133457799BBCDFF1);
//
//   // Ensure that exactly 16 round keys are generated
//   for (int i = 0; i <= 15; ++i) {
//     EXPECT_EQ(desEncryptor->roundKeys[i].size(), 48);
//   }
// }
//
// TEST_F(DESFixture, GenerateRoundKeys_KnownKeyTest) {
//     desEncryptor->setKey(0x133457799BBCDFF1);
//
//     for (int i = 0; i < expectedRoundKeys.size(); ++i) {
//         EXPECT_EQ(desEncryptor->roundKeys[i], expectedRoundKeys[i]) << "Mismatch in round key " << (i);
//     }
// }
//
// TEST_F(DESFixture, GenerateRoundKeys_AllZeroKey) {
//     desEncryptor->setKey(0x0); // All-zero key
//
//     // Verify all round keys are zero
//     for (int i {0}; i < 16; ++i) {
//         EXPECT_EQ(desEncryptor->roundKeys[i].to_ullong(), 0) << "Round key " << i << "should be zero.";
//     }
// }
//
// TEST_F(DESFixture, GenerateRoundKeys_AllOneKey) {
//     desEncryptor->setKey(0xFFFFFFFFFFFFFFFF); // All-one key
//
//     // Verify all round keys are generated correctly
//     for (int i {0}; i < 16; ++i) {
//         EXPECT_NE(desEncryptor->roundKeys[i].to_ullong(), 0) << "Round key " << i << "should be one.";
//     }
// }
//
// TEST_F(DESFixture, GenerateRoundKeys_AlternatingBitsKey) {
//     desEncryptor->setKey(0x133457799BBCDFF1);
//
//     for (int i {0}; i < 16; ++i) {
//         EXPECT_NE(desEncryptor->roundKeys[i].to_ullong(), 0) << "Round key " << i << "should not be zero.";
//     }
// }
//
// TEST_F(DESFixture, GenerateRoundKeys_PermutationConsistency) {
//     desEncryptor->setKey(0x133457799BBCDFF1);
//
//     // Ensure all round keys are unique
//     std::unordered_map<bitset<48>, int> uniqueKeys;
//     for (int i {0}; i < 16; ++i) {
//         uniqueKeys[desEncryptor->roundKeys[i].to_ullong()]++;
//     }
//
//     EXPECT_EQ(uniqueKeys.size(), 16) << "Some round keys are duplicated.";
// }
//
// TEST(ConcatenateBitsets, Basic_Concatenation) {
//   constexpr bitset<4> a {0b1111};
//   constexpr bitset<4> b {0b0000};
//   constexpr bitset<4> c {0b1100};
//   const vector<bitset<4>> z {a, b, c};
//   constexpr bitset<12> r {0b111100001100};
//
//   EXPECT_EQ(concatenateBitsets<12>(z), r);
// }
//
// TEST(ConcatenateBitsets, EdgeCase_AllZeros) {
//   const vector<bitset<4>> z {{0b0000},{0b0000},{0b0000}};
//   constexpr bitset<12> output {0b000000000000};
//   EXPECT_EQ(concatenateBitsets<12>(z), output);
// }
//
// TEST(ConcatenateBitsets, EdgeCase_SingleBitset) {
//   const vector<bitset<4>> z {{0b1100}};
//   constexpr bitset<4> expected {0b1100};
//   EXPECT_EQ(expected, concatenateBitsets<4>(z));
// }
//
// TEST(ConcatenateBitsets, EdgeCase_InvalidInput) {
//   const vector<bitset<4>> z {0b1010, 0b1100};
//   EXPECT_THROW(concatenateBitsets<10>(z), std::invalid_argument);
// }
//
//
// TEST_F(DESFixture, EncryptAndDecrypt) {
//   desEncryptor->setKey(0x133457799BBCDFF1);
//   constexpr auto plaintext {0b1100};
//   const auto ciphertext {desEncryptor->encrypt(plaintext)};
//   const auto decryption {desEncryptor->decrypt(ciphertext)};
//   EXPECT_EQ(decryption, plaintext);
// }
// Main entry point for the test runner
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}