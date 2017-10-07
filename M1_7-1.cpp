#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX_SIZE 100000

using namespace std;

int tower(int* mas, int* power, int n) {
    sort(mas, mas + n);
    sort(power, power + n);

    long allMass = mas[0];
    int high = 1;
    for (int i = 1; i < n; i++) {
        if (power[i] >= allMass) {
            allMass += mas[i];
            high++;
        }
    }
    return high;
}

int main() {
    int* mas = new int[MAX_SIZE];
    int* power = new int[MAX_SIZE];
    int n = 0;
    int j = 0;

    while (cin >> mas[n] >> power[j]) {
        n++;
        j++;
    }

    cout << tower(mas, power, n);
    delete[] mas;
    delete[] power;
}
