# Substitution Cipher Tool

### Objective
Encrypt and decrypt messages by shifting each character's ASCII value using a key.

### How it works
- Accepts a string and an integer key
- Uses a pointer to walk through the string in memory
- Shifts each character's ASCII value by the key to encrypt or reverse it to decrypt

### How to run
gcc cipher.c -o ciphertool
./ciphertool
### Example
Choice: 1
Enter message: hello
Enter key: 3
Encrypted: khoor

Choice: 2
Enter message: khoor
Enter key: 3
Decrypted: hello
---
