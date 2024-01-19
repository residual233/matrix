//
// Created by Etienne on 19.01.2024.
//

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP
#include <vector>
#include <iostream>

template<typename element>
class matrix {
    std::vector<std::vector<element>> data;
    size_t size;
public:
    matrix() = delete; // Empty matricies are not sensible
    matrix(size_t size); // Square matrix constructor
    matrix(size_t sizeX, size_t sizeY); // Rectangular matrix constructor

    // Getter and setter
    std::vector<element>& operator[](size_t x); // Allow for access in synatx like matrix[x][y]

    // Size
    size_t getSize();
    size_t getSizeX();
    size_t getSizeY();
};


// Square constructor
template<typename element>
matrix<element>::matrix(size_t size) : size(size) {
    if(!size) std::cerr << "Created empty square matrix!\n";
    data.resize(size);
    for(auto &cols : data) {
        cols.resize(size);
    }
}

// Rectangular constructor
template<typename element>
matrix<element>::matrix(size_t sizeX, size_t sizeY) {
    if(!sizeX || !sizeY) std::cerr << "Created rectangular matrix with either size x = 0 or size y = 0!\n";
    data.resize(sizeX);
    for(auto &cols : data) {
        cols.resize(sizeY);
    }
}

// allow for getting and setting via syntax: matrix[x][y]
template<typename element>
std::vector<element> &matrix<element>::operator[](size_t x) {
    if(x < 0 || x >= data.size()) throw std::invalid_argument("Tried to access matrix out of bound in x dimension\n");
    return data[x];
}

// get size for square matricies
template<typename element>
size_t matrix<element>::getSize() {
    if(data.size() != data[0].size()) throw std::
}



#endif //MATRIX_MATRIX_HPP
