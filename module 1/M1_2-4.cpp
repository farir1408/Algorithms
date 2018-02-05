#include <iostream>

//Считалка Джозефуса
using namespace std;

int josephus(int n, int k) {
    return n > 1 ? (josephus(n - 1, k) + k - 1) % n + 1 : 1;
}

//int josephus(int n, int k) {
//    int res = 1;
//    for (int i = 2; i <= n; ++i)
//        res = (res + k - 1) % i + 1;
//    return res;
//}

int main() {
    int n = 0;
    int k = 0;
    cin >> n >> k;
    
    cout << josephus(n, k) << "\n";
}
-
