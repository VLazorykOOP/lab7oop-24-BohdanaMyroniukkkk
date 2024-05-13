#include <iostream>
#include <algorithm>

template <typename T>
void swapMinMax(T arr[], int size) {
    if (size <= 1)
        return;

    // Знаходимо індекси максимального та мінімального елементів
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }

    // Переставляємо мінімальний елемент на перше місце
    std::swap(arr[0], arr[minIndex]);

    // Якщо максимальний елемент був на першому місці після перестановки мінімального, корегуємо індекс
    if (maxIndex == 0)
        maxIndex = minIndex;

    // Переставляємо максимальний елемент на друге місце
    std::swap(arr[1], arr[maxIndex]);
}

// Спеціалізація функції-шаблону для типу char*
template <>
void swapMinMax<char*>(char* arr[], int size) {
    if (size <= 1)
        return;

    // Знаходимо довжини рядків та їхні індекси
    int minIndex = 0;
    int maxIndex = 0;
    int minLength = strlen(arr[0]);
    int maxLength = strlen(arr[0]);
    for (int i = 1; i < size; ++i) {
        int length = strlen(arr[i]);
        if (length < minLength) {
            minLength = length;
            minIndex = i;
        }
        if (length > maxLength) {
            maxLength = length;
            maxIndex = i;
        }
    }

    // Переставляємо мінімальний елемент на перше місце
    std::swap(arr[0], arr[minIndex]);

    // Якщо максимальний елемент був на першому місці після перестановки мінімального, корегуємо індекс
    if (maxIndex == 0)
        maxIndex = minIndex;

    // Переставляємо максимальний елемент на друге місце
    std::swap(arr[1], arr[maxIndex]);
}

int main() {
    int intArr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    swapMinMax(intArr, 9);
    for (int i = 0; i < 9; ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    const char* charArr[] = { "apple", "banana", "orange", "strawberry", "grape" };
    swapMinMax(charArr, 5);
    for (int i = 0; i < 5; ++i) {
        std::cout << charArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
