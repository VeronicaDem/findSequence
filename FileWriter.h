#pragma once
#include <fstream>
#include <string>
using namespace std;
class FileWriter
{
private:
	fstream fileStream;
	string filePath;
public:
	void write(int elem);
	void close();
	FileWriter(string filePath);
	string getFilePath();
};

