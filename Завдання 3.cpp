#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("numbers.txt");
    int n, sum = 0;

    while (fin >> n) { // зчитування числа
        sum += n;
    }

    cout << "Сума чисел: " << sum << endl;
    fin.close();
}