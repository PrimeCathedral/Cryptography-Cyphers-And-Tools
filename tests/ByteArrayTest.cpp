//
// Created by Jimmy on 1/18/25.
//
#include <gtest/gtest.h>
#include "../Utilities/bytearray.h"

using namespace boost::multiprecision;

// Test for ByteArray::getBit
TEST(ByteArray, GetBit_ValidIndex) {
    const ByteArray input{std::vector<uint8_t>{{0b10101010}}};
    EXPECT_TRUE(input.getBit(0));  // First bit
    EXPECT_FALSE(input.getBit(1)); // Second bit
    EXPECT_TRUE(input.getBit(2));  // Third bit
    EXPECT_FALSE(input.getBit(3)); // Fourth bit
    EXPECT_TRUE(input.getBit(4));  // Fifth bit
    EXPECT_FALSE(input.getBit(5)); // Sixth bit
    EXPECT_TRUE(input.getBit(6));  // Seventh bit
    EXPECT_FALSE(input.getBit(7)); // Eighth bit
}

TEST(ByteArray, GetBit_OutOfBounds) {
    const ByteArray input{std::vector<uint8_t>{{0b10101010}}};
    EXPECT_THROW(input.getBit(8), std::out_of_range);
    EXPECT_THROW(input.getBit(100), std::out_of_range);
}

TEST(ByteArray, GetBit_MultiByte) {
    const ByteArray input{std::vector<uint8_t>{{0b10101010, 0b11001100}}};
    EXPECT_TRUE(input.getBit(0));  // First byte, first bit
    EXPECT_FALSE(input.getBit(15)); // Second byte, eighth bit
    EXPECT_TRUE(input.getBit(8));  // Second byte, first bit
}

// Test for ByteArray::setBit
TEST(ByteArray, SetBit_ValidIndex_SetTo1) {
    ByteArray input{std::vector<uint8_t>{{0b00000000}}};
    input.setBit(0, true); // Set first bit to 1
    EXPECT_TRUE(input.getBit(0));
    EXPECT_EQ(input.to_cpp_int(), 0b10000000); // Confirm result
}

TEST(ByteArray, SetBit_ValidIndex_SetTo0) {
    ByteArray input{std::vector<uint8_t>{{0b11111111}}};
    input.setBit(7, false); // Set last bit to 0
    EXPECT_FALSE(input.getBit(7));
    EXPECT_EQ(input.to_cpp_int(), 0b11111110); // Confirm result
}

TEST(ByteArray, SetBit_OutOfBounds) {
    ByteArray input{std::vector<uint8_t>{{0b00000000}}};
    EXPECT_THROW(input.setBit(8, true), std::out_of_range);
    EXPECT_THROW(input.setBit(100, false), std::out_of_range);
}

TEST(ByteArray, SetBit_MultiByte) {
    ByteArray input{std::vector<uint8_t>{{0b00000000, 0b00000000}}};
    input.setBit(9, true); // Second byte, second bit
    EXPECT_TRUE(input.getBit(9));
    EXPECT_EQ(input.to_cpp_int(), 0b0000000001000000); // Confirm result
}

TEST(ByteArray, SetBit_FlipBits) {
    ByteArray input{std::vector<uint8_t>{{0b00000000}}};
    for (size_t i = 0; i < 8; ++i) {
        input.setBit(i, true); // Set all bits to 1
    }
    EXPECT_EQ(input.to_cpp_int(), 0b11111111);
    for (size_t i = 0; i < 8; ++i) {
        input.setBit(i, false); // Reset all bits to 0
    }
    EXPECT_EQ(input.to_cpp_int(), 0b00000000);
}

TEST(ByteArray, Convert_to_cpp_int_Simple) {
    const ByteArray input{std::vector<uint8_t>{{0b00000001}, {0b00000010}, {0b00000100}}};
    constexpr auto expected{0b000000010000001000000100};
    const auto actual = input.to_cpp_int();
    EXPECT_EQ(expected, actual);
}

TEST(ByteArray, Convert_to_cpp_int_SingleByte) {
    const ByteArray input{std::vector<uint8_t>{{0b11110000}}};
    constexpr auto expected{0b11110000};
    const auto actual = input.to_cpp_int();
    EXPECT_EQ(expected, actual);
}

TEST(ByteArray, Convert_to_cpp_int_EmptyArray) {
    const ByteArray input{std::vector<uint8_t>{}};
    constexpr auto expected{0};
    const auto actual = input.to_cpp_int();
    EXPECT_EQ(expected, actual);
}

TEST(ByteArray, Convert_to_cpp_int_MultipleBytes) {
    const ByteArray input{std::vector<uint8_t>{{0b11111111}, {0b00000000}, {0b10101010}}};
    constexpr auto expected{0b111111110000000010101010};
    const auto actual = input.to_cpp_int();
    EXPECT_EQ(expected, actual);
}

TEST(ByteArray, Convert_to_cpp_int_MaxByteValues) {
    const ByteArray input{std::vector<uint8_t>{{0xFF}, {0xFF}, {0xFF}, {0xFF}}};
    constexpr auto expected{0xFFFFFFFF};
    const auto actual = input.to_cpp_int();
    EXPECT_EQ(expected, actual);
}

TEST(ByteArray, Convert_to_cpp_int_LeadingZeros) {
    const ByteArray input{std::vector<uint8_t>{{0b00000000}, {0b00000001}, {0b00000010}}};
    constexpr auto expected{0b000000000000000100000010};
    const auto actual = input.to_cpp_int();
    EXPECT_EQ(expected, actual);
}

TEST(ByteArray, Convert_to_cpp_int_LargeArray) {
    const ByteArray input{
        std::vector<uint8_t>{{0x01}, {0x23}, {0x45}, {0x67}, {0x89}, {0xAB}, {0xCD}, {0xEF}}};
    constexpr auto expected{0x0123456789ABCDEF};
    const auto actual = input.to_cpp_int();
    EXPECT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}