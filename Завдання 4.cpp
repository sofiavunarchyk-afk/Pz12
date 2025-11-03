#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("students.txt");
    string name; 
    int grade; 
    int count = 0;

    while (getline(fin, name, ',') >> grade) { // зчитування імені та оцінки
        if (grade >= 90) { // перевірка оцінки >= 90
            count++;   // збільшення лічильника
        }
    }

    cout << "Кількість студентів зі стипендією: " << count << endl;
    fin.close();
}