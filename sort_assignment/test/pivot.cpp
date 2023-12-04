#include <iostream>

using namespace std;

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


int main() {

	// Size is 10
	int array[] = {6, 3, 12, 10, 17, 4, 6, 7, 2, 14};

	int n = 10;

	int pivot_index = select_pivot(array, n);
	
	cout << "Pivot is: " << array[pivot_index] << " at index: " << pivot_index << endl;

	return 0;

}
