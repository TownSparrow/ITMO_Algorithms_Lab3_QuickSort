#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include <limits>
#include <numeric>
#include <fstream>
#include "QuickSort.h"
#define ANKERL_NANOBENCH_IMPLEMENT
#include "../nanobench/src/include/nanobench.h"

using namespace std;
using namespace chrono;

// Генерация случайного вектора
vector<int> GenerateRandomVector(int size, int randomNumber) {
  mt19937 gen(randomNumber);
  uniform_int_distribution<int> distance(0, 100000);
  vector<int> data(size);
  generate(data.begin(), data.end(), [&]() { return distance(gen); });
  return data;
}

// Генерация вектора, отсортированного в обратном порядке
vector<int> GenerateReversedSortedVector(int size) {
  vector<int> data(size);
  iota(data.rbegin(), data.rend(), 0);
  return data;
}

// Функция для измерения времени выполнения
template <typename Func>
double TimeMeasure(Func&& func) {
  auto start = high_resolution_clock::now();
  func();
  auto end = high_resolution_clock::now();
  return duration<double>(end - start).count();
}

// Сохранение результатов
void SaveResults(const string fileName, const vector<int>& sizes,const vector<double>& reversedInsertionSort, const vector<double>& reversedQuickSort) {
  ofstream file(fileName);
  if (!file.is_open()) {
    cerr << "Cannot open .csv file\n";
    return;
  }
  file << "Size,reversed_InsertionSortTimes,reversed_QuickSortTimes\n";
  for (size_t i = 0; i < sizes.size(); ++i) {
    file << sizes[i] << "," << reversedInsertionSort[i] << "," << reversedQuickSort[i] << "\n";
  }
  // file.close(); // хе-хе, лишнее действие
}

// Тестирование сортировки вставками
void InsertionSort_Test(vector<int> dataVector) {
  vector<int> dataVectorCopy = dataVector;
  InsertionSort(dataVectorCopy.data(), dataVectorCopy.data() + dataVectorCopy.size(), less<int>());
}

// Тестирование быстрой сортировки
void QuickSort_Test(vector<int> dataVector) {
  vector<int> dataVectorCopy = dataVector;
  QuickSort(dataVectorCopy.data(), dataVectorCopy.data() + dataVectorCopy.size(), less<int>());
}

// Запуск тестов с использованием chrono
/*
void ChronoTests() {
  vector<int> arraySizes;
  vector<double> reversedInsertionSortTimes;
  vector<double> reversedQuickSortTimes;

  int tries = 10000;
  double time;

  vector<int> dataVector;

  for (int i = 2; i <= 75; i += 1) {
    arraySizes.push_back(i);
  }

  for (int currentSize : arraySizes) {
    cout << "Size: " << currentSize << "\n";
    dataVector = GenerateReversedSortedVector(currentSize);

    // Генерация отсортированного вектора данных через вставку
    time = 0;
    for (int i = 0; i < tries; ++i) {
      time += TimeMeasure([&]() {InsertionSort_Test(dataVector); });
    }
    reversedInsertionSortTimes.push_back(time / tries);

    // Генерация отсортированного вектора данных через Quick Sort
    time = 0;
    for (int i = 0; i < tries; ++i) {
      time += TimeMeasure([&]() {QuickSort_Test(dataVector); });
    }
    reversedQuickSortTimes.push_back(time / tries);
  }

  // Сохранение результатов
  SaveResults("chrono-tests.csv", arraySizes, reversedInsertionSortTimes, reversedQuickSortTimes);

  dataVector.clear();
}
*/

// Запуск тестов с использованием nanobench
void NanobenchTests() {
  vector<int> arraySizes;
  vector<double> randomInsertionSortTimes;
  vector<double> randomQuickSortTimes;
  vector<double> reversedInsertionSortTimes;
  vector<double> reversedQuickSortTimes;

  random_device randomDevice;
  int randomNumber = randomDevice();

  vector<int> dataVector;
  int warmups = 1000; 
  int epochs = 10000;
  ankerl::nanobench::Bench bench;

  for (int i = 2; i <= 75; i += 1) {
    arraySizes.push_back(i);
  }

  for (int size : arraySizes) {
    cout << "Size = " << size << "\n";

    dataVector = GenerateReversedSortedVector(size);

    // Сортировка по вставке
    bench = ankerl::nanobench::Bench().warmup(warmups).minEpochIterations(epochs);
    bench.run("| Reversed array - InsertionSort", [&]() { InsertionSort_Test(dataVector); });
    reversedInsertionSortTimes.push_back(bench.results().front().median(ankerl::nanobench::Result::Measure::elapsed));

    // Сортировка по Quick Sort
    bench = ankerl::nanobench::Bench().warmup(warmups).minEpochIterations(epochs);
    bench.run("| Reversed array - QuickSort", [&]() { QuickSort_Test(dataVector); });
    reversedQuickSortTimes.push_back(bench.results().front().median(ankerl::nanobench::Result::Measure::elapsed));
  }

  SaveResults("nanobench-tests.csv", arraySizes, reversedInsertionSortTimes, reversedQuickSortTimes);
}

int main() {
  //ChronoTests();
  NanobenchTests();
  return 0;
}
