#ifndef Input_H
#define Input_H
#include<bits/stdc++.h>
#include "Record.h"
using namespace std;
class Input{
  int no_ofRecords, no_ofVariables, no_ofStrings;
  vector<string> attbr;
  vector<Record> values;
public:
  Input(string filename, int n){
    no_ofStrings = n;

    ifstream myfile;
    myfile.open(filename);

    string s;
    bool check=false;
    int j = 0;
    while(getline(myfile,s)){
      char p[s.size()+1];
      strcpy(p,s.c_str());
      char *token = strtok(p,",");

      Record tmp;
      if(check) tmp = Record(no_ofVariables, no_ofStrings);
      int i = 1;
      while(token != NULL){
        if(check){
          if(i <= n)
            tmp.add_stringVariable(string(token));
          else
            tmp.add_numericVariable(stod(string(token)));
        }
        else attbr.push_back(string(token));
        token = strtok(NULL,",");
        i++;
      }
      if(check)
        values.push_back(tmp);
      else
        no_ofVariables = attbr.size();
      check =true;

      j++;
    }
    no_ofRecords = j-1;
  }

  int get_no_ofRecords(){
    return no_ofRecords;
  }
  int get_no_ofVariables(){
    return no_ofVariables;
  }
  int get_no_ofStrings(){
    return no_ofStrings;
  }

  Record& get_values(int i){
    return values[i];
  }
  vector<string> get_attbr(){
    return attbr;
  }
};
#endif
