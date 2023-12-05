#include <iostream>

using namespace std;

#define DEBUG 1

void insertion(int *data_array, int array_size) {

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

int select_pivot(int *array, int n) {

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

void swap(int *array, int index1, int index2) {

	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;

}

void printArray(int *array, int size) {

	for (int i = 0; i < size; i++) {

		cout << array[i] << " ";

	}

	cout << endl;

}

int partition(int *array, int n, int pivot_index) {

	// 1: Swap pivot with last index
	swap(array, pivot_index, n-1);
	
	#if DEBUG
	//printArray(array, n);
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

			// If it found a value greater than or equal to pivot, stop
			if (array[i] >= array[n-1]) {

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
		//printArray(array, n);
		#endif

	}

	#if DEBUG
	//printArray(array,n);
	#endif

	// Return the new pivot index
	return i;

}


void quick(int *array, int size) {

	// 1: Check array size. If 1 or less, we're done.
	if (size == 1) {

		#if DEBUG
		cout << "Done\n";
		#endif

	}
	else {

		// 2. Select pivot
		int pivot_index = select_pivot(array, size);
		
		#if DEBUG
		cout << "Running quicksort on array: ";
		printArray(array,size);
		cout << "Pivot selected: " << array[pivot_index] << " at index: " << pivot_index << endl << endl;
		#endif


		// 3. Partition List
		pivot_index = partition(array, size, pivot_index);
		
		#if DEBUG
		cout << "Array after partitioning: ";
		printArray(array, size);
		cout << "Pivot after partitioning: " << array[pivot_index] << " at index: " << pivot_index << endl << endl;
		#endif

		
		// 4. Run quicksort recursively
		// If pivot is last element in array, run quicksort on only the left side
		if (pivot_index == size-1) {
	
			#if DEBUG
			cout << "Running Quicksort on left side.\n";
			cout << "\tSize is : " << size << endl;
			cout << "\tPivot index is: " << pivot_index << endl;
			#endif

	
			quick(array, size-1);

		}
		// If pivot is first element in array, run quicksort on only the right side
		else if (pivot_index == 0) {

			#if DEBUG
			cout << "Running Quicksort on right side\n";
			cout << "\tSize is : " << size << endl;
			cout << "\tPivot index is: " << pivot_index << endl;
			#endif


			quick(array+1, size-1);

		}
		// Else, run quicksort on both sides
		else {
		
			#if DEBUG
			cout << "Running quicksort on left side, then right side\n";
			cout << "\tSize is : " << size << endl;
			cout << "\tPivot index is: " << pivot_index << endl;
			#endif


			// Left side
			#if DEBUG
			cout << "Left side first" << endl;
			#endif
			quick(array, pivot_index);
			
			// Right side
			#if DEBUG
			cout << "Then right side" << endl;
			#endif
			quick(array + pivot_index + 1, size - pivot_index - 1);

		}
	}

}

int main() {

	int array[] = {6, 3, 12, 10, 17, 4, 6, 7, 2, 14};

	int n = 10;

	quick(array, n);

	printArray(array, n);

	return 0;

}
