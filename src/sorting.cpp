#include "sorting.h"

  Sorting::Sorting()
  {
    srand (time(NULL));
  };

  vector<int> Sorting::RandomizeArray(int size)
  {
    vector<int> ivector(size);
    for (size_t i = 0; i < size; i++)
    {
      ivector[i] = rand() % 100;
    }
    return ivector;
  }

  void Sorting::PrintArray(vector<int> ivector)
  {
    std::ostringstream oss;

    for (size_t i = 0; i < ivector.size(); i++) {
      oss << ivector[i] << " ";
    }

    std::cout << oss.str() << std::endl;
  }

  /*** QuickSort *****************************************************/

  void Sorting::QuickSort(vector<int> array, int pivot, int left, int right)
  {
    // while (left < right)
    // {
    //   while (array.GetArray()[left] > array.GetArray()[pivot])
    //   {
    //     /* code */
    //   }
    //   while (array.GetArray()[right] < array.GetArray()[pivot])
    //   {
    //     /* code */
    //   }
    // }

    //QuickSort(array, right - 1, left, )
  }

  void Sorting::QuickSort(int size)
  {
    // IArray array = RandomizeArray(size);
    // PrintArray(array);
    //
    // QuickSort(array, size - 1, 0, size - 1);
    // PrintArray(array);
    //
    // array.DeAllocate();
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

    vector<int> ivector = RandomizeArray(size);

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
