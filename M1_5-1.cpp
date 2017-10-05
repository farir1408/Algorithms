#include <iostream>
#include <vector>
#define INIT_SIZE 10
#define FACTOR 2

using namespace std;

class Stack {
public:
    Stack();
    ~Stack();

    void Push(char value);
    char Pop();
    void Resize();
    size_t top;

private:
    char* data;
    size_t size;
};

Stack::Stack() {
    size = INIT_SIZE;
    data = new char[size];
    top = 0;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::Push(char value) {
    data[top] = value;
    top++;
}

char Stack::Pop() {
    if (top == 0)
        return -1;
    top--;
    return data[top];
}

void Stack::Resize() {
    size *= FACTOR;
    data = (char*)realloc(data, size * sizeof(char));
}

char conformity(char c) {
    switch (c) {
    case ')':
        return '(';
        break;
    case '}':
        return '{';
        break;
    case ']':
        return '[';
        break;
    }
    return 0;
}

char conformity_2(char c) {
    switch (c) {
    case '(':
        return ')';
        break;
    case '{':
        return '}';
        break;
    case '[':
        return ']';
        break;
    }
    return 0;
}


int main() {
//    vector<char> buffer;
    Stack stack;
    Stack firstStack;
    Stack secondStack;
    bool key = true;
    char c = 0;

    while (true) {
        c = static_cast<char>(cin.get());
        if (c == '\n')
            break;
        firstStack.Push(c);
//        buffer.insert(buffer.end(), c);
        if (c == '(' || c == '[' || c == '{') {
            stack.Push(c);
        } else if (stack.top == 0) {
            secondStack.Push(conformity(c));
//            buffer.insert(buffer.begin(), conformity(c));
        } else {
            char val = stack.Pop();
            if (val != conformity(c)) {
                cout << "IMPOSSIBLE";
                key = false;
                break;
            }
        }
    }

    if (key) {
        while (stack.top != 0) {
            char val = conformity_2(stack.Pop());
            firstStack.Push(val);
//            buffer.insert(buffer.end(), val);
        }
        while (secondStack.top != 0) {
            cout << secondStack.Pop();
        }
        while (firstStack.top != 0) {
            secondStack.Push(firstStack.Pop());
        }
        while (secondStack.top != 0)
            cout << secondStack.Pop();
//        copy(buffer.begin(), buffer.end(), ostreambuf_iterator<char>(cout));
    }
}
