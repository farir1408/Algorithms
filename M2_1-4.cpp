#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>


bool cmpStr(char* str1, char* str2) {
    size_t size = 0;

    size = sizeof(str1) <= sizeof(str2) ? sizeof(str1) : sizeof(str2);

    for (size_t i = 0; i < size; i++) {
        if (str1[i] >= str2[i])
            return false;
    }
    return true;
}

int BinarySearchStr(char** stringArr, int left, int right, char* value) {

    if (!cmpStr(value, stringArr[right]))
        return right + 1;

    if (cmpStr(value, stringArr[0]))
        return 0;

    int mid = left + (right - left) / 2;

    if (right - left == 1)
        return right;

    if (cmpStr(value, stringArr[mid]))
        return BinarySearchStr(stringArr, left, mid, value);
    else
        return BinarySearchStr(stringArr, mid, right, value);
}

void sortString(char** stringArr, int n) {

    for (int i = 1; i < n; i++) {
        char* tmp = stringArr[i];
        int right = i -1;
        int pointer = BinarySearchStr(stringArr, 0, right, stringArr[i]);

        if (pointer < i) {
            memmove(&stringArr[i + pointer + 1], &stringArr[i + pointer], (i - pointer) * sizeof(char));
            stringArr[pointer] = tmp;
        }
    }
}

int main() {
    int n = 0;

    std::cin >> n;

    char** stringArr = new char*[n];

    for (int i = 0; i <= n; i++) {
        stringArr[i] = new char[255];
        std::cin.getline(stringArr[i], 255);
    }

    sortString(stringArr, n);

    for (int i = 0; i < n; i++) {
        std::cout << stringArr[i] << '\n';
    }
}
