
#ifndef SORTS_HPP
#define SORTS_HPP

using namespace std;

#define DEBUG 0
 
class Sorts
{
  public:
  void bubble(int*, int);
  
  void insertion(int*, int);
  void quick(int*, int);
  
  // Any Other Function you want to declare

  private:
  int select_pivot(int *array, int n);
  void swap (int *array, int index1, int index2);
  void printArray(int *array, int size);
  int partition(int *array, int n, int pivot_index);
	  // Any Variables you will need

};


// IMPLEMENTATION --- YOUR CODE

void Sorts::bubble(int *data_array, int array_size) {

	for (int i = 0; i < array_size - 1; i++) {

		for (int j = 0; j < array_size - 1 - i; j++) {

			// If adjacent neighbors are out of order, swap them
			if (data_array[j] > data_array[j+1]) {

				int temp = data_array[j];
				data_array[j] = data_array[j+1];
				data_array[j+1] = temp;

			}

		}

	}	

}

void Sorts::insertion(int *data_array, int array_size) {

	// Loop from index 1 to array_size - 1
	for (int pass = 1; pass < array_size; pass++) {

		// Compare value at current pass index with all previous values.
		// Put the value at current pass index in its correct spot in the ordered list
		for (int i = 0; i < pass; i++ ) {

			if (data_array[pass] < data_array[i]) {

				// Swap them
				int temp = data_array[pass];
				data_array[pass] = data_array[i];
				data_array[i] = temp;

			}

		}

	}

} 

int Sorts::select_pivot(int *array, int n) {

	int left = array[0];
	int right = array[n-1];
	int center_index = (n-1)/2;
	int center = array[center_index];

	int pivot_index = 0;

	// If left is median,
	if (left > right && left < center || left < right && left > center) {

		pivot_index = 0;

	}
	// Else if right is median,
	if (right > left && right < center || right < left && right > center) {

		pivot_index = n-1;

	}
	// Else center is median
	else {

		pivot_index = center_index;

	}
	
	return pivot_index;

}

void Sorts::swap(int *array, int index1, int index2) {

	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;

}

void Sorts::printArray(int *array, int size) {

	for (int i = 0; i < size; i++) {

		cout << array[i] << " ";

	}

	cout << endl;

}

int Sorts::partition(int *array, int n, int pivot_index) {

	// 1: Swap pivot with last index
	swap(array, pivot_index, n-1);
	
	#if DEBUG
	printArray(array, n);
	#endif

	// 2: We need iterators i and j
	// i advances from left until it finds a value greater than pivot
	// j advances from right until it finds a value less than pivot
	// If i and j have crossed,
		// swap i with pivot
	// Else,
		// swap i and j
	int i = 0;
	int j = n-2;
	while (true) {

		// Advance i
		while (i < n-1) {

			// If it found a value greater than pivot, stop
			if (array[i] > array[n-1]) {

				break;

			}

			// Else, advance
			else {

				i++;

			}

		}

		// Advance j
		while (j > 0) {

			// If it found a value less than pivot, stop
			if (array[j] < array[n-1]) {

				break;

			}

			// Else, advance
			else {

				j--;

			}

		}

		// If i == n-1, everything is less than the pivot

		// If j == 0, everything is greater than the pivot
		
		// If i and j have crossed,
		if (i >= j) {

			// Swap i with pivot
			swap(array, i, n-1);

			// Break out of loop
			break;

		}
		else {

			// Swap i and j
			swap(array, i, j);

		}

		#if DEBUG
		printArray(array, n);
		#endif

	}

	#if DEBUG
	printArray(array,n);
	#endif

	// Return the new pivot index
	return i;

}


void Sorts::quick(int *array, int size) {

	// 1: Check array size. If 20 or less, run insertion sort.
	if (size <= 20) {

		insertion(array, size);

	}
	else {

		// 2. Select pivot
		int pivot_index = select_pivot(array, size);
	
		// 3. Partition List
		pivot_index = partition(array, size, pivot_index);

		// 4. Run quicksort on both sides of partition if applicable.


	}

}

#endif
