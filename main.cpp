#include<iostream>
#include<cmath>
#include<cstdlib>
#include "Matrix.h"
#include "Input.h"
#include "output.h"
#include "tmp.cpp"

using namespace std;

double get_Euclidean_distance(double* first,double* second,int c)
{
  double distance = 0;
  for(int ele = 0;ele < c;ele++)
  {
    distance += pow((first[ele]-second[ele]),2);
  }
  distance = sqrt(distance);
  return distance;
}

double get_norm_distance(double min,double max,double value)
{
  if(max-min != 0)
    return (value- min)/(max-min);
  return 0;
}

double get_average(double** arr,int r,int c)
{
  double avg = 0;
  for(int i = 0; i<r ;i++)
  {
    avg += arr[i][c];
  }
  if(r!=0)
    avg = avg/r;
  return avg;
}

// function to sort the 2D vector on basis of a particular column
bool sortcol( const vector<double>& v1,
               const vector<double>& v2) {
  int e = v1.size()-1;
 return v1[e] < v2[e];
}

//Sorting based on second element of the pair.
bool sort_sec(const pair<int,double> &a,
              const pair<int,double> &b)
{
    return (a.second < b.second);
  }

int main()
{
  // string s = "AirQualityUCI.csv";
  string s = "sample.csv";
  Input I = Input(s,4);
  Matrix M1(I);
  int rows = M1.getrows();
  int columns = M1.getcolumns();
  double min = 1000000,max = -1000000;

  //This the 2D array where iam storng the matrix.
  double** array;
  array = new double*[rows];
  for(int i = 0;i < rows;i++)
  {
    array[i] = new double[columns];
  }
  for(int i = 0;i < rows;i++)
  {
    for(int j = 0;j < columns;j++)
    {
     array[i][j] = M1.get_element(i,j);
   }
 }


  double* avg = new double[columns];
  double* euclidean_dist = new double[rows];
  vector< pair<int,double> > normalized_values;

  vector< vector<double> > temp;

  for(int i = 0;i < rows;i++)
  {
    vector<double> a;
    for(int j = 0;j < columns;j++ )
    {
      a.push_back(array[i][j]);
    }
    temp.push_back(a);
  }

  for(int i = 0;i < columns;i++)
  {
    avg[i] = get_average(array,rows,i);
  }

  for(int k = 0;k < rows;k++)
  {
    euclidean_dist[k] = get_Euclidean_distance(array[k],avg,columns);
    if(euclidean_dist[k] > max) max = euclidean_dist[k];
    if(euclidean_dist[k] < min) min = euclidean_dist[k];
  }
  for(int k = 0;k < rows;k++)
  {
    normalized_values.push_back(make_pair(k,get_norm_distance(min,max,euclidean_dist[k])));
    temp[k].push_back(get_norm_distance(min,max,euclidean_dist[k]));
  }

 sort(normalized_values.begin(),normalized_values.end(),sort_sec);

 sort(temp.begin(),temp.end(),sortcol);

 vector< vector<double> >::const_iterator row;
 vector<double>::const_iterator col;
 int x = 0;
 for (row = temp.begin(); row != temp.end(); ++row)
 {
    int d = 0;
    for (col = row->begin(); col != row->end(); ++col)
    {
      if(d < columns)
      {
        array[x][d]  = *col;
        d++;
      }
    }
    x++;
 }
//
 Matrix out(rows,rows);    //Creating the r*r output matrix
 for(int l =0;l < rows;l++)
 {
    for(int m = 0;m <rows;m++)
    {
      out.set_element(l,m,get_Euclidean_distance(array[l],array[m],columns));
      }
  }
  powerIteration(6, out);
// Here Iam writing the output matrix into a file.
  // Output answer(out,"task2.txt");
  // answer.writeMatrix();
}
