#include <iostream>

// ����� ������
template<typename T>
struct Node {
    T data; // ��� �����
    Node<T>* next; // �������� �� ��������� �����
};

// ���� ��������� ��� ����������� ������
template<typename T>
class Iterator {
private:
    Node<T>* current; // �������� ����� ���������

public:
    // ����������� ���������
    Iterator(Node<T>* node) : current(node) {}

    // �������� ��������� ����� ��������� �����
    T& operator*() const {
        return current->data;
    }

    // ���������� ��������� �� ���������� �����
    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    // �������� �� ������ ���������
    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
};

// ������ ����� ������'������ ������
template<typename T>
class List {
private:
    Node<T>* head; // �������� �� ������ ������

public:
    // ����������� ������
    List() : head(nullptr) {}

    // ��������� �������� � ����� ������
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

    // ������� ���������
    Iterator<T> begin() const {
        return Iterator<T>(head);
    }

    // ʳ���� ���������
    Iterator<T> end() const {
        return Iterator<T>(nullptr);
    }
};

int main() {
    List<int> myList;

    // ��������� �������� � ������
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // ����������� ������ �� ��������� ���������
    std::cout << "List elements: ";
    for (Iterator<int> it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
