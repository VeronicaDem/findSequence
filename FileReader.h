#pragma once
#include <string>
#include <fstream>
using namespace std;
class FileReader {
private:
	string filePath;
	fstream fileStream;
	int offsetBuffer = 0;
	char buffer[256] = "";
	int convertToInt(char ch);
	bool hasNext();
public:
	static int ERROR_NEXT;
	int getNext();
	FileReader(string filePath);
	void close();
};
