#include <iostream>

// Вузол списку
template<typename T>
struct Node {
    T data; // Дані вузла
    Node<T>* next; // Вказівник на наступний вузол
};

// Клас ітератора для проходження списку
template<typename T>
class Iterator {
private:
    Node<T>* current; // Поточний вузол ітератора

public:
    // Конструктор ітератора
    Iterator(Node<T>* node) : current(node) {}

    // Операція отримання даних поточного вузла
    T& operator*() const {
        return current->data;
    }

    // Переміщення ітератора до наступного вузла
    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    // Перевірка на рівність ітераторів
    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
};

// Шаблон класу однозв'язного списку
template<typename T>
class List {
private:
    Node<T>* head; // Вказівник на голову списку

public:
    // Конструктор списку
    List() : head(nullptr) {}

    // Додавання елемента в кінець списку
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>{ value, nullptr };
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Початок ітератора
    Iterator<T> begin() const {
        return Iterator<T>(head);
    }

    // Кінець ітератора
    Iterator<T> end() const {
        return Iterator<T>(nullptr);
    }
};

int main() {
    List<int> myList;

    // Додавання елементів у список
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // Проходження списку за допомогою ітератора
    std::cout << "List elements: ";
    for (Iterator<int> it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
