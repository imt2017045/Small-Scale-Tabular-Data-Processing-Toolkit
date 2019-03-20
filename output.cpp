#include"output.h"
#include<fstream>
#include<iostream>

//constructors
Output::Output(){}

Output::Output(Matrix M, string fname){

    matrix = M;
    filename = fname;

}

void Output::writeMatrix(){
    ofstream myfile;
    myfile.open(filename);
    myfile << matrix;
    myfile << "eof" << endl;
}
