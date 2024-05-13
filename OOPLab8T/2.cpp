#include <iostream>
#include <cstring>
#include <algorithm> // Для використання std::swap

// Функція для сортування методом "Вилучення"
void selectionSort(char arr[][10], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]); // Використовуємо std::swap для обміну масивами char
        }
    }
}

int main() {
    char arr[][10] = { "def", "abc", "ghi", "xyz", "mno" };
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
