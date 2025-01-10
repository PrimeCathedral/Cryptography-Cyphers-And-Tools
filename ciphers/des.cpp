//
// Created by Jimmy on 1/7/25.
//

#include "des.hpp"

#include <bitset>

using std::bitset;
using std::vector;

    // Initial Permutation Box (IP)
    const vector<int> DataEncryptionStandard::IP {
        58,	50,	42,	34,	26,	18,	10,	2,  // 7
        60,	52,	44,	36,	28,	20,	12,	4,  // 15
        62,	54,	46,	38,	30,	22,	14,	6,  // 23
        64,	56,	48,	40,	32,	24,	16,	8,  // 31
        57,	49,	41,	33,	25,	17,	9,	1,  // 39
        59,	51,	43,	35,	27,	19,	11,	3,  // 47
        61,	53,	45,	37,	29,	21,	13,	5,  // 55
        63,	55,	47,	39,	31,	23,	15,	7   // 63
    };

    // Final Permutation (IP ^-1)
    const vector<int> DataEncryptionStandard::FP {
        40,	8, 48, 16, 56, 24, 64, 32,
        39,	7, 47, 15, 55, 23, 63, 31,
        38,	6, 46, 14, 54, 22, 62, 30,
        37,	5, 45, 13, 53, 21, 61, 29,
        36,	4, 44, 12, 52, 20, 60, 28,
        35,	3, 43, 11, 51, 19, 59, 27,
        34,	2, 42, 10, 50, 18, 58, 26,
        33,	1, 41,  9, 49, 17, 57, 25
    };

    // Expansion Function Box (E). Expands from 32 bits to 48 bits
    const vector<int> DataEncryptionStandard::E {
        32,	1,	2,	3,	4,	5,
        4,	5,	6,	7,	8,	9,
        8,	9,	10,	11,	12,	13,
        12,	13,	14,	15,	16,	17,
        16,	17,	18,	19,	20,	21,
        20,	21,	22,	23,	24,	25,
        24,	25,	26,	27,	28,	29,
        28,	29,	30,	31,	32,	1
    };

    // Permutation Box (P)
    const vector<int> DataEncryptionStandard::P {
        16,	07,	20,	21,	29,	12,	28,	17,
        01,	15,	23,	26,	05,	18,	31,	10,
        02,	 8,	24,	14,	32,	27,	03,	 9,
        19,	13,	30,	06,	22,	11,	04,	25
    };

    // Permuted choice 1 box (PC-1)
    const vector<int> DataEncryptionStandard::PC1 {
        57,	49,	41,	33,	25,	17,	9,
        01,	58,	50,	42,	34,	26,	18,
        10,	02,	59,	51,	43,	35,	27,
        19,	11,	03,	60,	52,	44,	36,
        63,	55,	47,	39,	31,	23,	15,
        07,	62,	54,	46,	38,	30,	22,
        14,	6,	61,	53,	45,	37,	29,
        21,	13,	05,	28,	20,	12,	04
    };

    // Permuted choice 2 box (PC-2)
    const vector<int> DataEncryptionStandard::PC2 {
        14,	17,	11,	24,	1,	5,
        3,	28,	15,	6,	21,	10,
        23,	19,	12,	4,	26,	8,
        16,	7,	27,	20,	13,	2,
        41,	52,	31,	37,	47,	55,
        30,	40,	51,	45,	33,	48,
        44,	49,	39,	56,	34,	53,
        46,	42,	50,	36,	29,	32
    };

    // S-Boxes used in the DES algorithm.
    // Each S-Box is a 4x16 table of values, defining how a 6-bit input is transformed into a 4-bit output.
    // There are 8 S-Boxes in total, each responsible for a specific transformation during the Feistel function.
    const vector<const vector<const vector<int>>> DataEncryptionStandard::S_BOXES {
        // S-Box 1
        {
        {14,	4,	13,	1,	2,	15,	11,	8,	3,	10,	6,	12,	5,	9,	0,	7},
        {0,	15,	7,	4,	14,	2,	13,	1,	10,	6,	12,	11,	9,	5,	3,	8},
        {4,	1,	14,	8,	13,	6,	2,	11,	15,	12,	9,	7,	3,	10,	5,	0},
        {15,	12,	8,	2,	4,	9,	1,	7,	5,	11,	3,	14,	10,	0,	6,	13}
        },
        // S-Box 2
    {
        {15,	1,	8,	14,	6,	11,	3,	4,	9,	7,	2,	13,	12,	0,	5,	10},
        {3,	13,	4,	7,	15,	2,	8,	14,	12,	0,	1,	10,	6,	9,	11,	5},
        {0,	14,	7,	11,	10,	4,	13,	1,	5,	8,	12,	6,	9,	3,	2,	15},
        {13,	8,	10,	1,	3,	15,	4,	2,	11,	6,	7,	12,	0,	5,	14,	9}
        },
        // S-Box 3
        {
            {10,	0,	9,	14,	6,	3,	15,	5,	1,	13,	12,	7,	11,	4,	2,	8},
            {13,	7,	0,	9,	3,	4,	6,	10,	2,	8,	5,	14,	12,	11,	15,	1},
            {13,	6,	4,	9,	8,	15,	3,	0,	11,	1,	2,	12,	5,	10,	14,	7},
            {1,	10,	13,	0,	6,	9,	8,	7,	4,	15,	14,	3,	11,	5,	2,	12}
        },
        // S-Box 4
        {
            {7,	13,	14,	3,	0,	6,	9,	10,	1,	2,	8,	5,	11,	12,	4,	15},
            {13,	8,	11,	5,	6,	15,	0,	3,	4,	7,	2,	12,	1,	10,	14,	9},
            {10,	6,	9,	0,	12,	11,	7,	13,	15,	1,	3,	14,	5,	2,	8,	4},
            {3,	15,	0,	6,	10,	1,	13,	8,	9,	4,	5,	11,	12,	7,	2,	14}
        },
        // S-Box 5
        {
            {2,	12,	4,	1,	7,	10,	11,	6,	8,	5,	3,	15,	13,	0,	14,	9},
            {14,	11,	2,	12,	4,	7,	13,	1,	5,	0,	15,	10,	3,	9,	8,	6},
            {4,	2,	1,	11,	10,	13,	7,	8,	15,	9,	12,	5,	6,	3,	0,	14},
            {11,	8,	12,	7,	1,	14,	2,	13,	6,	15,	0,	9,	10,	4,	5,	3},
        },
        //S-Box 6
        {
            {12,	1,	10,	15,	9,	2,	6,	8,	0,	13,	3,	4,	14,	7,	5,	11},
            {10,	15,	4,	2,	7,	12,	9,	5,	6,	1,	13,	14,	0,	11,	3,	8},
            {9,	14,	15,	5,	2,	8,	12,	3,	7,	0,	4,	10,	1,	13,	11,	6},
            {4,	3,	2,	12,	9,	5,	15,	10,	11,	14,	1,	7,	6,	0,	8,	13}
        },
        // S-Box 7
        {
            {4,	11,	2,	14,	15,	0,	8,	13,	3,	12,	9,	7,	5,	10,	6,	1},
            {13,	0,	11,	7,	4,	9,	1,	10,	14,	3,	5,	12,	2,	15,	8,	6},
            {1,	4,	11,	13,	12,	3,	7,	14,	10,	15,	6,	8,	0,	5,	9,	2},
            {6,	11,	13,	8,	1,	4,	10,	7,	9,	5,	0,	15,	14,	2,	3,	12}
        },
        // S-Box 8
        {
            {13,	2,	8,	4,	6,	15,	11,	1,	10,	9,	3,	14,	5,	0,	12,	7},
            {1,	15,	13,	8,	10,	3,	7,	4,	12,	5,	6,	11,	0,	14,	9,	2},
            {7,	11,	4,	1,	9,	12,	14,	2,	0,	6,	10,	13,	15,	3,	5,	8},
            {2,	1,	14,	7,	4,	10,	8,	13,	15,	12,	9,	0,	3,	5,	6,	11}
        }
    };

// SHIFT_SCHEDULE[i] returns the number of bits to shift in round i
const vector<int> DataEncryptionStandard::SHIFT_SCHEDULE {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

DataEncryptionStandard::DES::DES(const uint64_t key) : key(key) {};

namespace DataEncryptionStandard{
template <size_t Output, size_t Input>
bitset<Output> boxPermute(const vector<int>& Box, const bitset<Input>& original) {
    bitset<Output> permuted_text;

    // Ensure the size of the Box matches the Output size
    if (Box.size() != Output) {
        throw std::invalid_argument("Box size must match Output size.");
    }

    // Perform the permutation
    for (size_t i {0}; i < Output; ++i) {
        int bitFromOriginal = (Input - 1) - (Box[i] - 1); // Convert 1-based index to 0-based
        int newValue = original[bitFromOriginal];
        int bitToChange = (Output - 1) - i; // The bit we want to change is i from left to right, and bitset works right to left

        // Validate the index
        if (bitFromOriginal < 0 || bitFromOriginal >= Input) {
            throw std::out_of_range("Invalid index in Box for the given Input size.");
        }

        // Set the corresponding bit in permuted_text
        permuted_text.set(bitToChange, newValue);
    }
    return permuted_text;
}
}

