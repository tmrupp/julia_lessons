#include <iostream>
#include <string>

using namespace std;

struct person {
    string name;
    int height, age;
};

double averageAge (person p[], int numberOfPeople) {
    double sum = 0.0;
    for (int i = 0; i < numberOfPeople; i++) {
        sum += (double) p[i].age;
    }
    double average = sum / numberOfPeople;
    return average;
}

int main () {
    person people [8];
    int n;
    cout << "How many people: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        
        cout << "Enter a name: ";
        cin >> input;
        people[i].name = input;

        cout << "Enter " << people[i].name << "'s age: ";
        cin >> input;
        people[i].age = stoi(input);

        cout << "Enter " << people[i].name << "'s height in ft: ";
        cin >> input;
        people[i].height = stoi(input);

        cout << people[i].name << " is " << people[i].height << " ft tall and " << people[i].age << " years old" << endl;
    }

    cout << averageAge(people, n) << endl;

    ////////////////////////////////////////////////////////////////

    // char lastName [8]; // char = 8-bit number = byte 
    // char doNotTouchMe = 'd';
    // string name;
    // cin >> name;
    // cin >> lastName;

    // if (name.length() != 0) {
    //     cout << "Hello " << name << " " << lastName << endl;
    //     cout << doNotTouchMe << endl;
    // } else {
    //     cout << "Please Enter a Real Name!" << endl;
    // }

    ////////////////////////////////////////////////////////////////

    // int nums [5];
    // int thing = 1000000;

    // for (int i = 0; i < 5; i++) {
    //     cin >> nums[i];
    // }

    // int sum = 0;
    // for (int i = 0; i < 6; i++) {
    //     cout << nums[i] << endl;
    //     sum += nums[i];
    // }

    // cout << sum << endl;

    return 0;
}