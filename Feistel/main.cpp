#include <iostream>
#include <bitset>
#include <vector>

const int NUM_ROUNDS = 16;
const uint64_t FEISTEL_KEY = 0x0F0F0F0F0F0F0F0F;

uint32_t feistelTransformation(uint32_t right, uint64_t roundKey) {
    return right ^ static_cast<uint32_t>(roundKey);
}

void performFeistelRound(uint32_t& left, uint32_t& right, uint64_t roundKey) {
    uint32_t temp = left;
    left = right;
    right = temp ^ feistelTransformation(right, roundKey);
}

void encryptWithFeistel(uint64_t& block, uint64_t key) {
    uint32_t left = block >> 32;
    uint32_t right = static_cast<uint32_t>(block);

    for (int round = 0; round < NUM_ROUNDS; ++round) {
        performFeistelRound(left, right, key);
        key = (key << 1) | (key >> 63);
    }

    block = (static_cast<uint64_t>(right) << 32) | left;
}

void decryptWithFeistel(uint64_t& block, uint64_t key) {
    uint32_t left = block >> 32;
    uint32_t right = static_cast<uint32_t>(block);

    for (int round = 0; round < NUM_ROUNDS; ++round) {
        key = (key >> 1) | (key << 63);
        performFeistelRound(right, left, key);
    }

    block = (static_cast<uint64_t>(right) << 32) | left;
}

int main() {
    std::string inputText = "exampleplaintext";

    while (inputText.size() % 8 != 0) {
        inputText.push_back('\0');
    }

    std::vector<uint64_t> blocks;

    for (size_t i = 0; i < inputText.size(); i += 8) {
        uint64_t block = 0;
        for (int j = 0; j < 8; ++j) {
            block |= static_cast<uint64_t>(inputText[i + j]) << (8 * j);
        }
        blocks.push_back(block);
    }

    for (uint64_t& block : blocks) {
        encryptWithFeistel(block, FEISTEL_KEY);
    }

    for (uint64_t& block : blocks) {
        decryptWithFeistel(block, FEISTEL_KEY);
    }

    std::string encryptedText;
    for (uint64_t block : blocks) {
        for (int j = 0; j < 8; ++j) {
            encryptedText.push_back(static_cast<char>(block >> (8 * j)));
        }
    }

    std::cout << "Original Text: " << inputText << std::endl;
    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::cout << "Decrypted Text: " << inputText << std::endl;

    return 0;
}
