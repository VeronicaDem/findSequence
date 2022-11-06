#pragma once
#include <utility>
#include <vector>
using namespace std;
class FindSequenceUtil
{
private:
	bool found = false;
public:
	pair<int, int> getStartAndEndIndex(vector<int> vect);
	bool isFound();
};

