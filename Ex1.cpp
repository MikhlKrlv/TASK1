#include <iostream>

// Функція для обчислення суми елементів масиву з непарними номерами
double sumOddIndexElements(double arr[], int n) {
    double sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

// Функція для обчислення суми елементів масиву, розташованих між першим і останнім від’ємними елементами
double sumBetweenNegatives(double arr[], int n) {
    int firstNegative = -1, lastNegative = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (firstNegative == -1) firstNegative = i;
            lastNegative = i;
        }
    }
    double sum = 0;
    if (firstNegative != -1 && lastNegative != -1) {
        for (int i = firstNegative + 1; i < lastNegative; i++) {
            sum += arr[i];
        }
    }
    return sum;
}

// Функція для стиснення масиву, видаливши з нього всі елементи, модуль яких не перевищує 1
void compressArray(double arr[], int& n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) > 1) {
            arr[j++] = arr[i];
        }
    }
    while (j < n) {
        arr[j++] = 0;
    }
}

int main() {
    int n;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> n;
    double arr[n];
    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << "Сума елементів масиву з непарними номерами: " << sumOddIndexElements(arr, n) << std::endl;
    std::cout << "Сума елементів масиву, розташованих між першим і останнім від’ємними елементами: " << sumBetweenNegatives(arr, n) << std::endl;
    compressArray(arr, n);
    std::cout << "Масив після стиснення: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
