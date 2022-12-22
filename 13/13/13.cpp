#include <iostream>
#include <Windows.h>

double minElem(double* arr, int N) {
    double min = arr[0];
    for (int i = 0; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    /* В одновимірному масиві, що складається з дійсних елементів, обчислити мінімальний елемент
масиву (функція); суму елементів масиву, розташованих між першим і останнім додатними елементами.
Перетворити масив таким чином, щоб спочатку розташовувалися всі елементи рівні нулю, а потім − всі
інші.*/
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int N;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> N;
    double* arr = new double[N];
    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    double min = minElem(arr, N);
    std::cout << "Мінімальним елементом масиву є " << min << std::endl;

    int firstPositive = 0;
    int lastPositive = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            firstPositive = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            lastPositive = i;
            break;
        }
    }
    double sum = 0;
    for (int i = firstPositive; i <= lastPositive; i++) {
        sum += arr[i];
    }
    std::cout << "Сума елементів між першим і останнім позитивними елементами дорівнює " << sum << std::endl;

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }
    double* arr2 = new double[N];
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            arr2[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0) {
            arr2[j] = arr[i];
            j++;
        }
    }
    std::cout << "Новий масив: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    delete[] arr2;
    return 0;
}