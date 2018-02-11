//Во всех задачах из следующего списка следует написать структуру данных, обрабатывающую команды push* и pop*.
//Формат входных данных.
//В первой строке количество команд n. n ≤ 1000000.
//Каждая команда задаётся как 2 целых числа: a b.
//a = 1 - push front
//a = 2 - pop front
//a = 3 - push back
//a = 4 - pop back
//Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
//Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
//Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”.
//Формат выходных данных.
//Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.
//
//Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.	

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define INIT_SIZE 10
#define FACTOR 2

using namespace std;

class Stack {
public:
    Stack();
    ~Stack();

    void Push(int val);
    int Pop();
    void Resize();
    bool Empty() const;
    
private:
    int* _data;
    size_t _size;
    size_t _top;

};

class Queue {
public:
    Queue();
    ~Queue();

    void Enqueue(int val);
    int Dequeue();
    
private:
    Stack _firstStack;
    Stack _secondStack;
};

Stack::Stack() {
    _size = INIT_SIZE;
    _data = (int*)calloc(_size, sizeof(int));
    _top = 0;
}

Stack::~Stack() {
    free(_data);
}

bool Stack::Empty() const {
    return (Stack::_top == 0);
}

void Stack::Push(int val) {
    if (_top >= _size)
        Resize();
    _data[_top] = val;
    _top ++;
}

int Stack::Pop() {
    if (_top == 0)
        return -1;
    _top --;
    return _data[_top];
}

void Stack::Resize() {
    _size *= FACTOR;
    _data = (int*)realloc(_data, _size * sizeof(int));
}

Queue::Queue() {
    _firstStack = new Stack;
    _secondStack = new Stack;
}

Queue::~Queue() {
    delete _firstStack;
    delete _secondStack;
}

void Queue::Enqueue(int val) {
    _firstStack.Push(val);
}

int Queue::Dequeue() {
    if (_secondStack._top)
        return _secondStack.Pop();
    
    if (_firstStack.Empty())
        return -1;
    
    while (_firstStack._top)
        _secondStack.Push(_firstStack.Pop());

    return _secondStack.Pop();
}

int main() {
    int n = 0;
    int val = 0;
    int com = 0;
    int num = 0;
    Queue queue;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> com >> num;
        switch (com) {
        case 2:
            val = queue.Dequeue();
            if (val != num) {
                cout << "NO";
                delete queue;
                return 0;
            }
            break;
        case 3:
            queue.Enqueue(num);
            break;
        }
    }
    cout << "YES";
    return 0;
}
