#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a = 42;
int* p;

void printA () {
    cout << "a: " << a << endl;
}

void printP () {
    cout << "p: " << p << " *p: " << *p << endl;
}

void addOne (int& q) {
    q = q + 1;
    cout << "q: " << q << endl;
}

int* makeAnInt (int a) {
    int* p = new int;
    *p = a;
    return p;
}

struct person {
    string name;
    int height, age;
};

int main () {
    int arr [5] = {1, 2, 3, 4, 5};
    // person tom;
    int* arrp = arr;

    cout << "arr: " << arr << " *arr: " << *arr << endl;
    cout << "arrp: " << arrp << " *arrp: " << *arrp << endl;

    cout << "*(arrp+2): " << *(arrp+2) << " arrp[2]: " << arrp[2] << endl;

    int w = 4;
    addOne(w);
    cout << "w: " << w << endl;

    vector<int*> myInts;

    for (int i = 0; i < 10; i++) {
        int* myNewInt = makeAnInt(i*i);
        myInts.push_back(myNewInt);
    }

    for (int i = 0; i < 10; i++) {
        cout << "myInts[" << i << "]: " << myInts[i] << "*myInts[" << i << "]: " << *myInts[i] << endl;
        delete myInts[i];
    }

    
    // for (int i = 0; i < )

    // p = &a;
    // printA();
    // (*p)++;
    // printA();

    return 0;
}