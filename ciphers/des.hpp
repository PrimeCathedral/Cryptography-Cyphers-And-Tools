//
// Created by Jimmy on 1/7/25.
//

#ifndef DES_HPP
#define DES_HPP
#include <bitset>
#include <cstdint>
#include <vector>

using std::bitset;
using std::vector;

namespace DataEncryptionStandard {
class DES {

public:
  // Constructor
  explicit DES(uint64_t key);

  // Encryption function
  uint64_t encrypt(uint64_t plaintext);

  // Decryption function
  uint64_t decrypt(uint64_t ciphertext);

  void setKey(uint64_t key);

#ifndef UNIT_TESTING // This enables me to test private methods but still
                     // compiles correctly for user
private:
#endif

  // Member variables
  bitset<64> key;               // Original 64-bit key
  vector<bitset<48>> roundKeys; // 16 round keys (48-bit each)

  // Private functions
  void generateRoundKeys(); // Key scheduling

  // TODO: uint64_t feistelFunction(uint32_t R, uint64_t roundKey); // Feistel
  // function
  // TODO: uint64_t permute(uint64_t input, const int* table, int size); //
  // General permutation
  bitset<32> substitute(bitset<48> expanded_input);   // Substitution using S-boxes
};

// `extern` indicates that these variables are declared here but defined in the
// .cpp file.

/**
 * Initial Permutation (IP) Box
 * Takes a 64-bit block and permutes it according to elements in the table.
 */
extern const vector<int> IP;

/**
 * Final Permutation (FP) Box
 * Inverse to the Initial Permutation (IP).
 */
extern const vector<int> FP;

/**
 * Expansion (E) Box
 * Expands 32-bit blocks to 48 bits by duplicating certain bits.
 */
extern const vector<int> E;

/**
 * Permutation (P) Box
 * Shuffles a 32-bit block to increase diffusion.
 */
extern const vector<int> P;

/**
 * Permuted Choice 1 (PC1) Box
 * Transforms the original 64-bit key into a 56-bit key by permuting and
 * discarding 8 parity bits.
 */
extern const vector<int> PC1;

/**
 * Permuted Choice 2 (PC2) Box
 * Selects the 48-bit subkey for each round from the 56-bit key-schedule state.
 * Note: This permutation ignores 8 specific bits (e.g., 9, 18, 22, 25, 35, 38,
 * 43, 54).
 */
extern const vector<int> PC2;

/**
 * Substitution Boxes (S-Boxes)
 * A collection of 8 substitution boxes used in the Feistel function.
 * Each S-box maps a 6-bit input to a 4-bit output.
 */
extern const vector<const vector<const vector<int>>> S_BOXES;

/**
 * Shift Schedule
 * Determines how much to left-shift the key halves during key schedule
 * generation for each round.
 */
extern const vector<int> SHIFT_SCHEDULE;
} // namespace DataEncryptionStandard

#endif // DES_HPP
