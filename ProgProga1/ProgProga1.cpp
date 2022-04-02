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
        int radius, heigth, width, depth = 0;
        in >> radius >> heigth;
        in >> width >> depth;
        if (radius == 0)
            if (heigth != 0)
            {
                Shape tmp(heigth, width, depth);
                myElement = array.addElement(tmp);
                cout << "Element number " << i << ": ";
                cout << tmp.getHeigth() << ", ";
                cout << tmp.getWidth() << ", ";
                cout << tmp.getDepth() << ". That's a parallelepiped.\n";
            }
            else cout << "Element number " << i << " is empty\n";
        else
            if (heigth != 0)
                cout << "Element number " << i << " is broken. It has both radius and heigth\n";
            else
            {
                Shape tmp(radius);
                myElement = array.addElement(tmp);
                cout << "Element number " << i << ": ";
                cout << tmp.getRadius() << ". That's a sphere.\n";
            }
    }
    int counter = 0;
    for (int i = 0; i < 30; i++)
    {
        Shape tmp;
        if (array.getSizeOfVector(i) != 0)
        {
            int size = array.getSizeOfVector(i);
            for (int j = 0; j < size; j++)
            {
                tmp = array.getElement(i, j);
                if (tmp.getRadius() == 0)
                    if (tmp.getHeigth() != 0)
                    {
                        out << "Element number " << counter << " is a parallelepiped with edges: ";
                        out << tmp.getHeigth() << ", ";
                        out << tmp.getWidth() << ", ";
                        out << tmp.getDepth() <<"\n";
                    }
                    else out << "Element number " << counter << " is empty\n";
                else
                    if (tmp.getHeigth() != 0)
                        out << "Element number " << counter << " is broken. It has both radius and heigth\n";
                    else
                    {
                        out << "Element number " << counter << " is a sphere with radius: ";
                        out << tmp.getRadius() << "\n";
                    }
            }
        }
    }
    out << "Total number of objects: " << counter << "\n";
    cout << "228";
    return 0;
}
