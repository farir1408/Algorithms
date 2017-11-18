#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>


bool cmpStr(const std::string &str1, const std::string &str2) {
    size_t size = 0;
    size_t k = 0;

    size = str1.length() <= str2.length() ? str1.length() : str2.length();

    for (size_t i = 0; i < size; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] < str2[i])
                return false;
            else
                return true;
        } else {
            k++;
        }
    }

    if (k == size && size == str1.length())
        return false;

    return true;
}

int BinarySearchStr(std::string* &stringArr, size_t left,
                    size_t right, const std::string &value) {

    if (cmpStr(value, stringArr[right]))
        return right + 1;

    if (!cmpStr(value, stringArr[0]))
        return 0;

    size_t mid = left + (right - left) / 2;

    if (right - left == 1)
        return right;

    if (!cmpStr(value, stringArr[mid]))
        return BinarySearchStr(stringArr, left, mid, value);
    else
        return BinarySearchStr(stringArr, mid, right, value);
}

void sortString(std::string* stringArr, size_t n) {

    for (size_t i = 1; i < n; i++) {
        int right = i - 1;
        int pointer = BinarySearchStr(stringArr, 0, right, stringArr[i]);
        std::string tmp = std::move(stringArr[i]);

        int j = i - 1;
        for (; j >= pointer; --j) {
            stringArr[j + 1] = std::move(stringArr[j]);
        }
        stringArr[pointer] = std::move(tmp);
//        if (pointer < i) {
//            memmove(&stringArr[pointer + 1], &stringArr[pointer], (i - pointer) * sizeof(char));
//            stringArr[pointer] = std::move(tmp);
//        }
    }
}

int main() {
    size_t n = 0;

    std::cin >> n;

    auto stringArr = new std::string[n];

    for (size_t i = 0; i < n; i++) {
        std::cin >> stringArr[i];
    }

    sortString(stringArr, n);

    for (size_t i = 0; i < n; i++) {
        std::cout << stringArr[i] << '\n';
    }

    delete[] stringArr;
}