#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Heap {
public:
    Heap(size_t size);
    ~Heap() {delete _Arr;}

    int GetSize() {return _Number;}
    int GetHead();
    void SiftUp(size_t);
    void SiftDown(size_t);
    void Add(int);

private:
    int* _Arr;
    size_t _SizeArr;
    size_t _Number;
    void __Swap(int, int);
};

int Heap::GetHead() {
    int tmp = _Arr[0];
    __Swap(0, --_Number);
    SiftDown(0);
    return tmp;
}

void Heap::SiftUp(size_t i) {
    while (i > 0) {
        size_t parent = (i - 1) / 2;

        if (_Arr[i] < _Arr[parent])
            __Swap(i, parent);
        i = parent;
    }
}

void Heap::SiftDown(size_t i) {
    size_t left = 2 * i + 1;
    size_t  right = 2 * i + 2;
    size_t smallest = i;

    if (left < _Number && _Arr[left] < _Arr[i])
        smallest = left;

    if (right < _Number && _Arr[right] < _Arr[smallest])
        smallest = right;

    if (smallest != i) {
        __Swap(i, smallest);
        SiftDown(smallest);
    }
}

void Heap::Add(int val) {
    _Arr[_Number] = val;
    SiftUp(_Number);
    _Number++;
}

void Heap::__Swap(int i, int j) {
    _Arr[i] = _Arr[i] ^ _Arr[j];
    _Arr[j] = _Arr[i] ^ _Arr[j];
    _Arr[i] = _Arr[i] ^ _Arr[j];
}

Heap::Heap(size_t size): _SizeArr(size), _Number(0) {
    _Arr = new int[_SizeArr];
}

int Calc(Heap* Mas) {
    int time = 0;
    int sum = 0;

    while (Mas->GetSize() > 1) {
        sum = Mas->GetHead();
        sum += Mas->GetHead();
        Mas->Add(sum);
        time += sum;
    }

    return time;
}

int main() {
    size_t N = 0;

    std::cin >> N;

    Heap Mas(N);

    for (size_t i = 0; i < N; i++) {
        int buf;
        std::cin >> buf;
        Mas.Add(buf);
    }

    std::cout << Calc(&Mas);
    return 0;
}
