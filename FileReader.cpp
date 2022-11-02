
#include <string>
#include <fstream>
#include <iostream>
#include "FileReader.h"
using namespace std;

int FileReader::ERROR_NEXT = -1;
static int ERROR_NEXT;
int FileReader::getNext() {
	int result = ERROR_NEXT;
	if (this->fileStream.is_open()) {
		//this->fileStream.open(this->filePath);
		if (hasNext()) {
			this->fileStream >> result;
		}
	}
	return result;
};
FileReader::FileReader(string filePath) {
	this->filePath = filePath;
	this->fileStream.open(filePath, ios::in);
};
bool FileReader::hasNext() {
	return !this->fileStream.eof();
};
void FileReader::close() {
	if (this->fileStream.is_open()) this->fileStream.close();
}