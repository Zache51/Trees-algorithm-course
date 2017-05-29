#ifndef SORTING_H_
#define SORTING_H_

#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include "colors.h"

using namespace std;

class Sorting
{
private:
  int counter;
  std::vector<std::vector<int>> printvector;

  vector<int> RandomizeArray(int size, int max_random);
  void PrintArray(vector<int> array);

  // Counting
  void PrintCountingSortStage(int index);

  // Quick
  void PrintQuickSortStage(vector<int>* array, int left, int right, int pivot);
  void QuickSort(vector<int>* array, int left, int pivot);

  // Merge
  void MergeSort(vector<int>* permanent, vector<int>* temporary, int start, int end, int lvl);

public:
  Sorting();

  void CountingSort(int size);
  void QuickSort(int size);
  void MergeSort(int size);
};

#endif /* end of include guard: SORTING_H_ */
