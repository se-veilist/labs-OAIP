//n=8; диапазон:53000-78000
//M=10; Схема хеширования: На основе связанных списков
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int hashFunction(int key, int M) {
    return key % M;
}

int main() {
    setlocale(LC_ALL, "Ru");
    const int n = 8;
    const int M = 10;
    vector<int> array = { 55000, 60000, 65000, 70000, 71000, 72000, 73000, 78000 };
    list<int> hashTable[M];

    
    for (int i = 0; i < n; ++i) {
        int hashValue = hashFunction(array[i], M);
        hashTable[hashValue].push_back(array[i]);
    }

    
    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Хеш-таблица:" << endl;
    for (int i = 0; i < M; ++i) {
        cout << "Хеш " << i << ": ";
        for (int element : hashTable[i]) {
            cout << element << " ";
        }
        cout << endl;
    }

    
    int searchElement = 71000;
    int searchHash = hashFunction(searchElement, M);
    bool found = false;
    for (int element : hashTable[searchHash]) {
        if (element == searchElement) {
            found = true;
            break;
        }
    }

    
    if (found) {
        cout << "Элемент " << searchElement << " найден в хеш-таблице." << endl;
    }
    else {
        cout << "Элемент " << searchElement << " не найден в хеш-таблице." << endl;
    }

    return 0;
}