#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1 Сортировка пузырьком (Bubble Sort) - шаблонная
// Сложность: O(n^2). Устойчивая
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Флаг оптимизации

        // Проходим по неотсортированной части массива
        for (int j = 0; j < n - i - 1; j++) {
            // Если текущий элемент больше следующего — меняем их местами
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Если за проход ни одного обмена не произошло, массив уже отсортирован
        if (!swapped) break;
    }
}

// 2 Сортировка вставками (Insertion Sort) - шаблонная
// Сложность: O(n^2). Устойчивая
template <typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i]; // Запоминаем текущий элемент
        int j = i - 1;

        // Сдвигаем элементы, которые больше key, на одну позицию вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Ставим key на освободившееся место
        arr[j + 1] = key;
    }
}

// 3 Сортировка выбором (Selection Sort) - шаблонная
// Сложность: O(n^2). Неустойчивая
template <typename T>
void selectionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Предполагаем, что первый — минимальный

        // Ищем реальный минимум в оставшейся части
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Если нашли минимум не на текущем месте, меняем их местами
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Вспомогательная функция для вывода массива на экран
template <typename T>
void printArray(const vector<T>& arr) {
    for (const T& item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Сортировка целых чисел (int)
    cout << " Тест 1: целые числа (int) " << endl;
    vector<int> numbers = { 5, 2, 9, 1, 5, 6 };

    cout << "Исходный:       "; printArray(numbers);

    // Создаем копии, чтобы протестировать каждую сортировку на одинаковых данных
    vector<int> num1 = numbers;
    vector<int> num2 = numbers;
    vector<int> num3 = numbers;

    bubbleSort(num1);
    cout << "Пузырьковая:    "; printArray(num1);

    insertionSort(num2);
    cout << "Вставками:      "; printArray(num2);

    selectionSort(num3);
    cout << "Выбором:        "; printArray(num3);
    cout << endl;

    // Сортировка дробных чисел (double)
    cout << " Тест 2: дробные числа (double) " << endl;
    vector<double> doubles = { 3.14, 1.41, 2.71, 0.58, 1.61 };

    cout << "Исходный:       "; printArray(doubles);

    bubbleSort(doubles);
    cout << "Пузырьковая:    "; printArray(doubles);
    cout << endl;

    // Сортировка строк (string)
    cout << "Тест 3: строки (string) " << endl;
    vector<string> words = { "яблоко", "банан", "арбуз", "вишня", "абрикос" };

    cout << "Исходный:       "; printArray(words);

    insertionSort(words);
    cout << "Вставками:      "; printArray(words);
    cout << endl;

    // Сортировка символов (char)
    cout << " Тест 4: символы (char) " << endl;
    vector<char> letters = { 'z', 'a', 'm', 'c', 'b' };

    cout << "Исходный:       "; printArray(letters);

    selectionSort(letters);
    cout << "Выбором:        "; printArray(letters);

    return 0;
}