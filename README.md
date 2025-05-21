# Frequency Analysis Caesar Cipher Breaker — Fully Working in C

> **Note:** At the time of writing the code, I originally planned to implement it in **C++**, but I realized it could be easily implemented in **simple C**, so I went ahead with that instead.

This program utilizes frequency analysis to break Caesar's cipher, a simple substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet. This brute force method tests all possible displacements and returns the most likely decryption of a text.

## How it Works

Caesar's cipher operates by shifting each letter in the plaintext by a fixed number of positions in the alphabet. Frequency analysis exploits the fact that certain letters or combinations of letters occur more frequently in a language, regardless of the text size. For instance, in English, 'e' is the most common letter.

This program takes an encrypted text as input and applies frequency analysis to identify the most likely decryption by analyzing the frequency distribution of letters in the encrypted text.

## Usage

1. Clone the repository or download the source code.
2. Ensure you have a C compiler installed on your system (e.g., GCC).
3. Compile the program: ```gcc caesarCipher.cpp```
4. Run the program: ./a.out
5. Provide the encrypted text when prompted.
6. The program will display the most likely decrypted text based on frequency analysis.

## Example

Suppose we have the following encrypted text:

```
Khoor zruog lv d vlpsoh sduw, xqghu pb frqilghqw rqh wklv xqlyhuvh. L dp qrw frph lq wkh edfnjurxqjv ri wklv sduw. Lq wklv sduw, l dp phqwdoo\#v lqwhusuhwhg lq wkdw wkh\#v dq xqlilhg \#uhvhdufk\# ri pb vxevwudwhv khu zlwk
```

Running the program with this text as input would yield:

```
Hello world is a simple text, under no encryption just this example. I am not come in the dictionary of this text. In this text, I illustrate#s repetition# of no occurring# in just
```
