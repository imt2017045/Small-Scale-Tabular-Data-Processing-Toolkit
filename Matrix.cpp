#include<iostream>
#include<cmath>
#include<cstdlib>
#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
  matrix = NULL;
}

Matrix::Matrix(int x,int y)
{
  this->r = x;
  this->c = y;
  matrix = new double*[r];
  for(int j = 0;j < r;j++)
     matrix[j] = new double[c];

}

Matrix::Matrix(Input I){
    int n = I.get_no_ofStrings();
    r = I.get_no_ofRecords();
    c = I.get_no_ofVariables()-I.get_no_ofStrings();
    // cout<<"columns : "<<c<<endl;
    matrix = new double*[r];
    for(int j = 0;j < r;j++)
       matrix[j] = new double[c];

    for(int i=0;i < r;i++){
        Record temp = I.get_values(i);
        for(int j=0;j < c;j++){
            // To comliple stod use " -std=c++11 " in the end
            matrix[i][j] = temp.get_numericVariable(j);
        }
      }
}

Matrix::~Matrix()
{
  for(int i= 0;i < r;i++)
    delete[] matrix[i];
  delete[] matrix;
}

//This is the setter method to assign values to matrix at particular position
void Matrix::set_element(int x,int y,double data)
{
  this->matrix[x][y] = data;
}

double Matrix::get_element(int i,int j)
{
  return matrix[i][j];
}

//Setter to assign values to the whole matrix.
void Matrix::set_matrix(double** m)
{
  for(int i  = 0;i < r; i++)
    for(int j = 0;j < c;j++)
      matrix[i][j] = m[i][j];
}

double** Matrix::get_matrix()
{
  return matrix;
}


Matrix::Matrix(const Matrix& m) :
  r(m.r), c(m.c)
  {
  matrix = new double*[r] ;
  for (int i = 0 ; i < r ; i++)
    matrix[i] = new double[c];

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
	     matrix[i][j] = m.matrix[i][j];
}

int Matrix::getrows()
{
  return this->r;
}

int Matrix::getcolumns()
{
  return this->c;
}

//ostream to print the grid and is a friend function of the grid class.
ostream& operator<<(ostream &os,const Matrix &m) {
  for (int i = 0 ; i < m.r; i++)
    {
      for(int j = 0; j < m.c; j++)
        {
          os<<m.matrix[i][j]<<",";
        }
        os <<endl ;
    }
  return os ;
}
