#include <iostream>

// Визначення класу черги
template<typename T>
class Queue {
private:
    // Внутрішнє представлення черги
    T* elements;
    int capacity; // максимальна місткість черги
    int front; // позиція першого елемента
    int rear; // позиція останнього елемента
    int count; // кількість елементів у черзі

public:
    // Конструктор
    Queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        elements = new T[capacity];
    }

    // Деструктор
    ~Queue() {
        delete[] elements;
    }

    // Функція для додавання елемента у чергу
    void enqueue(const T& item) {
        if (count == capacity) {
            std::cout << "Черга переповнена!" << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        elements[rear] = item;
        count++;
    }

    // Функція для видалення елемента з черги
    T dequeue() {
        if (count == 0) {
            std::cout << "Черга порожня!" << std::endl;
            return T(); // Повертаємо значення за замовчуванням для типу T
        }
        T item = elements[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    // Функція для перевірки, чи є черга порожньою
    bool isEmpty() {
        return count == 0;
    }

    // Функція для отримання кількості елементів у черзі
    int size() {
        return count;
    }
};

int main() {
    // Створення черги зі строковими значеннями
    Queue<std::string> stringQueue(5);

    // Додавання елементів у чергу
    stringQueue.enqueue("One");
    stringQueue.enqueue("Two");
    stringQueue.enqueue("Three");

    // Видалення елемента з черги та виведення його на екран
    std::cout << "An element from the queue: " << stringQueue.dequeue() << std::endl;

    // Виведення кількості елементів у черзі
    std::cout << "The number of items in the queue: " << stringQueue.size() << std::endl;

    return 0;
}
