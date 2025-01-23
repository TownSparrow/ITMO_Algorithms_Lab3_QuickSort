#include "pch.h"
#include <gtest/gtest.h>
#include "../QuickSort/QuickSort.h"
#include <vector>
#include <string>
#include <functional>

// Тестирование сортировки пустого массива (вставка)
TEST(QuickSortTests, EmptyArray_InsertionSort) {
  std::vector<int> data;

  InsertionSort(data.data(), data.data(), std::less<int>());
  EXPECT_TRUE(data.empty());
}

// // Тестирование сортировки пустого массива (quick sort изначальный)
TEST(QuickSortTests, EmptyArray_QuickSort) {
  std::vector<int> data;

  QuickSort(data.data(), data.data(), std::less<int>());
  EXPECT_TRUE(data.empty());
}

// Тестирование сортировки пустого массива (quick sort модифицированный)
TEST(QuickSortTests, EmptyArray_QuickSortModified) {
  std::vector<int> data;

  QuickSortModified(data.data(), data.data(), std::less<int>());
  EXPECT_TRUE(data.empty());
}

// Тестирование сортировки массива из одного элемента (вставка)
TEST(QuickSortTests, SingleElement_InsertionSort) {
  std::vector<int> data = { 42 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data.size(), 1);
  EXPECT_EQ(data[0], 42);
}

// Тестирование сортировки массива из одного элемента (quick sort изначальный)
TEST(QuickSortTests, SingleElement_QuickSort) {
  std::vector<int> data = { 42 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data.size(), 1);
  EXPECT_EQ(data[0], 42);
}

// Тестирование сортировки массива из одного элемента (quick sort модифицированный)
TEST(QuickSortTests, SingleElement_QuickSortModified) {
  std::vector<int> data = { 42 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data.size(), 1);
  EXPECT_EQ(data[0], 42);
}

// Тестирование сортировки массива из двух элементов (вставка)
TEST(QuickSortTests, TwoElements_InsertionSort) {
  std::vector<int> data = { 2, 1 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2 }));
}

// Тестирование сортировки массива из двух элементов (quick sort изначальный)
TEST(QuickSortTests, TwoElements_QuickSort) {
  std::vector<int> data = { 2, 1 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2 }));
}

// Тестирование сортировки массива из двух элементов (quick sort модифицированный)
TEST(QuickSortTests, TwoElements_QuickSortModified) {
  std::vector<int> data = { 2, 1 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2 }));
}

// Тестирование сортировки массива с отрицательными числами (вставка)
TEST(QuickSortTests, NegativeNumbers_InsertionSort) {
  std::vector<int> data = { 3, -1, 2, -5, 0 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ -5, -1, 0, 2, 3 }));
}

// Тестирование сортировки массива с отрицательными числами (quick sort изначальный)
TEST(QuickSortTests, NegativeNumbers_QuickSort) {
  std::vector<int> data = { 3, -1, 2, -5, 0 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ -5, -1, 0, 2, 3 }));
}

// Тестирование сортировки массива с отрицательными числами (quick sort модифицированный)
TEST(QuickSortTests, NegativeNumbers_QuickSortModified) {
  std::vector<int> data = { 3, -1, 2, -5, 0 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ -5, -1, 0, 2, 3 }));
}

// Тестирование сортировки уже отсортированного массива (вставка)
TEST(QuickSortTests, AlreadySorted_InsertionSort) {
  std::vector<int> data = { 1, 2, 3, 4, 5 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5 }));
}

// Тестирование сортировки уже отсортированного массива (quick sort изначальный)
TEST(QuickSortTests, AlreadySorted_QuickSort) {
  std::vector<int> data = { 1, 2, 3, 4, 5 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5 }));
}

// Тестирование сортировки уже отсортированного массива (quick sort модифицированный)
TEST(QuickSortTests, AlreadySorted_QuickSortModified) {
  std::vector<int> data = { 1, 2, 3, 4, 5 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5 }));
}

// Тестирование сортировки массива, отсортированного в обратном порядке (вставка)
TEST(QuickSortTests, ReverseSorted_InsertionSort) {
  std::vector<int> data = { 5, 4, 3, 2, 1 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5 }));
}

// Тестирование сортировки массива, отсортированного в обратном порядке (quick sort изначальный)
TEST(QuickSortTests, ReverseSorted_QuickSort) {
  std::vector<int> data = { 5, 4, 3, 2, 1 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5 }));
}

// Тестирование сортировки массива, отсортированного в обратном порядке (quick sort модифицированный)
TEST(QuickSortTests, ReverseSorted_QuickSortModified) {
  std::vector<int> data = { 5, 4, 3, 2, 1 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5 }));
}

// Тестирование сортировки массива с повторяющимися элементами (вставка)
TEST(QuickSortTests, Duplicates_InsertionSort) {
  std::vector<int> data = { 3, 1, 2, 3, 2, 1 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 1, 2, 2, 3, 3 }));
}

// Тестирование сортировки массива с повторяющимися элементами (quick sort изначальный)
TEST(QuickSortTests, Duplicates_QuickSort) {
  std::vector<int> data = { 3, 1, 2, 3, 2, 1 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 1, 2, 2, 3, 3 }));
}

// Тестирование сортировки массива с повторяющимися элементами (quick sort модифицированный)
TEST(QuickSortTests, Duplicates_QuickSortModified) {
  std::vector<int> data = { 3, 1, 2, 3, 2, 1 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 1, 2, 2, 3, 3 }));
}

// Тестирование сортировки маленького массива (на работоспособность) (вставка)
TEST(QuickSortTests, NotBigArray_InsertionSort) {
  constexpr int N = 50;
  std::vector<int> data(N);

  for (int i = 0; i < N; ++i) {
    data[i] = N - i; // массив заполняется в обратном порядке
  }

  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(data[i], i + 1);
  }
}

// Тестирование сортировки маленького массива (на работоспособность) (quick sort изначальный)
TEST(QuickSortTests, NotBigArray_QuickSort) {
  constexpr int N = 50;
  std::vector<int> data(N);

  for (int i = 0; i < N; ++i) {
    data[i] = N - i; // массив заполняется в обратном порядке
  }

  QuickSort(data.data(), data.data() + data.size(), std::less<int>());

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(data[i], i + 1);
  }
}

// Тестирование сортировки маленького массива (на работоспособность) (quick sort модифицированный)
TEST(QuickSortTests, NotBigArray_QuickSortModified) {
  constexpr int N = 50;
  std::vector<int> data(N);

  for (int i = 0; i < N; ++i) {
    data[i] = N - i; // массив заполняется в обратном порядке
  }

  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(data[i], i + 1);
  }
}

// Тестирование сортировки большого массива (проверка производительности) (вставка)
TEST(QuickSortTests, LargeArray_InsertionSort) {
  constexpr int N = 1000;
  std::vector<int> data(N);

  for (int i = 0; i < N; ++i) {
    data[i] = N - i; // массив заполняется в обратном порядке
  }

  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(data[i], i + 1);
  }
}

// Тестирование сортировки большого массива (проверка производительности) (quick sort изначальный)
TEST(QuickSortTests, LargeArray_QuickSort) {
  constexpr int N = 1000;
  std::vector<int> data(N);

  for (int i = 0; i < N; ++i) {
    data[i] = N - i; // массив заполняется в обратном порядке
  }

  QuickSort(data.data(), data.data() + data.size(), std::less<int>());

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(data[i], i + 1);
  }
}

// Тестирование сортировки большого массива (проверка производительности) (quick sort модифицированный)
TEST(QuickSortTests, LargeArray_QuickSortModified) {
  constexpr int N = 1000;
  std::vector<int> data(N);

  for (int i = 0; i < N; ++i) {
    data[i] = N - i; // массив заполняется в обратном порядке
  }

  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(data[i], i + 1);
  }
}

// Тестирование сортировки массива строк (вставка)
TEST(QuickSortTests, SortStrings_InsertionSort) {
  std::vector<std::string> data = { "apple", "orange", "banana", "grape" };
  InsertionSort(data.data(), data.data() + data.size(), std::less<std::string>());
  EXPECT_EQ(data, std::vector<std::string>({ "apple", "banana", "grape", "orange" }));
}

// Тестирование сортировки массива строк (quick sort изначальный)
TEST(QuickSortTests, SortStrings_QuickSort) {
  std::vector<std::string> data = { "apple", "orange", "banana", "grape" };
  QuickSort(data.data(), data.data() + data.size(), std::less<std::string>());
  EXPECT_EQ(data, std::vector<std::string>({ "apple", "banana", "grape", "orange" }));
}

// Тестирование сортировки массива строк (quick sort модифицированный)
TEST(QuickSortTests, SortStrings_QuickSortModified) {
  std::vector<std::string> data = { "apple", "orange", "banana", "grape" };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<std::string>());
  EXPECT_EQ(data, std::vector<std::string>({ "apple", "banana", "grape", "orange" }));
}

// Тестирование сортировки пользовательских типов данных
struct Custom {
  int key;
  double value;

  bool operator<(const Custom& other) const {
    if (key == other.key) {
      return value < other.value;
    }
    return key < other.key;
  }
};

// Для вставки
TEST(QuickSortTests, CustomTypes_InsertionSort) {
  std::vector<Custom> data = { {2, 2.1}, {2, 1.2}, {1, 1.1} };
  InsertionSort(data.data(), data.data() + data.size(), [](const Custom& a, const Custom& b) { return a < b; });
  EXPECT_EQ(data[0].key, 1);
  EXPECT_EQ(data[1].key, 2);
  EXPECT_EQ(data[2].key, 2);
  EXPECT_EQ(data[0].value, 1.1);
  EXPECT_EQ(data[1].value, 1.2);
  EXPECT_EQ(data[2].value, 2.1);
}

// Для QuickSort
TEST(QuickSortTests, CustomTypes_QuickSort) {
  std::vector<Custom> data = { {2, 2.1}, {2, 1.2}, {1, 1.1} };
  QuickSort(data.data(), data.data() + data.size(), [](const Custom& a, const Custom& b) { return a < b; });
  EXPECT_EQ(data[0].key, 1);
  EXPECT_EQ(data[1].key, 2);
  EXPECT_EQ(data[2].key, 2);
  EXPECT_EQ(data[0].value, 1.1);
  EXPECT_EQ(data[1].value, 1.2);
  EXPECT_EQ(data[2].value, 2.1);
}

// Для QuickSort модифцированного
TEST(QuickSortTests, CustomTypes_QuickSortModified) {
  std::vector<Custom> data = { {2, 2.1}, {2, 1.2}, {1, 1.1} };
  QuickSortModified(data.data(), data.data() + data.size(), [](const Custom& a, const Custom& b) { return a < b; });
  EXPECT_EQ(data[0].key, 1);
  EXPECT_EQ(data[1].key, 2);
  EXPECT_EQ(data[2].key, 2);
  EXPECT_EQ(data[0].value, 1.1);
  EXPECT_EQ(data[1].value, 1.2);
  EXPECT_EQ(data[2].value, 2.1);
}

// Тестирование массива с одинаковыми элементами (вставка)
TEST(QuickSortTests, AllEqualElements_InsertionSort) {
  std::vector<int> data(100, 42); // 100 элементов со значением 42
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>(100, 42));
}

// Тестирование массива с одинаковыми элементами (QuickSort)
TEST(QuickSortTests, AllEqualElements_QuickSort) {
  std::vector<int> data(100, 42); // 100 элементов со значением 42
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>(100, 42));
}

// Тестирование массива с одинаковыми элементами (QuickSort модифцированный)
TEST(QuickSortTests, AllEqualElements_QuickSortModified) {
  std::vector<int> data(100, 42); // 100 элементов со значением 42
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>(100, 42));
}

// Тестирование массива с одним уникальным элементом и остальными одинаковыми (вставка)
TEST(QuickSortTests, OneUniqueElement_InsertionSort) {
  std::vector<int> data = { 42, 42, 42, 42, 99, 42, 42 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 42, 42, 42, 42, 42, 42, 99 }));
}

// Тестирование массива с одним уникальным элементом и остальными одинаковыми (QuickSort)
TEST(QuickSortTests, OneUniqueElement_QuickSort) {
  std::vector<int> data = { 42, 42, 42, 42, 99, 42, 42 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 42, 42, 42, 42, 42, 42, 99 }));
}

// Тестирование массива с одним уникальным элементом и остальными одинаковыми (QuickSort модифцированный)
TEST(QuickSortTests, OneUniqueElement_QuickSortModified) {
  std::vector<int> data = { 42, 42, 42, 42, 99, 42, 42 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 42, 42, 42, 42, 42, 42, 99 }));
}

// Тестирование массива с плавающими точками (вставка)
TEST(QuickSortTests, FloatingPointNumbers_InsertionSort) {
  std::vector<double> data = { 3.14, 2.71, -1.0, 0.0, 1.618 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<double>());
  EXPECT_EQ(data, std::vector<double>({ -1.0, 0.0, 1.618, 2.71, 3.14 }));
}

// Тестирование массива с плавающими точками (QuickSort)
TEST(QuickSortTests, FloatingPointNumbers_QuickSort) {
  std::vector<double> data = { 3.14, 2.71, -1.0, 0.0, 1.618 };
  QuickSort(data.data(), data.data() + data.size(), std::less<double>());
  EXPECT_EQ(data, std::vector<double>({ -1.0, 0.0, 1.618, 2.71, 3.14 }));
}

// Тестирование массива с плавающими точками (QuickSort модифцированный)
TEST(QuickSortTests, FloatingPointNumbers_QuickSortModified) {
  std::vector<double> data = { 3.14, 2.71, -1.0, 0.0, 1.618 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<double>());
  EXPECT_EQ(data, std::vector<double>({ -1.0, 0.0, 1.618, 2.71, 3.14 }));
}

// Тестирование массива с пользовательским компаратором для сортировки по убыванию (вставка)
TEST(QuickSortTests, CustomComparatorDescending_InsertionSort) {
  std::vector<int> data = { 1, 3, 2, 5, 4 };
  InsertionSort(data.data(), data.data() + data.size(), std::greater<int>());
  EXPECT_EQ(data, std::vector<int>({ 5, 4, 3, 2, 1 }));
}

// Тестирование массива с пользовательским компаратором для сортировки по убыванию (QuickSort)
TEST(QuickSortTests, CustomComparatorDescending_QuickSort) {
  std::vector<int> data = { 1, 3, 2, 5, 4 };
  QuickSort(data.data(), data.data() + data.size(), std::greater<int>());
  EXPECT_EQ(data, std::vector<int>({ 5, 4, 3, 2, 1 }));
}

// Тестирование массива с пользовательским компаратором для сортировки по убыванию (QuickSort модифцированный)
TEST(QuickSortTests, CustomComparatorDescending_QuickSortModified) {
  std::vector<int> data = { 1, 3, 2, 5, 4 };
  QuickSortModified(data.data(), data.data() + data.size(), std::greater<int>());
  EXPECT_EQ(data, std::vector<int>({ 5, 4, 3, 2, 1 }));
}

// Тестирование массива с нулевой длиной через передачу некорректных указателей (вставка)
TEST(QuickSortTests, NullPointer_InsertionSort) {
  int* elemFirst = nullptr;
  int* elemLast = nullptr;
  InsertionSort(elemFirst, elemLast, std::less<int>());
  SUCCEED(); // если программа не упала, тест считается успешным
}

// Тестирование массива с нулевой длиной через передачу некорректных указателей (QuickSort)
TEST(QuickSortTests, NullPointer_QuickSort) {
  int* elemFirst = nullptr;
  int* elemLast = nullptr;
  QuickSort(elemFirst, elemLast, std::less<int>());
  SUCCEED(); // если программа не упала, тест считается успешным
}

// Тестирование массива с нулевой длиной через передачу некорректных указателей (QuickSort модифцированный)
TEST(QuickSortTests, NullPointer_QuickSortModified) {
  int* elemFirst = nullptr;
  int* elemLast = nullptr;
  QuickSortModified(elemFirst, elemLast, std::less<int>());
  SUCCEED(); // если программа не упала, тест считается успешным
}

// Тестирование с уже отсортированными строками (вставка)
TEST(QuickSortTests, AlreadySortedStrings_InsertionSort) {
  std::vector<std::string> data = { "a", "b", "c", "d", "e" };
  InsertionSort(data.data(), data.data() + data.size(), std::less<std::string>());
  EXPECT_EQ(data, std::vector<std::string>({ "a", "b", "c", "d", "e" }));
}

// Тестирование с уже отсортированными строками (QuickSort)
TEST(QuickSortTests, AlreadySortedStrings_QuickSort) {
  std::vector<std::string> data = { "a", "b", "c", "d", "e" };
  QuickSort(data.data(), data.data() + data.size(), std::less<std::string>());
  EXPECT_EQ(data, std::vector<std::string>({ "a", "b", "c", "d", "e" }));
}

// Тестирование с уже отсортированными строками (QuickSort модифцированный)
TEST(QuickSortTests, AlreadySortedStrings_QuickSortModified) {
  std::vector<std::string> data = { "a", "b", "c", "d", "e" };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<std::string>());
  EXPECT_EQ(data, std::vector<std::string>({ "a", "b", "c", "d", "e" }));
}

// Тестирование с перестановкой местами нескольких элементов (вставка)
TEST(QuickSortTests, PartiallySortedArray_InsertionSort) {
  std::vector<int> data = { 1, 2, 5, 4, 3, 6 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5, 6 }));
}

// Тестирование с перестановкой местами нескольких элементов (QuickSort)
TEST(QuickSortTests, PartiallySortedArray_QuickSort) {
  std::vector<int> data = { 1, 2, 5, 4, 3, 6 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5, 6 }));
}

// Тестирование с перестановкой местами нескольких элементов (QuickSort модифцированный)
TEST(QuickSortTests, PartiallySortedArray_QuickSortModified) {
  std::vector<int> data = { 1, 2, 5, 4, 3, 6 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 2, 3, 4, 5, 6 }));
}

// Тестирование сортировки массивов с большим количеством дубликатов (вставка)
TEST(QuickSortTests, LargeDuplicates_InsertionSort) {
  std::vector<int> data = { 1, 2, 2, 2, 2, 1, 1, 1, 3 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 1, 1, 1, 2, 2, 2, 2, 3 }));
}

// Тестирование сортировки массивов с большим количеством дубликатов (QuickSort)
TEST(QuickSortTests, LargeDuplicates_QuickSort) {
  std::vector<int> data = { 1, 2, 2, 2, 2, 1, 1, 1, 3 };
  QuickSort(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 1, 1, 1, 2, 2, 2, 2, 3 }));
}

// Тестирование сортировки массивов с большим количеством дубликатов (QuickSort модифцированный)
TEST(QuickSortTests, LargeDuplicates_QuickSortModified) {
  std::vector<int> data = { 1, 2, 2, 2, 2, 1, 1, 1, 3 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<int>());
  EXPECT_EQ(data, std::vector<int>({ 1, 1, 1, 1, 2, 2, 2, 2, 3 }));
}

// Тестирование с большими числами (проверка на переполнение) (вставка)
TEST(QuickSortTests, LargeNumbers_InsertionSort) {
  std::vector<long long> data = { 9223372036854775807, -9223372036854775807, 0, 1 };
  InsertionSort(data.data(), data.data() + data.size(), std::less<long long>());
  EXPECT_EQ(data, std::vector<long long>({ -9223372036854775807, 0, 1, 9223372036854775807 }));
}

// Тестирование с большими числами (проверка на переполнение) (QuickSort)
TEST(QuickSortTests, LargeNumbers_QuickSort) {
  std::vector<long long> data = { 9223372036854775807, -9223372036854775807, 0, 1 };
  QuickSort(data.data(), data.data() + data.size(), std::less<long long>());
  EXPECT_EQ(data, std::vector<long long>({ -9223372036854775807, 0, 1, 9223372036854775807 }));
}

// Тестирование с большими числами (проверка на переполнение) (QuickSort модифцированный)
TEST(QuickSortTests, LargeNumbers_QuickSortModified) {
  std::vector<long long> data = { 9223372036854775807, -9223372036854775807, 0, 1 };
  QuickSortModified(data.data(), data.data() + data.size(), std::less<long long>());
  EXPECT_EQ(data, std::vector<long long>({ -9223372036854775807, 0, 1, 9223372036854775807 }));
}

// Тестирование с пользовательскими структурами данных с дополнительными полями
struct ComplexCustom {
  int key;
  std::string value;

  bool operator<(const ComplexCustom& other) const {
    return key < other.key;
  }
};

// для вставки
TEST(QuickSortTests, ComplexCustomTypes_InsertionSort) {
  std::vector<ComplexCustom> data = { {2, "B"}, {1, "A"}, {3, "C"} };
  InsertionSort(data.data(), data.data() + data.size(), [](const ComplexCustom& a, const ComplexCustom& b) { return a.key < b.key; });
  EXPECT_EQ(data[0].key, 1);
  EXPECT_EQ(data[1].key, 2);
  EXPECT_EQ(data[2].key, 3);
  EXPECT_EQ(data[0].value, "A");
  EXPECT_EQ(data[1].value, "B");
  EXPECT_EQ(data[2].value, "C");
}

// для QuickSort
TEST(QuickSortTests, ComplexCustomTypes_QuickSort) {
  std::vector<ComplexCustom> data = { {2, "B"}, {1, "A"}, {3, "C"} };
  QuickSort(data.data(), data.data() + data.size(), [](const ComplexCustom& a, const ComplexCustom& b) { return a.key < b.key; });
  EXPECT_EQ(data[0].key, 1);
  EXPECT_EQ(data[1].key, 2);
  EXPECT_EQ(data[2].key, 3);
  EXPECT_EQ(data[0].value, "A");
  EXPECT_EQ(data[1].value, "B");
  EXPECT_EQ(data[2].value, "C");
}

// для QuickSort модифицированного
TEST(QuickSortTests, ComplexCustomTypes_QuickSortModified) {
  std::vector<ComplexCustom> data = { {2, "B"}, {1, "A"}, {3, "C"} };
  QuickSortModified(data.data(), data.data() + data.size(), [](const ComplexCustom& a, const ComplexCustom& b) { return a.key < b.key; });
  EXPECT_EQ(data[0].key, 1);
  EXPECT_EQ(data[1].key, 2);
  EXPECT_EQ(data[2].key, 3);
  EXPECT_EQ(data[0].value, "A");
  EXPECT_EQ(data[1].value, "B");
  EXPECT_EQ(data[2].value, "C");
}
