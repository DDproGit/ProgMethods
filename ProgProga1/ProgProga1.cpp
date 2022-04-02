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
                Shape::type key = static_cast<Shape::type>(type);
                in >> radius;
                Sphere tmp(key, radius);
                cout << "Element number " << i << ": ";
                cout << tmp.getRadius() << ". That's a sphere.\n";
                myElement = array.addElement(tmp);
                break;
            }
            case 1:
            {
                int heigth, width, depth = 0;
                Shape::type key = static_cast<Shape::type>(type);
                in >> heigth >> width >> depth;
                Parallelepiped tmp(key, heigth, width, depth);
                cout << "Element number " << i << ": ";
                cout << tmp.getHeigth() << ", ";
                cout << tmp.getWidth() << ", ";
                cout << tmp.getDepth() << ". That's a parallelepiped.\n";
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
                Shape::type myKey = array.getElement(i, j)->key;
                if (myKey == Shape::sphere)
                {
                    Sphere* tmp = array.getSphere(i, j);
                    out << "Element number " << counter << " is a sphere with radius: ";
                    out << tmp->getRadius() << "\n";
                };
                if (myKey == Shape::parallelepiped)
                {
                    Parallelepiped* tmp = array.getParallelepiped(i, j);
                    out << "Element number " << counter << " is a parallelepiped with edges: ";
                    out << tmp->getHeigth() << ", ";
                    out << tmp->getWidth() << ", ";
                    out << tmp->getDepth() << "\n";
                };
            }
        }
    }
    out << "Total number of objects: " << counter << "\n";
    return 0;
}
