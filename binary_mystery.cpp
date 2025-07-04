#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string xor_rotate_cipher(const string& text, int key, bool encrypt) {
    string result = text;
    
    // Apply XOR with key to each character
    for (char& c : result) {
        c ^= key;
    }
    
    // Rotate right during encryption, left during decryption
    if (!result.empty()) {
        if (encrypt) {
            // Rotate right by 1
            rotate(result.rbegin(), result.rbegin() + 1, result.rend());
        } else {
            // Rotate left by 1
            rotate(result.begin(), result.begin() + 1, result.end());
        }
    }
    
    return result;
}

int main() {
    string plaintext = "Ishtiak";
    int key = 42;
    
    cout << "Original: " << plaintext << endl;
    
    string ciphertext = xor_rotate_cipher(plaintext, key, true);
    cout << "Encrypted: " << ciphertext << endl;
    
    string decrypted = xor_rotate_cipher(ciphertext, key, false);
    cout << "Decrypted: " << decrypted << endl;
    
    return 0;
}