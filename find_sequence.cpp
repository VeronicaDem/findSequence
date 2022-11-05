// find_sequence.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "FileReader.h"
#include "Util.h"

#include <chrono>
using namespace std::chrono;

// Use auto keyword to avoid typing long
// type definitions to get the timepoint
// at this instant use function now()

int main()
{
   // FileWriter* fileWriter = new FileWriter("C:\\Users\\Nica\\Documents\\cpp_projects\\random_file_big.txt");
   // FileReader* fileReader = Util::writeRandom(fileWriter, 1000000);
   // fileReader->close();
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        FileReader* fileReader = new FileReader("C:\\Users\\Nica\\Documents\\cpp_projects\\random_file_big.txt");
        vector<int> elems = Util::constructVector(fileReader);
        // saved no-pair elems
        bool found = false;
        int indexLast = 2;
        int aX, bX, cX;
        aX = bX = cX = -1;
        int startSeq = -1;
        int endSeq = -1;
        int xxx, yyy;
        xxx = yyy = -1;
        while (!found && indexLast < elems.size()) {
            if (aX == bX == cX == -1) {
                aX = elems[indexLast - 2];
                bX = elems[indexLast - 1];
            }
            else {
                aX = bX;
                bX = cX;
            }
            cX = elems[indexLast];
            xxx = Util::getTriad(aX, bX, cX);
            int testYYY = xxx * 2;
            for (int i = indexLast + 1; i < elems.size() - 2; i++) {
                int aY = elems[i];
                int bY = elems[i + 1];
                int cY = elems[i + 2];
                int yyy = Util::getTriad(aY, bY, cY);
                if (testYYY == yyy) {
                    startSeq = indexLast + 1;
                    endSeq = i - 1;
                    found = true;
                    break;
                }
            }
            indexLast++;
        }
        if (found) {
            cout << "Found" << endl;
            Util::printVector(elems, startSeq, endSeq);
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
    cout << duration.count() / 10000 << endl;
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
