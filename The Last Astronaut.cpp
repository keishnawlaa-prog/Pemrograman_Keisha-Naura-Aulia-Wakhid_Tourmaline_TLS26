/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan K: ";
    cin >> K;

    if (N <= 0 || K < 2) {
        cout << "N harus > 0 dan K harus >= 2.\n";
        return 0;
    }

    int* circle = new int[N];
    for (int i = 0; i < N; i++) {
        circle[i] = i + 1;
    }

    int size = N;
    int pos = 0;

    int* eliminationOrder = new int[N];
    int elimCount = 0;

    while (size > 1) {

        pos = (pos + (K - 1)) % size;

        int eliminated = circle[pos];
        eliminationOrder[elimCount++] = eliminated;

        for (int i = pos; i < size - 1; i++) {
            circle[i] = circle[i + 1];
        }
        size--;

        if (size > 0 && pos >= size) {
            pos = 0;
        }

        if (eliminated % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }
        if (K < 2) K = 2;
    }

    cout << "\nUrutan astronot yang dieliminasi:\n";
    for (int i = 0; i < elimCount; i++) {
        cout << eliminationOrder[i];
        if (i != elimCount - 1) cout << " -> ";
    }
    cout << "\n";

    cout << "\nAstronot terakhir yang bertahan: " << circle[0] << "\n";

    delete[] circle;
    delete[] eliminationOrder;

    return 0;
}