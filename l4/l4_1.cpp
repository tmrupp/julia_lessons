#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int CAPACITY = 100;

struct person {
    string name;
    int height, age;
};

struct database {
    person* data [CAPACITY]; //person** data;
    int size = 0;
};

void addPerson (database* db, string name, int height, int age) {
    //make a new person, and make sure we don't lose it so we use new
    person* p = new person; // db->something = *(db).something

    //assign all of the values
    p->age = age;
    p->height = height;
    p->name = name;

    if (db->size == CAPACITY) //if size is already equal to capacity we can't take another
        cout << "reached capacity!" << endl;

    db->data[db->size] = p; //add the new person to the end
    db->size += 1; //increase the size
}

void removePerson (database* db, string name) {
    bool shift = false;
    for (int i = 0; i < db->size; i++) {
        if (db->data[i]->name == name) { // remove this guy
            delete db->data[i]; // frees that memory
            shift = true; // starts shifting the data over to fill the hole
            db->size--; // this both ensures the correct size but also makes sure that the last item doesn't grab nonsense
        }
        
        if (shift)
            db->data[i] = db->data[i+1]; //if we are shifting, shift it over!
    }

    if (!shift) 
        cout << "They were never here!" << endl; //if we never shift the name wasn't in our database
}

void printDataBase (database* db) {
    //prints out the contents of the database for easy debugging
    for (int i = 0; i < db->size; i++)
        cout << "db[" << i << "][name=" << db->data[i]->name << "][age=" << db->data[i]->age << "][height=" << db->data[i]->height << "]\n"; 
}

int main () {
    fstream fin;
    fin.open("people.in"); //This makes input easier

    database db;

    while (!fin.eof()) { //While not at the end of the file
        string n;
        int a, h;
        fin >> n >> h >> a; //read in the stuff
        addPerson(&db, n, h, a); //add it to the database
    }

    printDataBase(&db);

    removePerson(&db, "Frodo");
    cout << "removed Frodo!" << endl;

    printDataBase(&db);

    removePerson(&db, "Bill");

    printDataBase(&db);
    

    return 0;
}