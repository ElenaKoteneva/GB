/* Koteneva Elena
 * Lesson 7
*/

#include <iostream>

//Task 1

#define ISINRANGE(X,Y) ((X) >= 0 && (X) < (Y) ? 1 : 0)

//Task 2

#define ARRAY_EL(array,X,Y) (*(*((array) + (Y)) + (X))) 

// Task 3

#define QUANTITY(ARRAY,TYPE) (sizeof(ARRAY) / sizeof(TYPE))

int main(){
	
	std::cout << ISINRANGE(5,10) << "\n";
	
	int** matrix = new int*[100] {};
	for (int i = 0; i<100; i++){
		matrix[i] = new int[100] {};	
	}
	matrix[50][15] = 125;
	std::cout << ARRAY_EL(matrix,15,50) << "\n";

	int array[100]{};
	std::cout << QUANTITY(array,int) << "\n";
	
	return 0;	
}