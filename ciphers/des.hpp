//
// Created by Jimmy on 1/7/25.
//

#ifndef DES_HPP
#define DES_HPP
#include <vector>

namespace DataEncryptionStandard {
    class DES {
    public:
        // Constructor
        explicit DES(uint64_t key);

        // Encryption function
        uint64_t encrypt(uint64_t plaintext);

        // Decryption function
        uint64_t decrypt(uint64_t ciphertext);

    private:
        // Member variables
        uint64_t key;                          // Original 64-bit key
        std::vector<uint64_t> roundKeys;       // 16 round keys (48-bit each)

        // Private functions
        void generateRoundKeys();              // Key scheduling
        uint64_t initialPermutation(uint64_t input); // Apply the initial permutation (IP)
        uint64_t finalPermutation(uint64_t input);   // Apply the final permutation (FP)
        uint64_t feistelFunction(uint32_t R, uint64_t roundKey); // Feistel function
        uint64_t permute(uint64_t input, const int* table, int size); // General permutation
        uint32_t substitute(uint64_t input);   // Substitution using S-boxes
    };


    // `extern` indicates that these variables are declared here but defined in the .cpp file.

    /**
     * Initial Permutation (IP) Box
     * Takes a 64-bit block and permutes it according to elements in the table.
     */
    extern const std::vector<int> IP;

    /**
     * Final Permutation (FP) Box
     * Inverse to the Initial Permutation (IP).
     */
    extern const std::vector<int> FP;

    /**
     * Expansion (E) Box
     * Expands 32-bit blocks to 48 bits by duplicating certain bits.
     */
    extern const std::vector<int> E;

    /**
     * Permutation (P) Box
     * Shuffles a 32-bit block to increase diffusion.
     */
    extern const std::vector<int> P;

    /**
     * Permuted Choice 1 (PC1) Box
     * Transforms the original 64-bit key into a 56-bit key by permuting and discarding 8 parity bits.
     */
    extern const std::vector<int> PC1;

    /**
     * Permuted Choice 2 (PC2) Box
     * Selects the 48-bit subkey for each round from the 56-bit key-schedule state.
     * Note: This permutation ignores 8 specific bits (e.g., 9, 18, 22, 25, 35, 38, 43, 54).
     */
    extern const std::vector<int> PC2;

    /**
     * Substitution Boxes (S-Boxes)
     * A collection of 8 substitution boxes used in the Feistel function.
     * Each S-box maps a 6-bit input to a 4-bit output.
     */
    extern const std::vector<const std::vector<const std::vector<int>>> S_BOXES;

    /**
     * Shift Schedule
     * Determines how much to left-shift the key halves during key schedule generation for each round.
     */
    extern const std::vector<int> SHIFT_SCHEDULE;
}


#endif //DES_HPP
