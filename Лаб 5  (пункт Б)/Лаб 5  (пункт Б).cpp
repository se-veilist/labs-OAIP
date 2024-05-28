// n=8; поля структуры:марка автомобиля, максимальная скорость, год выпуска
// ключевое поле: год выпуска; M=10;
// схема хеширования:С произвольной адресацией
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
struct Car {
    string brand;
    int maxSpeed;
    int year;
};


int hashFunction(int key, int M) {
    return key % M;
}

int main() {
    setlocale (LC_ALL,"Ru");
    const int n = 8;
    const int M = 10;
    vector<Car> cars(n);

    
    for (int i = 0; i < n; ++i) {
        cout << "Введите марку автомобиля: ";
        cin >> cars[i].brand;
        cout << "Введите максимальную скорость: ";
        cin >> cars[i].maxSpeed;
        cout << "Введите год выпуска: ";
        cin >> cars[i].year;
    }

    
    list<Car> hashTable[M];

    
    for (int i = 0; i < n; ++i) {
        int hashValue = hashFunction(cars[i].year, M);
        hashTable[hashValue].push_back(cars[i]);
    }

    
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Марка автомобиля: " << cars[i].brand << ", Максимальная скорость: "
            << cars[i].maxSpeed << ", Год выпуска: " << cars[i].year << endl;
    }

    cout << "Хеш-таблица:" << endl;
    for (int i = 0; i < M; ++i) {
        cout << "Хеш " << i << ": ";
        for (Car car : hashTable[i]) {
            cout << "Марка автомобиля: " << car.brand << ", Максимальная скорость: "
                << car.maxSpeed << ", Год выпуска: " << car.year << " ";
        }
        cout << std::endl;
    }

   
    int searchYear;
    cout << "Введите год выпуска для поиска: ";
    cin >> searchYear;

    int searchHash = hashFunction(searchYear, M);
    bool found = false;
    for (Car car : hashTable[searchHash]) {
        if (car.year == searchYear) {
            found = true;
            cout << "Найдена структура с годом выпуска " << searchYear << ":" << endl;
            cout << "Марка автомобиля: " << car.brand << ", Максимальная скорость: "
                << car.maxSpeed << ", Год выпуска: " << car.year << endl;
            break;
        }
    }

    if (!found) {
        cout << "Структура с годом выпуска " << searchYear << " не найдена." << endl;
    }

    return 0;
}