#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("students.txt");
    if (!fin) {
        cout << "Не вдалося відкрити файл students.txt" << endl;
        return 1;
    }

    ofstream fout("report.txt"); 
    if (!fout) {
        cout << "Не вдалося створити файл report.txt" << endl;
        return 1;
    }

    string surname, name;
    int grade, dorm, extra; // extra - зайве число з файлу
    int countScholar = 0, countDorm = 0, total = 0, n = 0;

    // Заголовок
    cout << "№  ПІБ студента      Бал  Гурт  Стипендія  Гуртожиток\n";
    fout << "№  ПІБ студента      Бал  Гурт  Стипендія  Гуртожиток\n";

    while (fin >> surname >> name >> grade >> dorm >> extra) {
        n++;
        total += grade;

        // Вивід на екран
        cout << n << "  " << surname << " " << name << "  " << grade << "    " << dorm << "    ";
        // Запис у файл
        fout << n << "  " << surname << " " << name << "  " << grade << "    " << dorm << "    ";

        if (grade >= 90) {
            cout << "✅";
            fout << "✅";
            countScholar++;
        } else {
            cout << "  ";
            fout << "  ";
        }

        if (dorm == 1) {
            cout << "★";
            fout << "★";
            countDorm++;
        }

        cout << endl;
        fout << endl;
    }

    double avg = n > 0 ? (double)total / n : 0;

 
    cout << "\nКількість студентів зі стипендією: " << countScholar << endl;
    cout << "Кількість студентів у гуртожитку: " << countDorm << endl;
    cout << "Середній бал групи: " << avg << endl;

  
    fout << "\nКількість студентів зі стипендією: " << countScholar << endl;
    fout << "Кількість студентів у гуртожитку: " << countDorm << endl;
    fout << "Середній бал групи: " << avg << endl;

    fin.close();
    fout.close();

    cout << "\nРезультати також записані у файл report.txt" << endl;

    return 0;
}