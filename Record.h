#include <bits/stdc++.h>
using namespace std;

class Record {
  int no_ofVariables;
  int no_ofStrings;
  vector<string> stringVariables;
  vector<double> numericVariables;

public:
  int get_no_ofVariables(){
    return no_ofVariables;
  }
  int get_no_ofStrings(){
    return no_ofStrings;
  }
  void set_no_ofVariables(int N){
    no_ofVariables = N;;
  }
  void set_no_ofStrings(int n){
    no_ofStrings = n;
  }

  string get_stringVariable(int i){
    return stringVariables[i];
  }
  vector<string> get_stringVariable_vector(){
    return stringVariables;
  }
  double get_numericVariable(int i){
    return numericVariables[i];
  }
  vector<double> get_numericVariable_vector(){
    return numericVariables;
  }

  void add_stringVariable(string s){
    stringVariables.push_back(s);
  }
  void add_numericVariable(double nv){
    numericVariables.push_back(nv);
  }

  void set_stringVariable(int i, string s){
    stringVariables[i] = s;
  }
  void set_numericVariable(int i, double nv){
    numericVariables[i] = nv;
  }

  Record(int N, int n){
    no_ofVariables = N;
    no_ofStrings = n;
  }
  Record(){
    no_ofVariables = 0;
    no_ofStrings = 0;
  }
};
