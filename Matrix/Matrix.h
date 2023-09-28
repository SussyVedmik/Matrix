#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class E {
    int k;
public:
    E() = default;
    E(int val) {
        k = val;
    }
    int getValue(int r, int c) const {
        return k;
    }
    void setValue(int val) {
        k = val;
    }
    E& operator=(int a) {
        k = a;
        return *this;
    }
    E operator+(int num) {
        return E(k + num);
    }
    E operator+(const E& obj) {
        return E(k + obj.k);
    }
    E operator-(int num) {
        return E(k - num);
    }
    E operator-(const E& obj) {
        return E(k - obj.k);
    }
    E operator*(int num) {
        return E(k * num);
    }
    E operator*(const E& obj) {
        return E(k * obj.k);
    }
    E operator/(double num) {
        return E(k / num);
    }
    E operator/(const E& obj) {
        if (obj.k != 0) {
            return E(k / obj.k);
        }
        return E();
    }
    bool operator>(const E& obj) const {
        return k > obj.k;
    }
    bool operator<(const E& obj) const {
        return k < obj.k;
    }
    E operator++(int) {
        E temp(*this);
        k++;
        return temp;
    }
};

template <typename T>
class Matrix {
    T** arr;
    int rows;
    int cols;
public:
    static int count;
    Matrix() : arr(nullptr), rows(0), cols(0) {
        count++;
    }

    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        arr = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new T[cols];
        }
        count++;
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    T GetArr(int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return arr[rows][cols];
        }
    }

    T SetArr(int r, int c) {
        if (r > 1 && c > 1) {
            rows = r;
            cols = c;
        }
    }

    void FillRandom() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = rand() % 20 + 1;
            }
        }
    }

    void Input() {
        int a;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> a;
                arr[i][j] = a;
            }
        }
    }

    void Print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "\t" << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> AddMatr(const Matrix<T>& obj) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] + obj.arr[i][j];
            }
        }
        return result;
    }

    Matrix<T> AddNum(int num) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] + num;
            }
        }
        return result;
    }

    Matrix<T> DiffMatr(const Matrix<T>& obj) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] - obj.arr[i][j];
            }
        }
        return result;
    }

    Matrix<T> DiffNum(int num) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] - num;
            }
        }
        return result;
    }

    Matrix<T> DivMatr(const Matrix<T>& obj) {
        Matrix<T> result(rows, obj.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < obj.cols; ++j) {
                result.arr[i][j] = arr[i][j] / obj.arr[i][j];
            }
        }
        return result;
    }

    Matrix<T> DivNum(int num) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] / num;
            }
        }
        return result;
    }

    Matrix<T> MultMatr(const Matrix<T>& obj) {
        Matrix<T> result(rows, obj.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < obj.cols; ++j) {
                result.arr[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.arr[i][j] = result.arr[i][j] + (arr[i][k] * obj.arr[k][j]);
                }
            }
        }
        return result;
    }

    Matrix<T> MultNum(int num) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.arr[i][j] = arr[i][j] * num;
                }
            }
        }
        return result;
    }

    T findMax() {
        T max = arr[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
        return max;
    }

    T findMin() {
        T min = arr[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
            }
        }
        return min;

    }
};

template <typename T>
int Matrix<T>::count = 0;

