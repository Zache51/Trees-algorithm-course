#include "sorting.h"

  Sorting::Sorting()
  {
    srand (time(NULL));
  }

  vector<int> Sorting::RandomizeArray(int size, int max_random)
  {
    vector<int> ivector(size);
    for (int i = 0; i < size; i++)
    {
      ivector[i] = rand() % max_random;
    }
    return ivector;
  }

  void Sorting::PrintArray(vector<int> ivector)
  {
    std::ostringstream oss;

    for (int i = 0; i < (int)ivector.size(); i++) {
      oss << ivector[i] << " ";
    }

    std::cout << oss.str() << std::endl;
  }

  /*** QuickSort *****************************************************/

  void Sorting::PrintQuickSortStage(vector<int>* array, int left, int right, int pivot)
  {
    cout << "Iteration " << to_string(counter) << ": ";
    for (int i = 0; i < (int)array->size(); i++) {
      string message = to_string(array->at(i));
      if (i == pivot)
      {
        message = TeCo::color_it(TeCo::cyan, message);
      }
      else if (i == right)
      {
        message = TeCo::color_it(TeCo::yellow, message);
      }
      else if (i == left)
      {
        message = TeCo::color_it(TeCo::red, message);
      }
      else if (printvector[0][i] != -1)
      {
        message = TeCo::color_it(TeCo::green, message);
      }
      cout << message << " ";
    }
    cout << endl;
  }

  void Sorting::QuickSort(vector<int>* array, int left, int pivot)
  {
    if (left == pivot)
    {
      printvector[0][pivot] = pivot;
      PrintQuickSortStage(array, left, left, pivot);
      counter++;
    }
    else
    {
      int leftstart = left;
      int rightend = pivot;

      int right = pivot - 1;

      PrintQuickSortStage(array, left, right, pivot);
      do {
        while (array->at(left) <= array->at(pivot) && left != right) {
          left++;
        }
        while (array->at(right) >= array->at(pivot) && left != right) {
          right--;
        }

        if (left != right) {
          int temp = array->at(left);
          array->at(left) = array->at(right);
          array->at(right) = temp;
          PrintQuickSortStage(array, left, right, pivot);
        }
        else if (array->at(left) > array->at(pivot)) {
            int temp = array->at(left);
            array->at(left) = array->at(pivot);
            array->at(pivot) = temp;
            pivot = left;

            PrintQuickSortStage(array, left, right, pivot);
            printvector[0][left] = left;

        }

      } while(left != right);

      printvector[0][pivot] = pivot;
      counter++;

      if (leftstart != pivot) QuickSort(array, leftstart, pivot - 1);
      if (rightend != pivot) QuickSort(array, pivot + 1, rightend);
    }
  }

  void Sorting::QuickSort(int size)
  {
    vector<int> ivector = RandomizeArray(size, 100);

    printvector.push_back(vector<int>());
    for (int i = 0; i < size; i++) {
      printvector[0].push_back(-1);
    }

    counter = 1;
    PrintArray(ivector);
    QuickSort(&ivector, 0, size - 1);
    counter = 1;

    printvector.clear();
  }


  /*** MergeSort *****************************************************/

  void Sorting::MergeSort(vector<int>* permanent, vector<int>* temporary, int start, int end, int lvl)
  {
    if (start == end)
    {
      printvector[lvl].push_back(permanent->at(start));
    }
    else
    {
      int middle = (start + end) / 2;

      MergeSort(permanent, temporary, start, middle, lvl + 1);
      MergeSort(permanent, temporary, middle + 1, end, lvl + 1);


      int l, r, i;
      l = start;
      r = middle + 1;
      i = start;

      // Compare and sort the two "arrays"
      while (l <= middle && r <= end)
      {
        if (permanent->at(l) <= permanent->at(r))
        {
          temporary->at(i) = permanent->at(l);
          l++;
        }
        else if (permanent->at(r) < permanent->at(l))
        {
          temporary->at(i) = permanent->at(r);
          r++;
        }
        i++;
      }

      // Copy over leftover data (that obviously is sorted)
      while (l <= middle) {
        temporary->at(i) = permanent->at(l);
        l++;
        i++;
      }
      while (r <= end) {
        temporary->at(i) = permanent->at(r);
        r++;
        i++;
      }

      for (i = start; i <= end; i++) {
        permanent->at(i) = temporary->at(i);

        // copy to extra memory for demonstration purpose
        printvector[lvl].push_back(permanent->at(i));
      }
    }
  }

  void Sorting::MergeSort(int size)
  {

    vector<int> ivector = RandomizeArray(size, 100);

    int maxlevel = std::log2(size) + 2;
    for (int i = 0; i < maxlevel; i++) {
      printvector.push_back(vector<int>());
    }

    vector<int> temp(size);
    MergeSort(&ivector, &temp, 0, size - 1, 0);

    cout << std::endl;
    for (int i = maxlevel - 1; i >= 0; i--) {
      cout << "Level" << std::to_string(i) << ": ";
      PrintArray(printvector[i]);
    }
    cout << std::endl;

    printvector.clear();
  }
