#include <bits/stdc++.h>
#include "Matrix.cpp"
using namespace std;

class Task5{
  vector<double> eigenValues;
  vector<vector<double>> eigenVectors;

  void powerIteration(Matrix& S, int p){
    int b = S.getrows();
    const double epsilon = 0.00001;
    for(int i=0; i<p; i++){
      vector<double> ui(b);
      vector<double> u_aux(b);
      vector<double> tmp(b);
      ui = random_vector(b);
      ui = normalise(b, ui);
      int prevEig = 0, currEig = 0;

      do{
        for(int j=0; j<b; j++)
          u_aux[j] = ui[j];
        prevEig = currEig;
        currEig = 0;
        for(int j=0; j<i; j++){
          for(int k=0; k<b; k++)
            tmp[k] = eigenVectors[j][k];
          tmp = multiply(b, tMultiply(b, tmp, u_aux), tmp);
          u_aux = subtractVectors(b, u_aux, tmp);
        }
        ui = multiply(b, S, u_aux);
        double currEig = 0;
        for(int i=0; i<b; i++)
          currEig += ui[i]*ui[i];
        ui = normalise(b, ui);
      }while(fabs(currEig - prevEig) > epsilon);
      if((ui[0]<0 && u_aux[0]>0) || (ui[0]>0 && u_aux[0]<0))
        currEig = -currEig;
      eigenVectors.push_back(ui);
      eigenValues.push_back(currEig);
    }
  }

  vector<double> random_vector(int b){
    srand(time(0));
    vector<double> ret(b);
    for(int i=0; i<b; i++)
      ret[i] = rand()%100;
    return ret;
  }
  vector<double> normalise(int b, vector<double> ui){
    double mod = 0;
    for(int i=0; i<b; i++)
      mod += ui[i]*ui[i];
    vector<double> ret(b);
    for(int i=0; i<b; i++)
      ret[i] = ui[i]/mod;
    return ret;
  }
  double tMultiply(int b, vector<double> A,vector<double> B){
    double sum = 0;
    for(int i=0;i<b;i++)
      sum+= A[i]*B[i];
    return sum;
  }
  vector<double> multiply(int b, double c, vector<double> A){
    vector<double> ret(b);
    for(int i=0;i<b;i++)
      ret[i] = A[i]*c;
    return ret;
  }
  vector<double> subtractVectors(int b, vector<double> u, vector<double> v){
    vector<double> ret(b);
    for(int i=0;i<b;i++)
      ret[i] = u[i] - v[i];
    return ret;
  }
  vector<double> multiply(int b, Matrix& S,vector<double> x){
    // int k=0;
    vector<double> ret(b);
    for(int i=0;i<b;i++){
      ret[i]=0;
      for(int j=0;j<b;j++)
        ret[i] += (S.get_element(i, j))*x[j];
    }
    return ret;
  }
public:
  Task5(Matrix& S, int p){
    powerIteration(S, p);
  }

  vector<double> get_eigenValues(){
    return eigenValues;
  }
  vector<vector<double>> get_eigenVectors(){
    return eigenVectors;
  }
};
