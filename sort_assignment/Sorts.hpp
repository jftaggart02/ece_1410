
#ifndef SORTS_HPP
#define SORTS_HPP
 
class Sorts
{
  public:
  void bubble(int*, int);
  
  //void insertion(int*, int);
  //void quick(int*, int);
  
  // Any Other Function you want to declare

  private:

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

#endif
