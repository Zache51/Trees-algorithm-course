#include <SFML/Graphics.hpp>
#include "TernaryTree.h"
#include "sorting.h"

#include <iostream>

int main(int argc, char* argv[])
{
	Sorting sorting;
	bool error = true;

	if (argc == 3)
	{
		if (std::string(argv[1]) == "quicksort")
		{
			error = false;
			sorting.QuickSort(std::atoi(argv[2]));
		}
		else if (std::string(argv[1]) == "mergesort")
		{
			error = false;
			sorting.MergeSort(std::atoi(argv[2]));
		}
	}

	if (error)
	{
		std::cerr << "Usage: " << argv[0] << " quicksort [size]" << std::endl;
		std::cerr << "or" << std::endl;
		std::cerr << "Usage: " << argv[0] << " mergesort [size]" << std::endl;
		return 1;
	}

	return 0;
}
