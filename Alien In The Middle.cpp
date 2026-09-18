/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

const int MAXLEN = 1000;

int letterValue(char c) {
    return c - 'A' + 1;
}

char valueToLetter(int v) {
    return (char)('A' + (v - 1));
}

void encodeMessage(const char* msg, char* result, int len) {
    result[0] = msg[0];
    for (int i = 1; i < len; i++) {
        int prevVal = letterValue(msg[i - 1]);
        int curVal  = letterValue(msg[i]);
        int shifted = ((curVal - 1 + prevVal) % 26) + 1;
        result[i] = valueToLetter(shifted);
    }
    result[len] = '\0';
}

int main() {
    char input[MAXLEN];

    cout << "Masukkan pesan: ";
    cin >> input;

    int len = 0;
    while (input[len] != '\0') len++;

    for (int i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 'a' + 'A';
        }
    }

    char result[MAXLEN];
    encodeMessage(input, result, len);

    cout << "\nPesan asli  : " << input << "\n";
    cout << "Pesan sandi : " << result << "\n";

    return 0;
}