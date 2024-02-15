#pragma once
#include<iostream>
#include <conio.h>
#include <Windows.h>
#include"number.h"
#include "application.h"
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

class Matrix {
public:
    Matrix() {
        this->size = 3;
        this->matrix = new number * [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new number[size];
                for (int j = 0; j < size; j++)
                    matrix[i][j] = number((i+j)*size);
        }
        
    }

    void Show() {
        system("cls");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout<< matrix[i][j] << '\t';
            cout << '\n';
        }
        Wait();
    }

    void TransposeMatrix() {
        system("cls");
        number** mtrx = matrix, tmp;
        for(int i = 0;i<size;i++)
            for (int j = 0; j < i; j++) {
                tmp = mtrx[i][j];
                mtrx[i][j] = mtrx[j][i];
                mtrx[j][i] = tmp;
            }
        this->matrix = mtrx;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << mtrx[i][j] << '\t';
            cout << '\n';
        }
        Wait();
    }

    int Rang()
    {
        system("cls");
        number** mas = matrix;
        int rang = size;
        double sum=0;
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++)
                sum+=mas[i][j];
            if (sum == 0)
                rang = rang - 1;
            sum = 0;
        }
        cout << "Rang equal " << rang;
        Wait();
        return rang;
    }

    int FindDet() {
        system("cls");
        int FD = findDet_private(matrix, size);
        cout << "Determinant equal " << FD;
        Wait();
        return FD;
    }

    void SetMatrix() {
        system("cls");
        cout << "Enter size: ";
        cin >> this->size;
        this->matrix = new number * [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new number[size];
            for (int j = 0; j < size; j++) {
                SetCursorPosition((j+2)*5,i+2);
                cin >> matrix[i][j];
            }
            cout << endl;
        }
        Wait();
    }
    
    Matrix& operator = (const Matrix& otherMatrix) {
        delete this->matrix;
        this->size = otherMatrix.size;
        this->matrix = new number *[size];
        for (int i = 0; i < size; i++) {
            this->matrix[i] = new number[size];
            for (int j = 0; j < size; j++)
                matrix[i][j] = otherMatrix.matrix[i][j];
        }
        return *this;
    }

    bool operator == (const Matrix& otherMatrix) {
        if (this->size == otherMatrix.size) {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (matrix[i][j] != otherMatrix.matrix[i][j])return false;
        }
        else return false;
        return true;
    };

    bool operator != (const Matrix& otherMatrix) {
        if (this->matrix == otherMatrix.matrix)return false;
        return true;
    };

    Matrix& operator ++ () {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j]++;

        return *this;
    
    };

    Matrix& operator -- () {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j]--;

        return *this;

    };

    Matrix& operator ++ (int value) {
        Matrix t;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                t.matrix[i][j] = matrix[i][j];


        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j]++;


        return t;
    };

    Matrix& operator -- (int value) {
        Matrix t;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                t.matrix[i][j] = matrix[i][j];


        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j]--;


        return t;

    };

     

private:
    number** matrix;
    int size;
    char chr;

    static int count_matrix;
    
    void SetCursorPosition(short x, short y) {
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { x , y };
        SetConsoleCursorPosition(output, pos);
    }

    int findDet_private(number** a, int n) { //Рекурсивная функция вычисления определителя матрицы
        if (n == 1)
            return a[0][0];
        else if (n == 2)
            return a[0][0] * a[1][1] - a[0][1] * a[1][0];
        else {
            int d = 0;
            for (int k = 0; k < n; k++) {
                number** m = new number * [n - 1];
                for (int i = 0; i < n - 1; i++) {
                    m[i] = new number[n - 1];
                }
                for (int i = 1; i < n; i++) {
                    int t = 0;
                    for (int j = 0; j < n; j++) {
                        if (j == k)
                            continue;
                        m[i - 1][t] = a[i][j];
                        t++;
                    }
                }
                d += pow(-1, k + 2) * a[0][k] * findDet_private(m, n - 1);
                clearMemory(m, n - 1); //Освобождаем память, выделенную под алгебраическое дополнение
            }
            return d; //Возвращаем определитель матрицы
        }
    }

    void clearMemory(number** a, int n) { //Функция освобождения памяти, выделенной под двумерный динамический массив
        for (int i = 0; i < n; i++) {
            delete[] a[i];
        }
        delete[] a;
    }

    void Wait() {
        cout << "\n\n\n 'e' exit";
        while (true) {
            chr = _getch();
            if (chr == 'e')break;
        }
    }

};