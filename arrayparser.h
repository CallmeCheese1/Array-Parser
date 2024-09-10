#ifndef ARRAYPARSER_H
#define ARRAYPARSER_H

#include <string>

void readDataFromFile(const std::string& filename, int*& array, int& size);

int doesIntegerExist(const int num, const int* array, const int size);

void changeIntAtIndex(const int num, const int index, int* array, const int size);

void addNewInt(const int new_num, int*& array, int& size);

void theWeirdOne(int index, int*& array, int& size, bool flag);

#endif