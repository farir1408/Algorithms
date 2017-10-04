#include <iostream>
#include <vector>
#define INIT_SIZE 10

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
    vector<char> buffer;
    Stack stack;
    bool key = true;
    char c = 0;

    while (true) {
        cin >> c; //костыль, что бы работало, в конце строки надо ввести 0
        if (c == '0')
            break;
        buffer.insert(buffer.end(), c);
        if (c == '(' || c == '[' || c == '{') {
            stack.Push(c);
        } else if (stack.top == 0) {
            buffer.insert(buffer.begin(), conformity(c));
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
            buffer.insert(buffer.end(), val);
        }
        copy(buffer.begin(), buffer.end(), ostreambuf_iterator<char>(cout));
    }
}
