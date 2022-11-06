// find_sequence.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "FileReader.h"
#include "Util.h"
#include "FindSequenceUtil.h"

#include <chrono>
using namespace std::chrono;

const int ITERATIONS = 100;
int main()
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        FileReader* fileReader = new FileReader("C:\\Users\\Nica\\Documents\\cpp_projects\\input.txt");
        vector<int> elems = Util::constructVector(fileReader);
        FindSequenceUtil * findSeqUtil = new FindSequenceUtil();
        pair<int, int> pairIndex = findSeqUtil->getStartAndEndIndex(elems);
        if (findSeqUtil->isFound()) {
            cout << "Found" << endl;
            Util::printVector(elems, pairIndex.first, pairIndex.second);
        }
        else {
            cout << "No found" << endl;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "ms: " << endl;
    cout << duration.count() / ITERATIONS << endl;
}

