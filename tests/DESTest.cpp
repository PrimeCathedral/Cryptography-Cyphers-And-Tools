//
// Created by Jimmy on 1/9/25.
//

#include <gtest/gtest.h>
#include "../ciphers/des.hpp"
#include "../ciphers/des.cpp"

// Fixture class for DES testing
class DESFixture : public ::testing::Test {
protected:
    DataEncryptionStandard::DES* desEncryptor {nullptr};

    // Setup before each test
    void SetUp() override {
        constexpr uint64_t sampleKey = 0x133457799BBCDFF1; // Example 64-bit key
        desEncryptor = new DataEncryptionStandard::DES(sampleKey);
    }

    // Teardown after each test
    void TearDown() override {
        delete desEncryptor;
    }
};


// TEST_F(DESFixture, InitialPermutationWorks) {
//     // Input plaintext: 0x0123456789ABCDEF
//     constexpr uint64_t input = 0x4;
//
//     // Expected output after the initial permutation (IP)
//     constexpr bitset<56> expected_output = 0x0;
//
//     // Perform the initial permutation using the DES private method
//     const auto actual_output = desEncryptor->initialPermutation(input);
//
//     // Check if the result matches the expected value
//     ASSERT_EQ(expected_output, actual_output);
// }

TEST(BoxPermute, IdentityPermutation) {
    using namespace DataEncryptionStandard;

    const std::bitset<8> input {0b10000000};
    const std::vector<int> identityBox = {1, 2, 3, 4, 5, 6, 7, 8}; // Identity permutation

    const auto output = boxPermute<8, 8>(identityBox, input);

    EXPECT_EQ(input, output); // Output should match the input
}

TEST(BoxPermute, ReversePermutation) {
    using namespace DataEncryptionStandard;

    const std::bitset<8> input {0b00000001};
    const std::vector<int> reverseBox = {8, 7, 6, 5, 4, 3, 2, 1}; // Reverses the bit order

    const std::bitset<8> expected {0b10000000}; // Reversed input

    const auto output = boxPermute<8, 8>(reverseBox, input);

    EXPECT_EQ(expected, output); // Output should be reversed
}

TEST(BoxPermute, PartialPermutation) {
    using namespace DataEncryptionStandard;

    const std::bitset<8> input {0b01010101};
    const std::vector<int> partialBox = {2, 4, 6, 8}; // Maps bits 1, 4, 6, 8 to the output

    const std::bitset<4> expected {0b1111}; // Bits from 1, 4, 6, 8 (from right to left)

    const auto output = boxPermute<4, 8>(partialBox, input);

    EXPECT_EQ(expected, output); // Output should match the selected bits
}

TEST(BoxPermute, LargerOutput) {
    using namespace DataEncryptionStandard;

    const std::bitset<2> input {0b10};
    const std::vector<int> largerBox = {1,2,1,2,1,2}; // Repeats some input bits

    const std::bitset<6> expected {0b101010}; // From repeated and reordered bits

    const auto output = boxPermute<6, 2>(largerBox, input);

    EXPECT_EQ(expected, output); // Output should match the specified mapping
}


TEST(BoxPermute, IPTest) {
    using namespace DataEncryptionStandard;
    const bitset<64> plainText {0b1};
    const bitset<64> expected {1ULL << 39};
    const auto actual {boxPermute<64, 64>(IP, plainText)};

    EXPECT_EQ(expected, actual);

}


// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}