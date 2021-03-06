//Дан массив целых чисел A[0..n). 
//Не используя других массивов переставить элементы массива A  в обратном порядке за O(n).

#include <iostream>

//Разворачивание массива
using namespace std;

void reverse(int *a, int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tmp;
    }
}

int main() {
    int n = 0;
    cin >> n;
    int* a = new int[n];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    reverse(a, n);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    delete[] a;
}
