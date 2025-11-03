#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
    ofstream fout("students.txt"); 
    string name = "Іваненко Іван";
    double grade = 95;

    fout << name << "," << grade << endl; // запис
    fout.close();

    ifstream fin("students.txt");
    string line;
    while (getline(fin, line)) { // читання рядка
        cout << line << endl;
    }
    fin.close();
}