// find_sequence.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "FileReader.h"
#include "Sequence.h"
int main()
{
    FileReader * fileReader = new FileReader("C:\\Users\\Nica\\Documents\\cpp_projects\\file1.txt");
    /*while (fileReader->hasNext()) {
        std::cout << fileReader->getNext();
    }
    fileReader->close();*/
    //Sequence* seq = new Sequence();
   // cout << "Input sequence (-1 to stop)" << endl;
   /* int curElem;
    cin >> curElem;
    while (curElem != -1) {
        seq->addElem(curElem);
        cin >> curElem;
    }*/
    int elem = fileReader->getNext();
    while (elem != FileReader::ERROR_NEXT) {
        cout << "curElem: " << elem << endl;
        elem = fileReader->getNext();
    }
    fileReader->close();

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
