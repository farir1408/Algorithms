#include <iostream>
#include <cmath>

using namespace std;
//Нахождение ближайшего значения

int find(int *a, int key, int n){
    int left = 0;
    int right = n - 1;
    
    while (true){
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
            return mid;

        if ((a[mid] < key && key < a[mid + 1]) && mid != n - 1)
            return (abs(key - a[mid]) < abs(a[mid + 1] - key + 1)) ? mid : mid + 1;
        else {
            if (mid == n - 1)
                return mid;
            if (mid == 0)
                return 0;
        }

        if (a[mid] > key)
            right = mid;
        else
            left = mid + 1;
    }
}

int main(){
    int m, n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int *b = new int[m];
//    bool direction = a[0] > a[n-1];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++){
        int key = b[i];
        cout << find(a, key, n) << " ";
    };

    delete[] a;
    delete[] b;
}

