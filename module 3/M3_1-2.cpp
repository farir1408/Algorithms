#include <iostream>
#include <string>
#include <vector>
#define INIT_SIZE 8
#define FIRST 31
#define SECOND 97
#define REHASH 3.0 / 4.0
#define MNO 2

using std::string;

inline int firstHash(const string& key, int bound) {
    int result = 0;

    for (size_t i = 0; i < key.length(); i++)
        result = (result * FIRST + key[i]) % bound;

    return result;
}

inline int secondHash(const string& key, int bound) {
    int result = 0;

    for (size_t i = 0; i < key.length(); i++)
        result = (result * SECOND + key[i]) % bound;

    return (2 * result + 1) % bound;
}


class HashTable {
public:
    explicit HashTable(): _table(INIT_SIZE, NULL), _size(0), _allocate(INIT_SIZE) {}
    ~HashTable();

    bool Has(const string& key) const;
    bool Add(const string& key);
    bool Remove(const string& key);

private:
    struct HashTableNode {
        string Key;
        bool isDeleted;
        explicit HashTableNode(const string& key): Key(key), isDeleted(false) {}
    };
    std::vector<HashTableNode*> _table;
    size_t _size;
    size_t _allocate;
    void __rehash();
};

//HashTable::HashTable(): _table(INIT_SIZE, NULL), _size(0), _allocate(INIT_SIZE) {}

HashTable::~HashTable() {
    for (size_t i = 0; i < _size; i++) {
        delete _table[i];
    }
}

bool HashTable::Has(const std::string &key) const {
    int hashOne = firstHash(key, _allocate);
    int hashTwo = secondHash(key, _allocate);
    size_t i = 0;

    while (_table[hashOne] != NULL and i < _allocate) {
        if (_table[hashOne]->Key == key and !_table[hashOne]->isDeleted)
            return true;

        hashOne = (hashOne + hashTwo) % _allocate;
        i++;
    }

    return false;
}

bool HashTable::Add(const std::string &key) {
    if ((float) _size / (float) _allocate >= REHASH)
        __rehash();

    int hashOne = firstHash(key, _allocate);
    int hashTwo = secondHash(key, _allocate);

    size_t i = 0;
    int deletedNodeIndex = -1;

    while (_table[hashOne] != NULL and i < _allocate) {
        if (_table[hashOne]->Key == key and !_table[hashOne]->isDeleted)
            return false;

        if (_table[hashOne]->isDeleted and deletedNodeIndex < 0)
            deletedNodeIndex = hashOne;

        hashOne = (hashOne + hashTwo) % _allocate;
        i++;
    }

    if (deletedNodeIndex >= 0) {
        _table[deletedNodeIndex]->Key = key;
        _table[deletedNodeIndex]->isDeleted = false;
    } else {
        _table[hashOne] = new HashTableNode(key);
    }

    _size++;
    return true;
}

bool HashTable::Remove(const std::string &key) {
    int hashOne = firstHash(key, _allocate);
    int hashTwo = secondHash(key, _allocate);

    size_t i = 0;
    while (_table[hashOne] != NULL and i < _allocate) {
        if (_table[hashOne]->Key == key and !_table[hashOne]->isDeleted) {
            _table[hashOne]->isDeleted = true;
            _size--;

            return true;
        }
        hashOne = (hashOne + hashTwo) % _allocate;
        i++;
    }

    return false;
}

void HashTable::__rehash() {
    size_t newSize = _allocate * MNO;
    std::vector<HashTableNode*> NewHashTable(newSize, NULL);

    for (size_t i = 0; i < _allocate; i++) {
        if (_table[i] != NULL and !_table[i]->isDeleted) {
            string data = _table[i]->Key;
            int newHashOne = firstHash(data, newSize);
            int newHashTwo = secondHash(data, newSize);
            size_t j = 0;

            while (NewHashTable[newHashOne] != NULL and j < newSize) {
                newHashOne = (newHashOne + newHashTwo) % newSize;
                j++;
            }

            NewHashTable[newHashOne] = new HashTableNode(data);
        }
    }

    _table = NewHashTable;
    _allocate = newSize;
}

int main() {
    char option;
    string keySequence;

    HashTable table;

    while (std::cin >> option >> keySequence) {
        bool result;

        switch (option) {
        case '+':
            result = table.Add(keySequence);
            break;
        case '-':
            result = table.Remove(keySequence);
            break;
        case '?':
            result = table.Has(keySequence);
            break;
        default:
            result = false;
        }

        std::cout << ((result) ? "OK" : "FAIL") << "\n";
    }

    return 0;
}
