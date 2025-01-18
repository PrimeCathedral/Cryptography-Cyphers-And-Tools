//
// Created by Jimmy on 1/18/25.
//
#include "bytearray.h"

#include "../external/boost/libs/multiprecision/include/boost/multiprecision/detail/assert.hpp"

std::vector<uint8_t> ByteArray::get_data() const {
    return this->data;
}

ByteArray & ByteArray::set_data(const std::vector<uint8_t> &data) {
    this->data = data;
    return *this;
}

ByteArray::ByteArray() : data(std::vector<uint8_t>{}) {}

ByteArray::ByteArray(const std::vector<uint8_t>& data) : data(data) {}

ByteArray::~ByteArray() = default;

bool ByteArray::getBit(const size_t pos) const {
    // Make sure position is within bounds
    if (pos > data.size() * 8 - 1) throw std::out_of_range("ByteArray::getBit");

    const size_t byte_index {pos / 8};  // Which byte
    const size_t bit_index {pos % 8};   // Which bit in that byte

    return (data[byte_index] >> (7 - bit_index) & 1);
}

ByteArray& ByteArray::setBit(const size_t pos, const bool value, const bool can_grow) {
    if (!can_grow && pos > data.size() * 8 - 1) throw std::out_of_range("ByteArray::setBit");

    const size_t byte_index {pos / 8}; // Which byte
    const size_t bit_index {pos % 8}; // Which bit in that byte

    if (byte_index >= data.size()) {
        // This case is when we want to modify bits beyond
        // the current range. It should allow for the array
        // to grow as needed. This functionality can be turned
        // off by setting can_grow = false in the function call.
        data.emplace_back(128 >> bit_index);
    } else {
        if (value) {
            // Create a 0b1, shift it to the bit we want to modify,
            // do an OR/AND comparison with the byte depending on
            // if the new value is 0 or 1.
            data[byte_index] |= (1 << (7 - bit_index));
        } else { // Set bit to 0
            data[byte_index] &= ~(1 << (7 - bit_index));
        }
    }

    return *this;
}

cpp_int ByteArray::to_cpp_int() const {

    cpp_int result {0};
    constexpr uint8_t mask {0b11111111};

    for (const auto& byte : data) {
        result <<= 8;
        result |= byte & mask;
    }

    return result;
}

bool ByteArray::operator[](const size_t pos) const {
    return getBit(pos);
}

bool ByteArray::operator==(const ByteArray& other) const {
    return data == other.data;
}