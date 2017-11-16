#include <iostream>
#include <vector>
#define INIT_SIZE 10
#define FACTOR 2

using namespace std;

class Stack {
public:
    Stack();
    ~Stack();

    Stack &Push(char value);
    char Pop();

    bool empty() const {
        return 0 == _top;
    }

protected:
    void Resize(size_t newSize);

private:
    static auto constexpr INIT_SIZE = 10;
    static auto constexpr FACTOR = 2;

    size_t _size;
    size_t _top;

    char* _data;
};

Stack::Stack():
    _size(INIT_SIZE),
    _top(0),
    _data(new char[_size]) {}

Stack::~Stack() {
    delete[] _data;
}

Stack &Stack::Push(char value) {
    if (_top >= _size)
        Resize(_size * FACTOR);

    _data[_top++] = value;

    return *this;
}

char Stack::Pop() {
    if (0 == _top)
        return 0;

    return _data[--_top];
}

void Stack::Resize(size_t newSize) {
    auto newData = new char[newSize];
    std::copy(_data, _data + _size, newData);

    delete[] _data;

    _data = newData;
    _size = newSize;
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
    Stack stack;
    Stack firstStack;
    Stack secondStack;
    
    bool key = true;
    char c = 0;

    while (true) {
        c = static_cast<char>(cin.get());
        if (c == '\n')
            continue;
        
        if (c == EOF)
            break;
        
        firstStack.Push(c);
        if (c == '(' || c == '[' || c == '{') {
            stack.Push(c);
        } else if (stack.top == 0) {
            secondStack.Push(conformity(c));
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
        }
        
        while (secondStack.top != 0) {
            cout << secondStack.Pop();
        }
        
        while (firstStack.top != 0) {
            secondStack.Push(firstStack.Pop());
        }
        
        while (secondStack.top != 0)
            cout << secondStack.Pop();
    }
    
    return 0;
}
