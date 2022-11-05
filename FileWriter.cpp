#include "FileWriter.h"
#include <charconv>
void FileWriter::write(int elem) {
	if (this->fileStream.is_open()) {
		this->fileStream << elem;
	}
}
void FileWriter::close() {
	if (this->fileStream.is_open()) this->fileStream.close();
}
FileWriter::FileWriter(string filePath) {
	this->fileStream.open(filePath, ios::out);
	this->filePath = filePath;
};
string FileWriter::getFilePath() {
	return this->filePath;
}