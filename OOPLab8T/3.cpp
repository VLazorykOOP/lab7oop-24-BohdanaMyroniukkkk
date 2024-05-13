#include <iostream>

// ���������� ����� �����
template<typename T>
class Queue {
private:
    // ������� ������������� �����
    T* elements;
    int capacity; // ����������� ������� �����
    int front; // ������� ������� ��������
    int rear; // ������� ���������� ��������
    int count; // ������� �������� � ����

public:
    // �����������
    Queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        elements = new T[capacity];
    }

    // ����������
    ~Queue() {
        delete[] elements;
    }

    // ������� ��� ��������� �������� � �����
    void enqueue(const T& item) {
        if (count == capacity) {
            std::cout << "����� �����������!" << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        elements[rear] = item;
        count++;
    }

    // ������� ��� ��������� �������� � �����
    T dequeue() {
        if (count == 0) {
            std::cout << "����� �������!" << std::endl;
            return T(); // ��������� �������� �� ������������� ��� ���� T
        }
        T item = elements[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    // ������� ��� ��������, �� � ����� ���������
    bool isEmpty() {
        return count == 0;
    }

    // ������� ��� ��������� ������� �������� � ����
    int size() {
        return count;
    }
};

int main() {
    // ��������� ����� � ���������� ����������
    Queue<std::string> stringQueue(5);

    // ��������� �������� � �����
    stringQueue.enqueue("One");
    stringQueue.enqueue("Two");
    stringQueue.enqueue("Three");

    // ��������� �������� � ����� �� ��������� ���� �� �����
    std::cout << "An element from the queue: " << stringQueue.dequeue() << std::endl;

    // ��������� ������� �������� � ����
    std::cout << "The number of items in the queue: " << stringQueue.size() << std::endl;

    return 0;
}
