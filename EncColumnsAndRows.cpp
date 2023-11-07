#include "EncColumnsAndRows.h"
#include <vector>
#include <iostream>

EncColumnsAndRows::EncColumnsAndRows(const std::string& key) : key(key) {}

void EncColumnsAndRows::encode(std::string& plaintext) const {
    int numRows = plaintext.length()/2;
    int numCols = 2;

    std::vector<std::vector<char>> matrix(numRows, std::vector<char>(numCols, ' '));

    int k = 0;
    for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
            if (k < plaintext.length()) {
                matrix[i][j] = plaintext[k++];
            }
        }
    }

    plaintext = "";
    for (int j = 0; j < numCols; ++j) {
        for (int i = 0; i < numRows; ++i) {
            if (matrix[i][j] != ' ') {
                plaintext += matrix[i][j];
            }
        }
    }
}


void EncColumnsAndRows::decode(std::string& ciphertext) const {
    int numRows = ciphertext.length() / 2;
    int numCols = 2;

    std::vector<std::vector<char>> matrix(100, std::vector<char>(100, ' '));

    int k = 0;
    for (int j = 0; j < numCols; ++j) {
        for (int i = 0; i < numRows; ++i) {
            if (k < ciphertext.length()) {
                matrix[i][j] = ciphertext[k++];
             
            }
        }
    }
    
    std::string plaintext = "";
    for (int i = 0; i < numRows; ++i)  {
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] != ' ') {
                plaintext += matrix[i][j];
            }
        }
    }

    ciphertext = plaintext; 
}

void EncColumnsAndRows::encodeDecode(std::string& s) {
    std::string originalText = s; 

    encode(s);
    std::cout << "Encoded string: " << s << std::endl;

    decode(s);

    std::cout << "Decoded string: " << s << std::endl;
}