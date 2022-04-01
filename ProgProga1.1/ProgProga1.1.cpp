#include <iostream>
#include "code.h"
#include <vector>
#include <fstream>

using namespace std;
struct lol
{
    string a;
    string b;
};
struct lol2
{
    string d;
    string e;
};
union kekw
{
    lol* a;
    lol2* b;
    kekw()
    {
        a = new lol;
    }
    ~kekw()
    {
        delete a;
    }
};

int main()
{
    kekw kek;
    kek.a->a = "asda";
    kek.b->e = "3123";
    
    std::cout << kek.b->d << kek.a->b;
}

