#include <iostream>
#include <ctime>
#include "Matrix.h"
using namespace std;

ostream& operator<<(ostream& os, const E& obj) {
    os << obj.getValue(0, 0);
    return os;
}

istream& operator>>(istream& is, E& obj) {
    int num;
    is >> num;
    obj.setValue(num);
    return is;
}

int main() {
    srand(unsigned(time(NULL)));
    int size1, size2;

    do {
        cout << "Enter rows: ";
        cin >> size1;
        if (size1 <= 1) {
            cout << "The rows cannot be less than 2" << endl;
        }
    } while (size1 <= 1);

    do {
        cout << "Enter cols: ";
        cin >> size2;
        if (size2 <= 1) {
            cout << "The cols cannot be less than 2" << endl;
        }
    } while (size2 <= 1);

    Matrix<E> m1(size1, size2);
    Matrix<E> m2(size1, size2);
    Matrix<E> m3(size1, size2);

    cout << "Matrix with random values:" << endl;
    m3.FillRandom();
    m3.Print();
    cout << endl;

    cout << "First matrix:" << endl;
    m1.Input();
    m1.Print();

    cout << "Second matrix:" << endl;
    m2.Input();
    m2.Print();

    Matrix<E> Addition = m1.AddMatr(m2);
    cout << "Matrix1 + Matrix2:" << endl;
    Addition.Print();

    Matrix<E> Addition1 = m1.AddNum(5);
    cout << "Matrix1 + number:" << endl;
    Addition1.Print();

    Matrix<E> Subtraction = m1.DiffMatr(m2);
    cout << "Matrix1 - Matrix2:" << endl;
    Subtraction.Print();

    Matrix<E> Subtraction1 = m1.DiffNum(2);
    cout << "Matrix1 - num:" << endl;
    Subtraction1.Print();

    Matrix<E> Division = m1.DivMatr(m2);
    cout << "Matrix1 / Matrix2:" << endl;
    Division.Print();

    Matrix<E> Division1 = m1.DivNum(2);
    cout << "Matrix1 / num:" << endl;
    Division1.Print();

    Matrix<E> Multiply = m1.MultMatr(m2);
    cout << "Matrix1 * Matrix2:" << endl;
    Multiply.Print();

    Matrix<E> Multiply1 = m1.MultNum(2);
    cout << "Matrix1 * num:" << endl;
    Multiply1.Print();

    cout << "Max on first matrix: " << m1.findMax() << endl;
    cout << "Max on second matrix: " << m2.findMax() << endl;
    cout << "Min on first matrix: " << m1.findMin() << endl;
    cout << "Min on second matrix: " << m2.findMin() << endl;
    cout << "Count: " << Matrix<E>::count << endl;
    return 0;
}