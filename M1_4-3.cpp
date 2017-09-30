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
    bool Empty();
    size_t top;
    bool init = false;
private:
    int *data;
    size_t size;

};

class Queue {
public:
    Queue();
    ~Queue();

    void Enqueue(int val);
    int Dequeue();
private:
    Stack *firstStack;
    Stack *secondStack;
};

Stack::Stack() {
    size = INIT_SIZE;
    data = (int*)calloc(size, sizeof(int));
    top = 0;
    init = true;
}

Stack::~Stack() {
    free(data);
}

bool Stack::Empty() {
    return (!init && Stack::top == 0);
}

void Stack::Push(int val) {
    if (top >= size)
        Resize();
    data[top] = val;
    top ++;
}

int Stack::Pop() {
    if (top == 0)
        return -1;
    top --;
    return data[top];
}

void Stack::Resize() {
    size *= FACTOR;
    data = (int*)realloc(data, size * sizeof(int));
}

Queue::Queue() {
    firstStack = new Stack;
    secondStack = new Stack;
}

Queue::~Queue() {
    delete firstStack;
    delete secondStack;
}

void Queue::Enqueue(int val) {
    firstStack->Push(val);
}

int Queue::Dequeue() {
    if (secondStack->top)
        return secondStack->Pop();
    else {
        if (firstStack->Empty())
            return -1;
        else {
            while (firstStack->top)
                secondStack->Push(firstStack->Pop());
            return secondStack->Pop();
        }
    }
}

int main()
{
    int n, val, com, num;
    Queue *queue = new Queue;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com >> num;
        switch (com) {
        case 2:
            val = queue->Dequeue();
            if (val != num) {
                cout << "NO";
                delete queue;
                return 0;
            }
            break;
        case 3:
            queue->Enqueue(num);
            break;
        }
    }
    cout << "YES";
    delete queue;
    return 0;
}
