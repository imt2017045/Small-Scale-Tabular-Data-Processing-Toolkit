#include <bits/stdc++.h>
#include "Matrix.h"
#include "Matrix.cpp"
#include "Input.h"
// #include "output.h"
// #include "Task5.h"

using namespace std;
vector<double> random(int n){
  srand(time(0));
  vector<double> x(n);
  for(int i=0;i<n;i++)x[i]=rand()%100;
  return x;
}

vector<double> multiply(int n,vector <vector<double> > A,vector<double> x){
  int k=0;
  vector<double> c(n);
  for(int i=0;i<n;i++){
      c[i]=0;
      for (int j=0;j<n;j++){
          c[i]+=A[i][j]*x[j];
      }
  }
  return c;
}

double normalization_value(int n,vector<double> c){
  double k = 0;
  for(int i=0;i<n;i++) k+=c[i]*c[i];
  k = sqrt(k);
  return k;
}

vector<double> normalization(int n,vector<double> c,double k){
  vector<double> x(n);
  for(int i=0;i<n;i++) x[i]=c[i]/k;
  return x;
}

double multiply_transpose(int n,vector<double> a,vector<double> b){
  double sum;
  for(int i=0;i<n;i++) sum+= a[i]*b[i];
  return sum;
}

vector<double> multiply_constant(int n,vector<double> a,double k){
  vector<double> b(n);
  for(int i=0;i<n;i++) b[i] = a[i]*k;
  return b;
}

vector<double> subtract_vectors(int n,vector<double> a,vector<double> b){
  vector<double> c(n);
  for(int i=0;i<n;i++) c[i] = a[i] - b[i];
  return c;
}

void powerIteration(int p, Matrix& S){
  int b = S.getrows();
  vector<vector<double>> original;
  vector<vector<double>> eigen_vectors;
  vector<double> eigen_values;

  for(int i=0; i<b; i++){
    vector<double> tmp;
    for(int j=0; j<b; j++){
      tmp.push_back(S.get_matrix()[i][j]);
    }
    original.push_back(tmp);
  }

  for(int loop=0;loop<p;loop++){
    vector<double> u_aux(b);
    vector <double> ui(b);
    vector<double> temp(b);
    double prevEig = 0, currEig = 0;
    ui = random(b);
    ui = normalization(b, ui, normalization_value(b,ui));
    do{
      for(int i=0;i<b;i++)
        u_aux[i] = ui[i];
      prevEig = currEig;
      currEig = 0;
      for(int j=0;j<=loop-1;j++){
          for(int l=0;l<b;l++)
            temp[l] = eigen_vectors[j][l];
          temp = multiply_constant(b, temp, multiply_transpose(b, u_aux, temp));
          u_aux = subtract_vectors(b, u_aux, temp);
        }
        ui = multiply(b, original, u_aux);
        currEig = normalization_value(b, ui);
        ui = normalization(b, ui,normalization_value(b, ui));
    }while (fabs(currEig - prevEig)>0.00001);
    if((ui[0]<0 && u_aux[0]>0) || (ui[0]>0 && u_aux[0]<0))
      currEig = -currEig;
    eigen_values.push_back(currEig);
    eigen_vectors.push_back(ui);
  }

  ofstream myfile;
  myfile.open("task5.csv");
  myfile << "Eigen Values are:" << endl;
  for(int i=0; i<p; i++)
    myfile << eigen_values[i] << ' ';
  myfile << endl << "Eigen Vectors are: " << endl;
  for(int i=0; i<p; i++){
    for(int j=0; j<b; j++)
      myfile << eigen_vectors[i][j] << ' ';
    myfile << endl;
  }
}

int main(){
  Matrix m(3, 3);
  double** temp = new double*[3];
  for(int i=0; i<3; i++)
    temp[i] = new double[3];
  temp[0][0] = 1;
  temp[0][1] = 2;
  temp[0][2] = 3;
  temp[1][0] = 2;
  temp[1][1] = 1;
  temp[1][2] = 4;
  temp[2][0] = 3;
  temp[2][1] = 4;
  temp[2][2] = 1;
  m.set_matrix(temp);

  vector<vector<double>> eigen_vectors;
  vector<double> eigen_values;

  powerIteration(6, m);
  return 0;
}
