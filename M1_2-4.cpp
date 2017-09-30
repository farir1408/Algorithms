#include <iostream>

//Считалка Джозефуса
using namespace std;

int josephus(int n, int k){
    return n > 1 ? (josephus(n - 1, k) + k - 1) % n + 1 : 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << "\n";
    return 0;
}
