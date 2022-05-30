#include <iostream>
using namespace std;
#include"Vector.h"

int main()
{
    Vector v(8);
    v.push_back(10);
    v.push_back(20);
    v.push_front(5);
    v.push_front(1);
    v.push_back(1);
    //cout << v.rfind(1) << endl;
    //cout << v.find(1) << endl;
    //v.insert_by_index(1, 15);
    //v.delete_by_index(1);
    //v.pop_front();
    //v.pop_back();
    v.print();
}
