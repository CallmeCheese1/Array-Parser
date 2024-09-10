#include "arrayparser.h"
#include <iostream>

int main() {

    int* array = nullptr; //Define the array with a fixed size, ASSUMING that our file will only have a hundred numbers max.
    int size = 0; //This is a surprise tool we'll use later. Call it foreshadowing.

    readDataFromFile("data.txt", array, size); //This is us using the surprise tool, int size. It'll read from data.txt into the array array, and increase the size as necessary.

    std::cout << "Data read from file: " << std::endl;

    for (int i = 0; i < size; ++i) {
        std:: cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Where does 10 exist? Index " << doesIntegerExist(10, array, size) << std::endl;
    
    changeIntAtIndex(123456789, doesIntegerExist(10, array, size), array, size);
    
    for (int i = 0; i < size; ++i) {
        std:: cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    addNewInt(69420, array, size);
    
    for (int i = 0; i < size; ++i) {
        std:: cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Running the last weird function at index 9, to remove it!" << std::endl;
    theWeirdOne(9, array, size, true);
    
    for (int i = 0; i < size; ++i) {
        std:: cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Now, running the last weird function at index 10, to 0 it." << std::endl;
    theWeirdOne(10, array, size, false);
    
    for (int i = 0; i < size; ++i) {
        std:: cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}