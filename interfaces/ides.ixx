//
// Created by Jimmy on 1/17/25.
//

export module ides;

import cipher;
import <cstdint>;
import <bitset>;
import <vector>;

export class IDES : public ICipher {
  public:
  virtual ByteArray encrypt(const ByteArray& plaintext) const override;
  virtual ByteArray decrypt(const ByteArray& ciphertext) const override;
  virtual void setKey(uint64_t key);
  virtual ~IDES() = default;

  virtual void generateRoundKeys();
  virtual ByteArray f_function(const ByteArray& input, const int& current_round) const;

};