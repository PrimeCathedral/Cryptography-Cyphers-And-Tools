//
// Created by Jimmy on 1/18/25.
//
#ifndef BYTEARRAY_H
#define BYTEARRAY_H
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

struct ByteArray {

    // ByteArray
    std::vector<uint8_t> data;

    // Getters
    std::vector<uint8_t> get_data() const;

    // Setters
    ByteArray& set_data(const std::vector<uint8_t>& data);

    // Constructors
    ByteArray();
    explicit ByteArray(const std::vector<uint8_t>& data);
    ~ByteArray();

    // Methods
    [[nodiscard]] bool getBit(size_t pos) const;
    ByteArray& setBit(size_t pos, bool value, bool can_grow = true);
    [[nodiscard]] cpp_int to_cpp_int() const;
    bool is_divisible_by(int divisor) const;
    std::vector<ByteArray> splitInto(int desired_segments) const;

    // Operator overloads
    bool operator[](size_t pos) const;
    bool operator==(const ByteArray& other) const;

};

#endif