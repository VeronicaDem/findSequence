// find_sequence.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "FileReader.h"
#include "Util.h"
#include "FindSequenceUtil.h"

#include <chrono>
using namespace std::chrono;

// Use auto keyword to avoid typing long
// type definitions to get the timepoint
// at this instant use function now()
const int ITERATIONS = 100;
int main()
{
   // FileWriter* fileWriter = new FileWriter("C:\\Users\\Nica\\Documents\\cpp_projects\\random_file_big.txt");
   // FileReader* fileReader = Util::writeRandom(fileWriter, 1000000);
   // fileReader->close();
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

    // To get the value of duration use the count()
    // member function on the duration object
    cout << "ms: " << endl;
    cout << duration.count() / ITERATIONS << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
