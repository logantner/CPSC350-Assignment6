#ifndef _ASS6_SORTING_H_
#define _ASS6_SORTING_H_

#include <iostream>

////////////
// Header //
////////////

template <class T> void bubbleSort(T*, int);
template <class T> void insertionSort(T*, int);
template <class T> void quickSort(T*, int);
template <class T> void cocktailSort(T*, int);

template <class T> void swap(T*, int, int);
template <class T> void insert(T*, int, int);
template <class T> void recQuickSort(T*, int, int);
template <class T> int partition(T*, int, int);
template <class T> void display(T*, int);
template <class T> void display(T*, int, int);

/////////////////////
// Implementations //
/////////////////////

template <class T>
void bubbleSort(T* data, int size) {
  // Sorts data array in place using the bubblesort algorithm
  if (size <= 1) { return; }

  bool isSorted = false;
  while (!isSorted) {
    isSorted = true;
    for (int i=0; i<size-1; ++i) {
      if (data[i] > data[i+1]) {
        swap(data, i, i+1);
        isSorted = false;
      }
    }
  }
}

template <class T>
void insertionSort(T* data, int size) {
  // Sorts data array in place using the insertionsort algorithm
  if (size <= 1) { return; }

  int insertLoc;
  for (int i=1; i<size; ++i) {
    insertLoc = 0;
    for (int j=0; j<i; ++j) {
      if (data[i] > data[j]) { ++insertLoc; }
      else                 { break; }
    }
    insert(data, i, insertLoc);
  }
}

template <class T>
void quickSort(T* data, int size) {
  // Sorts data array in place using the quicksort algorithm
  recQuickSort(data, 0, size);
}

template <class T>
void recQuickSort(T* data, int lowIdx, int highIdx) {
  int pivotIdx = partition(data, lowIdx, highIdx);

  if (lowIdx  < pivotIdx)   { recQuickSort(data, lowIdx, pivotIdx); }
  if (highIdx > pivotIdx+1) { recQuickSort(data, pivotIdx+1, highIdx); }
}

template <class T>
void cocktailSort(T* data, int size) {
  // Sorts data array in place using the cocktailsort algorithm
  if (size <= 1) { return; }

  bool isSorted;
  int low = 0;
  int high = size-1;
  while (!isSorted) {
    isSorted = true;
    for (int i=low; i < high; ++i) {
      if (data[i] > data[i+1]) {
        swap(data, i, i+1);
        isSorted = false;
      }
    }

    for (int i=high-1; i > low; --i) {
      if (data[i] < data[i-1]) {
        swap(data, i, i-1);
        isSorted = false;
      }
    }
  }
}

template <class T>
int partition(T* data, int lowIdx, int highIdx) {
  // Chooses highIdx-1 as the pivot value location. Moves it to the correct
  // location (with smaller values left and larger values right), then returns
  // the new pivot position
  int pivotIdx = lowIdx-1;
  T pivot = data[highIdx-1];
  for (int i = lowIdx; i < highIdx; ++i) {
    if (data[i] <= pivot) {
      pivotIdx++;
      swap(data, pivotIdx, i);
    }
  }
  return pivotIdx;
}

template <class T>
void swap(T* data, int idx1, int idx2) {
  // Swaps data at locations idx1 and idx2, inplace
  T temp = data[idx1];
  data[idx1] = data[idx2];
  data[idx2] = temp;
}

template <class T>
void insert(T* data, int fromIdx, int toIdx) {
  // Inserts the value located at fromIdx into toIdx.
  T temp = data[fromIdx];
  // Shift all necessary values up one index
  for (int i=fromIdx; i>toIdx; --i) {
    data[i] = data[i-1];
  }
  data[toIdx] = temp;
}

template <class T>
void display(T* data, int size) {
  for (int i=0; i<size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

template <class T>
void display(T* data, int lo, int hi) {
  for (int i=lo; i<hi; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

#endif
