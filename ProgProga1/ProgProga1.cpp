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
        cout << "Input file name \n";
        cin >> filename;
        in.open(filename);
        cout << "Output file name \n";
        cin >> filename;
        out.open(filename);
    }
    else
    {
        filename = argv[1];
        in.open(filename);
        filename = argv[2];
        out.open(filename);
    }
    int n = 0;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        int type = 0;
        in >> type;
        switch (type)
        {
            case 0:
            {
                int radius = 0;
                in >> radius;
                Sphere *tmp = new Sphere(radius);
                cout << "Element number " << i << ": ";
                cout << tmp->getRadius() << ". That's a sphere.\n";
                myElement = array.addElement(tmp);
                break;
            }
            case 1:
            {
                int heigth, width, depth = 0;
                in >> heigth >> width >> depth;
                Parallelepiped* tmp = new Parallelepiped(heigth, width, depth);
                cout << "Element number " << i << ": ";
                cout << tmp->getHeigth() << ", ";
                cout << tmp->getWidth() << ", ";
                cout << tmp->getDepth() << ". That's a parallelepiped.\n";
                myElement = array.addElement(tmp);
                break;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < 30; i++)
    {
        if (array.getSizeOfVector(i) != 0)
        {
            int size = array.getSizeOfVector(i);
            for (int j = 0; j < size; j++)
            {
                Shape* tmp = array.getElement(i, j);
                tmp->outElement(out, counter);
                counter++;
            }
        }
    }
    out << "Total number of objects: " << counter << "\n";
    return 0;
}
