//
// Created by Jimmy on 1/7/25.
//

#include "des.hpp"
#import <bitset>;

using std::bitset;
using std::vector;

// Initial Permutation Box (IP)
const vector<int> DataEncryptionStandard::kInitialPermutationBox{
    58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

// Final Permutation (IP ^-1)
const vector<int> DataEncryptionStandard::kFinalPermutationBox{
    40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9,  49, 17, 57, 25};

// Expansion Function Box (E). Expands from 32 bits to 48 bits
const vector<int> DataEncryptionStandard::kExpansionFunctionBox{
    32, 1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,  8,  9,  10, 11,
    12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};

// Permutation Box (P)
const vector<int> DataEncryptionStandard::kPermutationBox{
    16, 07, 20, 21, 29, 12, 28, 17, 01, 15, 23, 26, 05, 18, 31, 10,
    02, 8,  24, 14, 32, 27, 03, 9,  19, 13, 30, 06, 22, 11, 04, 25};

// Permuted choice 1 box (PC-1)
const vector<int> DataEncryptionStandard::kPermutedChoiceOneBox{
    57, 49, 41, 33, 25, 17, 9,  01, 58, 50, 42, 34, 26, 18, 10, 02, 59, 51, 43,
    35, 27, 19, 11, 03, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 07, 62, 54,
    46, 38, 30, 22, 14, 6,  61, 53, 45, 37, 29, 21, 13, 05, 28, 20, 12, 04};

// Permuted choice 2 box (PC-2)
const vector<int> DataEncryptionStandard::kPermutedChoiceTwoBox{
    14, 17, 11, 24, 1,  5,  3,  28, 15, 6,  21, 10, 23, 19, 12, 4,
    26, 8,  16, 7,  27, 20, 13, 2,  41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

// S-Boxes used in the DES algorithm.
// Each S-Box is a 4x16 table of values, defining how a 6-bit input is
// transformed into a 4-bit output. There are 8 S-Boxes in total, each
// responsible for a specific transformation during the Feistel function.
const vector<const vector<const vector<int>>> DataEncryptionStandard::kSBoxes{
    // S-Box 1
    {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
     {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
     {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
     {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
    // S-Box 2
    {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
     {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
     {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
     {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
    // S-Box 3
    {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
     {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
     {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
     {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
    // S-Box 4
    {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
     {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
     {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
     {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
    // S-Box 5
    {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
     {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
     {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
     {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
    // S-Box 6
    {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
     {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
     {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
     {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
    // S-Box 7
    {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
     {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
     {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
     {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
    // S-Box 8
    {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
     {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
     {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
     {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

// SHIFT_SCHEDULE[i] returns the number of bits to shift in round i
const vector<int> DataEncryptionStandard::kShiftSchedule{
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

DataEncryptionStandard::DES::DES(const uint64_t key) : key(key), current_round(0) {
  this->generateRoundKeys();
}

namespace DataEncryptionStandard {
template <size_t Output, size_t Input>
bitset<Output> boxPermute(const vector<int> &Box,
                          const bitset<Input> &original) {
  bitset<Output> permuted_text;

  // Ensure the size of the Box matches the Output size
  if (Box.size() != Output) {
    throw std::invalid_argument("Box size must match Output size.");
  }

  // Perform the permutation
  for (size_t i{0}; i < Output; ++i) {
    int bitFromOriginal =
        (Input - 1) - (Box[i] - 1); // Convert 1-based index to 0-based
    int newValue = original[bitFromOriginal];
    int bitToChange =
        (Output - 1) - i; // The bit we want to change is i from left to right,
    // and bitset works right to left

    // Validate the index
    if (bitFromOriginal < 0 || bitFromOriginal >= Input) {
      throw std::out_of_range("Invalid index in Box for the given Input size.");
    }

    // Set the corresponding bit in permuted_text
    permuted_text.set(bitToChange, newValue);
  }
  return permuted_text;
}
template <size_t Size>
void changeBit(bitset<Size> &bitset, const int bit_to_change,
               const bool new_value) {
  bitset.set(Size - 1 - bit_to_change, new_value);
}

/**
 * Splits a bitset into smaller segments of a specified size.
 * The order of the segments in the output matches the bit order in the original
 * bitset.
 *
 * @tparam size_of_segment The size of each segment in the resulting vector.
 * @tparam size_of_original The size of the original bitset to be split.
 * @param original The original bitset to be split into smaller segments.
 * @return A vector of bitsets, each of size `size_of_segment`, representing the
 * segments of the original bitset.
 *
 * @throws std::invalid_argument If the size of the original bitset is not
 * evenly divisible by the segment size.
 * @throws std::invalid_argument If the size of the original bitset is the same
 * as the segment size.
 */
template <size_t size_of_segment, size_t size_of_original>
vector<bitset<size_of_segment>>
splitBitset(const bitset<size_of_original> &original) {
  // Validate input: ensure split size divides original size
  if (size_of_original % size_of_segment != 0) {
    throw std::invalid_argument(
        "Original bitset size must be evenly divisible by SplitSize.");
  }
  if (size_of_original == size_of_segment) {
    throw std::invalid_argument(
        "Original size and segment size must not be the same");
  }

  // Precompute constants
  constexpr int number_of_segments{size_of_original / size_of_segment};
  constexpr unsigned long long mask{
      bitset<size_of_segment>().flip().to_ullong()};

  // Copy the original bitset to a modifiable value
  unsigned long long copy{original.to_ullong()};

  // Create a vector for segments
  vector<bitset<size_of_segment>> segments;

  // Extract segments using the mask
  for (int i{0}; i < number_of_segments; ++i) {
    segments.emplace_back(copy & mask);
    copy >>= size_of_segment;
  }
  // Reverse the order of segments to match the correct bit order
  reverse(segments.begin(), segments.end());
  return segments;
}

/**
 * Rotates the bits of a bitset by a specified number of positions,
 * accommodating both positive (right rotation) and negative (left rotation)
 * shifts.
 *
 * The rotation wraps around the bitset, so bits shifted out on one side
 * reappear on the opposite side. Negative values for `bits_to_rotate` result in
 * a left rotation, while positive values result in a right rotation. The number
 * of rotations is normalized to avoid redundant full rotations.
 *
 * @tparam Size The size of the bitset to rotate.
 * @param original The bitset to be rotated. This bitset is modified in place.
 * @param bits_to_rotate The number of positions to rotate the bits. Positive
 * values rotate the bits to the right, while negative values rotate the bits to
 * the left.
 * @return A reference to the rotated bitset (`original`) for convenience.
 *
 * @note The rotation is performed in place, modifying the input bitset
 * directly. If `bits_to_rotate` is a multiple of `Size`, the bitset remains
 * unchanged.
 */
template <size_t Size>
bitset<Size> &rotateBits(bitset<Size> &original, const int bits_to_rotate) {

  // We define this here to be able to use the % operator with ints and
  // accurately calculate modulus. Otherwise -1 % 5 returns -1 or conversion
  // error from downgrading size_t to int.
  const int size{static_cast<int>(original.size())};

  // To accommodate for negative shifts, find a number that is congruent with
  // bits_to_rotate and less than Size
  const int congruent_btr{((bits_to_rotate % size) + size) % size};

  // If full rotation return original
  if (congruent_btr == 0)
    return original;

  // Make copy of original
  bitset<Size> copy(original);

  // Shift copy-bits all the way to the left (11000)
  copy <<= size - congruent_btr;

  // Shift original bits to the right causing leftmost bits to be Zero (00111)
  original >>= congruent_btr;

  // XOR original and copy to merge them (11000 ^ 00111) = (11111)
  original ^= copy;

  return original;
}
/**
 * Concatenates two bitsets into a single bitset, where the first argument's
 * bits appear first in the resulting bitset, followed by the second argument's
 * bits.
 *
 * The order of the arguments is significant: the bits of the first bitset
 * (`B1`) will occupy the higher-order bits of the concatenated result, while
 * the bits of the second bitset (`B2`) will occupy the lower-order bits.
 *
 * @tparam S1 The size of the first bitset (B1).
 * @tparam S2 The size of the second bitset (B2).
 * @param B1 The first bitset, whose bits will appear first in the concatenated
 * result.
 * @param B2 The second bitset, whose bits will appear second in the
 * concatenated result.
 * @return A new bitset of size S1 + S2, containing the concatenation of `B1`
 * and `B2`.
 */
template <size_t S1, size_t S2>
bitset<S1 + S2> concatenateBitsets(const bitset<S1> &B1, const bitset<S2> &B2) {
  bitset<S1 + S2> result;

  // Copy bits from B2 (LSB-first) into the lower part of result
  for (size_t i = 0; i < S2; ++i) {
    result[i] = B2[i];
  }

  // Copy bits from B1 (LSB-first) into the upper part of result
  for (size_t i = 0; i < S1; ++i) {
    result[S2 + i] = B1[i];
  }

  return result;
}

} // namespace DataEncryptionStandard

void DataEncryptionStandard::DES::setKey(const uint64_t key) {

  // Save new key
  this->key = bitset<64>(key);

  // Generate new round keys based on new_key
  this->generateRoundKeys();
}

void DataEncryptionStandard::DES::generateRoundKeys() {

    // Make sure vector is clear
    roundKeys.clear();

  // Permute with PC1 and remove parity bits from key
  const bitset<56> pc1_key{boxPermute<56, 64>(kPermutedChoiceOneBox, this->key)};

  // Split key into 28-bit halves L0 and R0
  vector<bitset<28>> keys{splitBitset<28>(pc1_key)};

  int round{0};

  while (round < 16) {
    // In some specific rounds
    if (round == 0 || round == 1 || round == 8 || round == 15) {
      // Rotate the halves one bit to the left
      rotateBits(keys[0], -1);
      rotateBits(keys[1], -1);
    } else { // In all other rounds rotate the halves two bits to the left
      rotateBits(keys[0], -2);
      rotateBits(keys[1], -2);
    }

    // Join the two halves
    const bitset<56> concatenated_key{concatenateBitsets(keys[0], keys[1])};

    // Permute them
    const bitset<48> permuted_key{boxPermute<48, 56>(kPermutedChoiceTwoBox, concatenated_key)};

    // Save them as a round key
    roundKeys.emplace_back(permuted_key);

    // Move to next round
    round++;
  }
}

bitset<4> sBox (const bitset<6>& input, const vector<const vector<int>>& SBox) {
  bitset<2> row;
  bitset<4> column;

  row[0] = input[0];
  row[1] = input[5];

  column[0] = input[1];
  column[1] = input[2];
  column[2] = input[3];
  column[3] = input[4];

  // TODO: simplify this. This is ugly AF
  return {static_cast<unsigned long long>(SBox[row.to_ulong()][column.to_ulong()])};
}


namespace DataEncryptionStandard {
  template <size_t OutputSize, size_t InputSize>
  std::bitset<OutputSize> concatenateBitsets(const std::vector<std::bitset<InputSize>> &bitsets) {
    // Ensure the total size of the concatenated bitset matches OutputSize
    if (bitsets.size() * InputSize != OutputSize) {
      throw std::invalid_argument("Concatenation size must match the total size of the input bitsets.");
    }

    // Initialize the output bitset
    std::bitset<OutputSize> result;

    // Iterate through the input bitsets
    for (size_t i {0}; i < bitsets.size(); ++i) {
      // Shift the current bitset to its position in the result
      size_t shiftAmount {(bitsets.size() - i - 1) * InputSize};
      result |= (std::bitset<OutputSize>(bitsets[i].to_ullong()) << shiftAmount);
    }

    return result;
  }
}

bitset<32> DataEncryptionStandard::DES::f_function(const bitset<32>& input, const int& current_round) const {

  // Expand input
  const auto expanded_input {boxPermute<48>(kExpansionFunctionBox, input)};

  // XOR expanded input with round key
  // current_round is a class variable updated on every round of encryption and decryption
  const auto xored_input {expanded_input ^ this->roundKeys[current_round]};

  // Divide into 8 segments of 6-bits
  const auto split_segments {splitBitset<6>(xored_input)};
  auto resulting_segments {vector<bitset<4>>{}};

  // Use the S-boxes to find their 4-bit entry
  for (int i{0}; i < 8; ++i) {
    resulting_segments.emplace_back(sBox(split_segments[i], kSBoxes[i]));
  }

  // Merge segments, permute with P-Box, and return
  return boxPermute<32>(kPermutationBox, concatenateBitsets<32>(resulting_segments));
}

uint64_t DataEncryptionStandard::DES::encrypt(const uint64_t plaintext) {

  // Make sure current round is Zero
  current_round = 0;

  // Initial permutation
  const auto initial_permutation {boxPermute<64,64>(kInitialPermutationBox, bitset<64>{plaintext})};

  // Split into left and right
  const auto split_permutation {splitBitset<32>(initial_permutation)};
  auto previous_left {split_permutation[0]};
  auto previous_right {split_permutation[1]};
  auto new_left {bitset<32>{}};
  auto new_right {bitset<32>{}};

  // For each round i:
    // L_i = R_(i-1)
    // R_i = L_(i-1) XOR FeistelFunction(R_(i-1), k_i)
  do {
    new_left = previous_right;
    new_right = previous_left ^ f_function(previous_right, this->current_round);

    previous_left = new_left;
    previous_right = new_right;
  } while (current_round++ < 15);

  // Concatenate the two halves
  const auto post_round_text {concatenateBitsets(new_left, new_right)};

  // Permute them with the final permutation box
  const auto cipher_text {boxPermute<64>(kFinalPermutationBox, post_round_text)};

  // Return encrypted text as 64-bit unsigned integer
  return cipher_text.to_ullong();
}

