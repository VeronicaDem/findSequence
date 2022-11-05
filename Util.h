#pragma once
#include <vector>
#include "FileReader.h"
#include "FileWriter.h"
using namespace std;
class Util
{
public:
	static int getTriad(int a, int b, int c);
	static vector<int> constructVector(FileReader * file);
	static void printVector(vector<int> vect, int startIndex, int endIndex);
	static FileReader* writeRandom(FileWriter * fileWriter, int sizeElems);
};

