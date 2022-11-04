#pragma once
#include <vector>
using namespace std;
class Sequence
{
private:
	int offset = 0;
	int * elemsInSeq;
	int length = 0;
public:
	bool existElemInPos(int elem);
	Sequence();
	void addElem(int elem);
	bool isBound();
	bool isEmpty();
	int size();
};

