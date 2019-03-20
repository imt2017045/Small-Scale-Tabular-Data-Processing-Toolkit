
#ifndef Output_H_
#define Output_H_
#include "Matrix.h"

using namespace std;

class Output{
    public:
        Output();
        Output(Matrix M,string filename);
        void writeMatrix();
        // friend ostream& operator<<(ostream &os,const Matrix &m);
    private:
        Matrix matrix;
        string filename;
    protected:
};

#endif
