#include <iostream>

//high pyramid
using namespace std;

int f_piramids(int **table, int blocks) {
    int result = 0; // k - number of cubes, m - number of cubes at the bottom of pyramid
    for (int k = 1; k <= blocks; k++) {
        
        for (int m = 1; m <= blocks; m++) {
            if (k - m == 0) {
                table[k][m] = 1;
            } else {
                table[k][m] = 0;
                
                for (int r = 1; r <= m; r++) {
                    if (k - m > 0)
                        table[k][m] += table[k - m][r];
                }
            }
        }
    }
    
    for (int i = 1; i <= blocks; i++)
        result += table[blocks][i];
    
    return result;
}

int main() {
    int n = 0;
    cin >> n;

    int **table = new int*[n + 1];
    for (int i = 0; i <= n; i++)
        table[i] = new int[n + 1];

    cout << f_piramids(table, n);

    for (int i = 0; i <= n; i++)
        delete[] table[i];
    
    delit[] table;
}
