#include<iostream>
#include "Input.h"

#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix
{
  public:
    Matrix();
    Matrix(int,int);
    Matrix(Input I);
    ~Matrix();
    Matrix(const Matrix &M);
    double get_element(int,int);
    void set_element(int,int,double);
    double** get_matrix();
    void set_matrix(double**);
    int getrows();
    int getcolumns();
    friend ostream& operator<<(ostream &os,const Matrix &m);
  private:
    double** matrix;
    int r,c;
};

#endif
