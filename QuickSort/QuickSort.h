#pragma once

#include <algorithm> 
#include <iterator>
#include <utility> 
#include <stdexcept>

// ���������� ��������� ��� ����� ��������
template <typename T, typename Compare>
void InsertionSort(T* elemFirst, T* elemLast, Compare comp) {
  /*
    // ����������, ���� ������ ������, �� ����� � �������� ���� ��������� � ������� ������
    if (elemFirst == nullptr || elemLast == nullptr) {
      throw std::invalid_argument("Null pointer passed to QuickSort");
  }
  */
  
  // ����� �������� � ��������� �� ������� �� �����
  for (T* i = elemFirst + 1; i < elemLast; ++i) {
    T value = std::move(*i);
    T* temp = i;

    // �������� ��������� �� ��� ���, ���� ���������� ������� �� ����� �������
    while (temp > elemFirst && comp(value, *(temp - 1))) {
      *temp = std::move(*(temp - 1));
      --temp;
    }
    *temp = std::move(value); // ������� �������� � ������ �����
  }
}

// ������������ ��� swap
/*
template <typename T>
void SwapAlternative(T& elem1, T& elem2) {
  T temp = std::move(elem1);
  elem1 = std::move(elem2);
  elem2 = std::move(temp);
}
*/


// ����� ������� �� ���� (������, �������, ��������� ��������)
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

// �������� ������� QuickSort
template <typename T, typename Compare>
void QuickSort(T* elemFirst, T* elemLast, Compare comp) {
  /*
  // ����������, ���� ������ ������, �� ����� � �������� ���� ��������� � ������� ������
  if (elemFirst == nullptr || elemLast == nullptr) {
    throw std::invalid_argument("Null pointer passed to QuickSort");
  }
  */

  // ���� ����� ������ 1
  while (std::distance(elemFirst, elemLast) > 1) {
    int arraySize = std::distance(elemFirst, elemLast);

    // ����� ������� ��� �������� ��������
    T& pivot = SelectPivotMedian(elemFirst, elemFirst + arraySize / 2, elemLast - 1, comp);

    // ���������� ������� ������ �������� ��������
    T* elemLeft = elemFirst;
    T* elemRight = elemLast - 1;

    //HoareScheme(elemLeft, elemRight, comp);

    while (true) {
      // ����� ���������, ������� ����� �������� �������
      while (comp(*elemLeft, pivot)) ++elemLeft;
      while (comp(pivot, *elemRight)) --elemRight;

      if (elemLeft >= elemRight) break; // ���� ��������� �����������, �� ��������� ����

      //std::swap(*elemLeft, *elemRight); // ������ ��������� �������
      //SwapAlternative(*elemLeft, *elemRight);
      T temp = std::move(*elemLeft);
      *elemLeft = std::move(*elemRight);
      *elemRight = std::move(temp);

      ++elemLeft;
      --elemRight;
    }

    // ��������� ��������: ������� ����� �����������, � ������� - �������������� � �����
    T* elemMid = elemLeft;
    if (std::distance(elemFirst, elemMid) < std::distance(elemMid, elemLast)) {
      QuickSort(elemFirst, elemMid, comp);  // ����������� ����� ��� ����� �����
      elemFirst = elemMid;                  // ���������� ������ ����� � ��������� ��������
    }
    else {
      QuickSort(elemMid, elemLast, comp);   // ����������� ����� ��� ������ �����
      elemLast = elemMid;                   // ���������� ����� ����� � ��������� ��������
    }
  }
}


// ���������� ������� QuickSort
template <typename T, typename Compare>
void QuickSortModified(T* elemFirst, T* elemLast, Compare comp) {
  /*
  // ����������, ���� ������ ������, �� ����� � �������� ���� ��������� � ������� ������
  if (elemFirst == nullptr || elemLast == nullptr) {
    throw std::invalid_argument("Null pointer passed to QuickSort");
  }
  */

  constexpr int kThreshold = 24; // ����� ��� �������� �� ���������� ���������

  // ���� ����� ������ 1
  while (std::distance(elemFirst, elemLast) > 1) {
    int arraySize = std::distance(elemFirst, elemLast);

    // ���� ����� ������ ������, �� ���������� ���������
    if (arraySize <= kThreshold) {
      InsertionSort(elemFirst, elemLast, comp);
      return;
    }

    // ����� ������� ��� �������� ��������
    T& pivot = SelectPivotMedian(elemFirst, elemFirst + arraySize / 2, elemLast - 1, comp);

    // ���������� ������� ������ �������� ��������
    T* elemLeft = elemFirst;
    T* elemRight = elemLast - 1;

    //HoareScheme(elemLeft, elemRight, comp);
    
    while (true) {
      // ����� ���������, ������� ����� �������� �������
      while (comp(*elemLeft, pivot)) ++elemLeft;
      while (comp(pivot, *elemRight)) --elemRight;

      if (elemLeft >= elemRight) break; // ���� ��������� �����������, �� ��������� ����

      //std::swap(*elemLeft, *elemRight); // ������ ��������� �������
      // SwapAlternative(*elemLeft, *elemRight);

      T temp = std::move(*elemLeft);
      *elemLeft = std::move(*elemRight);
      *elemRight = std::move(temp);

      ++elemLeft;
      --elemRight;
    }

    // ��������� ��������: ������� ����� �����������, � ������� - �������������� � �����
    T* elemMid = elemLeft;
    if (std::distance(elemFirst, elemMid) < std::distance(elemMid, elemLast)) {
      QuickSortModified(elemFirst, elemMid, comp);  // ����������� ����� ��� ����� �����
      elemFirst = elemMid;                          // ���������� ������ ����� � ��������� ��������
    }
    else {
      QuickSortModified(elemMid, elemLast, comp);   // ����������� ����� ��� ������ �����
      elemLast = elemMid;                           // ���������� ����� ����� � ��������� ��������
    }
  }
}