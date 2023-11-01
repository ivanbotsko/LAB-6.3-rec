#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Функція для генерації масиву
std::vector<int> generateArray(int size, int min, int max, int currentIndex = 0, std::vector<int> array = {}) {
    if (currentIndex == size) {
        return array;
    }

    int randomValue = rand() % (max - min + 1) + min;
    array.push_back(randomValue);

    return generateArray(size, min, max, currentIndex + 1, array);
}

// Функція для виведення елементів масиву
std::vector<int> printElements(const std::vector<int>& array, int currentIndex = 0, std::vector<int> elements = {}) {
    if (currentIndex == array.size()) {
        return elements;
    }

    elements.push_back(array[currentIndex]);

    return printElements(array, currentIndex + 1, elements);
}

void printArrayRecursively(const std::vector<int>& array, int currentIndex = 0) {
    if (currentIndex == array.size()) {
        std::cout << "--------------------------------" << std::endl;
        return;
    }

    std::cout << array[currentIndex] << std::endl;
    printArrayRecursively(array, currentIndex + 1);
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Ініціалізувати генератор випадкових чисел

    std::vector<int> array = generateArray(10, 1, 100);
    std::cout << "Formed array: ";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i];
        if (i < array.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::vector<int> elements = printElements(array);
    std::cout << "--------------------------------" << std::endl;

    printArrayRecursively(elements);

    return 0;
}
