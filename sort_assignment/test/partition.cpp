#include <iostream>

using namespace std;

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

void partition(int *array, int n, int pivot_index) {

	// 1: Swap pivot with last index
	swap(array, pivot_index, n-1);
	
	printArray(array, n);

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

		printArray(array, n);

	}

	printArray(array,n);

}

int main() {

	int n = 10;
	int array[n] = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
	int pivot_index = 9;

	partition(array, n, pivot_index);	
	

return 0;
}
