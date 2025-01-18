//
// Created by Jimmy on 1/17/25.
//

export module cipher;
import <cstdint>;
import <vector>;

export using ByteArray = std::vector<uint8_t>;

export class ICipher {
  public:

    // All ciphers will encrypt and decrypt
    virtual ByteArray encrypt(const ByteArray& plaintext) const = 0;
    virtual ByteArray decrypt(const ByteArray& ciphertext) const = 0;
    virtual ~ICipher() = default;
   };