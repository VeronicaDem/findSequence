#include "Util.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
vector<int> Util::constructVector(FileReader * fileReader) {
    int elem = fileReader->getNext();
    vector<int> result;
    while (elem != FileReader::ERROR_NEXT) {
        result.push_back(elem);
        elem = fileReader->getNext();
    }
    fileReader->close();
    return result;
}
int Util::getTriad(int a, int b, int c) {
    return a * 100 + b * 10 + c;
}
void Util::printVector(vector<int> vect, int startIndex, int endIndex) {
    for (int i = startIndex; i <= endIndex; i++) {
        cout << vect[i];
    }
    cout << endl;
}
FileReader* Util::writeRandom(FileWriter* fileWriter, int sizeElems) {
    std::srand(std::time(0));
    for (int i = 0; i < sizeElems; i++) {
        int random_variable = std::rand();
        fileWriter->write(random_variable);
    }
    fileWriter->close();
    return new FileReader(fileWriter->getFilePath());
}
