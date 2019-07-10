#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void p_vect(vector<string> v) {
    int m = 1;
    string ts;
    for ( auto &i : v ) {
        ts = to_string(m);
        cout << m << ": " << i << endl;
        m++;
    }
}

int main () {
    // File open
    fstream myfile;
    myfile.open("data.txt", fstream::in | fstream::out);

    // String array
    vector<string> arr;
    string line;

    // read to do list from file
    if (myfile.is_open()) {
        while(getline(myfile, line)) {
            arr.push_back(line);
        }
    }

    // print file
    p_vect(arr);

    // separate list from options
    if ( arr.size() != 0) {
        cout << "\n" << endl;
    }

    // main loop of program
    int q = 0;
    string new_task;
    int num;
    do {
        // give user options
        int k;
        cout << "Please select what task you want to do" << endl;
        cout << "Enter a number to chose" << endl;
        cout << "1: Reprint todo list" << endl;
        cout << "2: Add to list" << endl;
        cout << "3: Remove from list" << endl;
        cout << "Anything else to quit" << endl;
        cin >> k;
        cout << "" << endl;

        // perform tasks
        switch (k) {
            case (1):
                p_vect(arr);
                cout << "" << endl;
                break;
            case (2):
                cout << "Enter task: " << endl;
                cin >> new_task;
                arr.push_back(new_task);
                myfile << "this\n";
                cout << "" << endl;
                break;

            case (3):
                cout << "Remove from list" << endl;
                break;

            default:
                cout << "Quitting" << endl;
                q = 1;
                break;
        }
    } while (q == 0);
    //close file
    myfile.close();
    return 0;
}