#pragma once
#include <string>
#include <fstream>
using namespace std;
class FileReader {
private:
	string filePath;
	fstream fileStream;
public:
	static int ERROR_NEXT;
	int getNext();
	FileReader(string filePath);
	bool hasNext();
	void close();
};
