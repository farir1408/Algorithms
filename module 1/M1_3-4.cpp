#include <iostream>
#include <cmath>

using namespace std;

int BinarySearch(int* arr, int left, int right,
                 int value, bool direction) {
    int mid = left + (right - left) / 2;
    
    if (right - left == 1)
        return value <= arr[left] ? left : right - 1;
    else if((value < arr[mid]) ^ direction)
        return BinarySearch(arr, left, mid, value, direction);
    else
        return BinarySearch(arr, mid, right, value, direction);
}

int FindInsert(int* arr, int count, int value) {
    if (count == 0)
        return -1;
    bool direction = arr[0] > arr[count-1];
    
    if (value > arr[count - 1])
       return count - 1;
    int prev = 0;
    int next = 1;
       
    while (true) {
        if (value <= arr[next]) {
            int point = BinarySearch(arr, prev, next, value, direction);
            return (abs(value - arr[point]) < abs(arr[point + 1] - value + 1)) ? point : point + 1;
        }
        if (next * 2 < count) {
            prev = next;
            next = next * 2;
        } else {
            next = count - 1;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    int* a = new int[n];
  
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m = 0;
    cin >> m;
    int* b = new int[m];
  
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++) {
        int value = b[i];
        cout << FindInsert(a, n, value) << " ";
    }
  
    delete[] a;
    delete[] b;
}
