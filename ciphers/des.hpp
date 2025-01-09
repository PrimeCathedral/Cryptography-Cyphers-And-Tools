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

    // Constants (e.g., IP, FP, E, S-boxes, P, PC-1, PC-2)
    const std::vector<int> IP;
    const std::vector<int> FP;
    const std::vector<int> E;
    const std::vector<int> P;
    const std::vector<int> PC1;
    const std::vector<int> PC2;
    const std::vector<const std::vector<const std::vector<int>>> S_BOXES;
    const std::vector<int> SHIFT_SCHEDULE;
}


#endif //DES_HPP
