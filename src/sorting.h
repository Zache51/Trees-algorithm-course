#ifndef SORTING_H_
#define SORTING_H_

#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Sorting
{
private:
  std::vector<std::vector<int>> printvector;

  vector<int> RandomizeArray(int size);
  void PrintArray(vector<int> array);

  void QuickSort(vector<int> array, int pivot, int left, int right);
  void MergeSort(vector<int>* permanent, vector<int>* temporary, int start, int end, int lvl);

public:
  Sorting();

  void QuickSort(int size);
  void MergeSort(int size);
};

#endif /* end of include guard: SORTING_H_ */
