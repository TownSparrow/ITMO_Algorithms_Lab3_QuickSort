#pragma once

#include <algorithm> 
#include <iterator>
#include <utility> 
#include <stdexcept>

// Сортировка вставками для малых массивов
template <typename T, typename Compare>
void InsertionSort(T* elemFirst, T* elemLast, Compare comp) {
  /*
    // Фактически, если массив пустой, то можно и вызывать краш программы с выводом ошибки
    if (elemFirst == nullptr || elemLast == nullptr) {
      throw std::invalid_argument("Null pointer passed to QuickSort");
  }
  */
  
  // Поиск элемента в диапозоне от второго до конца
  for (T* i = elemFirst + 1; i < elemLast; ++i) {
    T value = std::move(*i);
    T* temp = i;

    // Элементы смещаются до тех пор, пока правильная позиция не будет найдена
    while (temp > elemFirst && comp(value, *(temp - 1))) {
      *temp = std::move(*(temp - 1));
      --temp;
    }
    *temp = std::move(value); // вставка элемента в нужное место
  }
}

// Альтернатива для swap
/*
template <typename T>
void SwapAlternative(T& elem1, T& elem2) {
  T temp = std::move(elem1);
  elem1 = std::move(elem2);
  elem2 = std::move(temp);
}
*/


// Выбор медианы из трех (первый, средний, последний элементы)
template <typename T, typename Compare>
T& SelectPivotMedian(T* elemFirst, T* elemMid, T* elemLast, Compare comp) {
  /*
  if (comp(*elemMid, *elemFirst)) std::swap(*elemFirst, *elemMid);
  if (comp(*elemLast, *elemFirst)) std::swap(*elemFirst, *elemLast);
  if (comp(*elemLast, *elemMid)) std::swap(*elemMid, *elemLast);
  */

  /*
  if (comp(*elemMid, *elemFirst)) SwapAlternative(*elemFirst, *elemMid);
  if (comp(*elemLast, *elemFirst)) SwapAlternative(*elemFirst, *elemLast);
  if (comp(*elemLast, *elemMid)) SwapAlternative(*elemMid, *elemLast);
  return *elemMid;
  */

  if (comp(*elemMid, *elemFirst)) {
    T temp = std::move(*elemFirst);
    *elemFirst = std::move(*elemMid); 
    *elemMid = std::move(temp);
  }

  if (comp(*elemLast, *elemFirst)) {
    T temp = std::move(*elemLast);
    *elemLast = std::move(*elemFirst);
    *elemFirst = std::move(temp);
  }

  if (comp(*elemLast, *elemMid)) {
    T temp = std::move(*elemLast);
    *elemLast = std::move(*elemMid);
    *elemMid = std::move(temp);
  }
  
  return *elemMid;
}

// Исходная функция QuickSort
template <typename T, typename Compare>
void QuickSort(T* elemFirst, T* elemLast, Compare comp) {
  /*
  // Фактически, если массив пустой, то можно и вызывать краш программы с выводом ошибки
  if (elemFirst == nullptr || elemLast == nullptr) {
    throw std::invalid_argument("Null pointer passed to QuickSort");
  }
  */

  // Пока длина больше 1
  while (std::distance(elemFirst, elemLast) > 1) {
    int arraySize = std::distance(elemFirst, elemLast);

    // Выбор медианы как опорного элемента
    T& pivot = SelectPivotMedian(elemFirst, elemFirst + arraySize / 2, elemLast - 1, comp);

    // Разделение массива вокруг опорного элемента
    T* elemLeft = elemFirst;
    T* elemRight = elemLast - 1;

    //HoareScheme(elemLeft, elemRight, comp);

    while (true) {
      // Поиск элементов, которые нужно поменять местами
      while (comp(*elemLeft, pivot)) ++elemLeft;
      while (comp(pivot, *elemRight)) --elemRight;

      if (elemLeft >= elemRight) break; // если указатели пересеклись, то прерываем цикл

      //std::swap(*elemLeft, *elemRight); // замена элементов местами
      //SwapAlternative(*elemLeft, *elemRight);
      T temp = std::move(*elemLeft);
      *elemLeft = std::move(*elemRight);
      *elemRight = std::move(temp);

      ++elemLeft;
      --elemRight;
    }

    // Хвостовая рекурсия: меньшая часть сортируется, а большая - обрабатывается в цикле
    T* elemMid = elemLeft;
    if (std::distance(elemFirst, elemMid) < std::distance(elemMid, elemLast)) {
      QuickSort(elemFirst, elemMid, comp);  // рекурсивный вызов для левой части
      elemFirst = elemMid;                  // сортировка правой части в следующей итерации
    }
    else {
      QuickSort(elemMid, elemLast, comp);   // рекурсивный вызов для правой части
      elemLast = elemMid;                   // сортировка левой части в следующей итерации
    }
  }
}


// Улучшенная функция QuickSort
template <typename T, typename Compare>
void QuickSortModified(T* elemFirst, T* elemLast, Compare comp) {
  /*
  // Фактически, если массив пустой, то можно и вызывать краш программы с выводом ошибки
  if (elemFirst == nullptr || elemLast == nullptr) {
    throw std::invalid_argument("Null pointer passed to QuickSort");
  }
  */

  constexpr int kThreshold = 24; // порог для перехода на сортировку вставками

  // Пока длина больше 1
  while (std::distance(elemFirst, elemLast) > 1) {
    int arraySize = std::distance(elemFirst, elemLast);

    // Если длина меньше порога, то сортировка вставками
    if (arraySize <= kThreshold) {
      InsertionSort(elemFirst, elemLast, comp);
      return;
    }

    // Выбор медианы как опорного элемента
    T& pivot = SelectPivotMedian(elemFirst, elemFirst + arraySize / 2, elemLast - 1, comp);

    // Разделение массива вокруг опорного элемента
    T* elemLeft = elemFirst;
    T* elemRight = elemLast - 1;

    //HoareScheme(elemLeft, elemRight, comp);
    
    while (true) {
      // Поиск элементов, которые нужно поменять местами
      while (comp(*elemLeft, pivot)) ++elemLeft;
      while (comp(pivot, *elemRight)) --elemRight;

      if (elemLeft >= elemRight) break; // если указатели пересеклись, то прерываем цикл

      //std::swap(*elemLeft, *elemRight); // замена элементов местами
      // SwapAlternative(*elemLeft, *elemRight);

      T temp = std::move(*elemLeft);
      *elemLeft = std::move(*elemRight);
      *elemRight = std::move(temp);

      ++elemLeft;
      --elemRight;
    }

    // Хвостовая рекурсия: меньшая часть сортируется, а большая - обрабатывается в цикле
    T* elemMid = elemLeft;
    if (std::distance(elemFirst, elemMid) < std::distance(elemMid, elemLast)) {
      QuickSortModified(elemFirst, elemMid, comp);  // рекурсивный вызов для левой части
      elemFirst = elemMid;                          // сортировка правой части в следующей итерации
    }
    else {
      QuickSortModified(elemMid, elemLast, comp);   // рекурсивный вызов для правой части
      elemLast = elemMid;                           // сортировка левой части в следующей итерации
    }
  }
}