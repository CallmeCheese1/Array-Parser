#include "arrayparser.h"
#include <fstream> //Includes the file stream library, which allows us to read from files at all.
#include <sstream> //Includes the string stream libary, which allows us to read and write data to and from strings.
#include <iostream> //Might be useful if we need to cout anything for debugging!

//This is the starter function, which reads the data from data.txt into array.
void readDataFromFile(const std::string& filename, int*& array, int& size) {
	std::ifstream inputFile(filename); //Declare the object to read from the file input stream
	size = 0; //Edits the referenced size variable to start from 0
	std::string line; //This will be used to store each line as we read it, before we extract the numbers.

	// Free any existing array memory (if any)
	delete[] array;

	// Create a new array with an initial size
	array = new int[100]; // Initial size; you might want to resize if needed

	while (std::getline(inputFile, line)) { //While we're able to read more lines...
		std::stringstream ss(line); //Read strings from each line
		int num;
		while (ss >> num) { //Read the numbers from that line, and store it in num

			if (size >= 100) { // Resize if needed (initial size was 100)
				int* newArray = new int[size + 100];
				for (int i = 0; i < size; ++i) {
					newArray[i] = array[i];
				}
				delete[] array;
				array = newArray;
			}

			array[size] = num; //Store num into the index marked by the size variable -- in other words, the end of the array.
			size++; //Increase size, since we just increased the size of the variable.
		}
	}

	inputFile.close(); //Close the input file, because it's always necessary in C++ to not destroy the world.
}

//Checks if a certain integer exists, and returns the index if it does. If not, -1.
int doesIntegerExist(const int num, const int* array, const int size) {
	for (int i = 0; i < size; ++i) {
		if (array[i] == num) {
			return i; // Return the index where the integer is found
		}
	}
	return -1; // Return -1 if the integer is not found
}

//Places the number given at the specified index, and couts the old value and the new value.
void changeIntAtIndex(const int num, const int index, int* array, const int size) {
	if (index >= 0 && index < size) {
		int oldValue = array[index];

		array[index] = num;

		std::cout << "changeIntAtIndex: Old Value at Index " << index << ": " << oldValue << std::endl;
		std::cout << "changeIntAtIndex: New Value at Index " << index << ": " << array[index] << std::endl;

	} else { //The index doesn't exist
		std::cout << "changeIntAtIndex: The given index doesn't exist. Please try again." << std::endl;
		return;
	}
}

//Adds a new number at the end of the array, and increases size so the world doesn't explode.
//To be specific, we resize the array through pointer shenanigans. We create a new duplicate array that's one piece larger, add the new variable to that new array, and delete the old one while making the new version take its name. Pretty morbid.
void addNewInt(const int new_num, int*& array, int& size) {

	// Increase array size by 1
	int* newArray = new int[size + 1]; // Create new array with one extra element

	// Copy the contents of the old array to the new array
	for (int i = 0; i < size; ++i) {
		newArray[i] = array[i];
	}

	// Add the new element to the end of the new array
	newArray[size] = new_num;

	// Delete the old array to free up memory
	delete[] array;

	// Make the original pointer point to the new array. Some real bodysnatcher stuff going on here.
	array = newArray;

	std::cout << "Added " << new_num << " at index " << size << std::endl;

	// Update the size to reflect the new array size
	size++;

}

//This one's weird. So, if the flag is true, it will delete the data at that index, but if it's false, we'll just replace that index with 0.
void theWeirdOne(int index, int*& array, int& size, bool flag) {
    if (index < 0 || index > size) { //Just exits the function if we're given an index that isn't valid.
        return;
    }
    
    if (flag) { //Delete the data at that index. We'll just copy everything EXCEPT that index into a new array, and change the pointers.
        // Create new pointer array with one less element
        int* newArray = new int[size - 1];

        // Copy elements before the index from the old array into the new array
        for (int i = 0; i < index; ++i) {
            
            newArray[i] = array[i];
            
        }

        // Copy elements AFTER the index, thereby removing this index from the array.
        for (int i = index + 1; i < size; ++i) {
            
            newArray[i - 1] = array[i];
            
        }

        // Bodysnacher time. Delete the old array, and claim its name.
        delete[] array;
        
        array = newArray;
        
        //Reduce size by 1.
        --size;
        
    } else { //Since it's false, just replace that index with 0.
        array[index] = 0;
    }
}