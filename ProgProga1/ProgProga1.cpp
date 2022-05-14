// ProgProga1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "code.h"
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    string filename;
    pair <int, int> myElement;
    HashArray array;
    ifstream in;
    ofstream out;
    if (argc != 3)
    {
        while (in.is_open() != true)
        {
            cout << "Input file name \n";
            cin >> filename;
            in.open(filename);
            cout << "Input file can't be opened";
        }
        while (out.is_open() != true)
        {
            cout << "Output file name \n";
            cin >> filename;
            out.open(filename);
            cout << "Output file can't be opened";
        }
    }
    else
    {
        filename = argv[1];
        in.open(filename);
        filename = argv[2];
        out.open(filename);
        while (in.is_open() != true)
        {
            cout << "Input file name \n";
            cin >> filename;
            in.open(filename);
            cout << "Input file can't be opened";
        }
        while (out.is_open() != true)
        {
            cout << "Output file name \n";
            cin >> filename;
            out.open(filename);
            cout << "Output file can't be opened";
        }
    }
    array.fillContainer(in);
    array.saveContainer(out);
    array.sortElements();
    array.showContainer();
    out << "Total number of objects: " << array.getCountOfElements() << "\n";
    return 0;
}
