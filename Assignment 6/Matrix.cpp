#include "Matrix.h"
#include "Checks.h"
using namespace std;

size_t matrix::index(size_t i, size_t j){
    bool validRow{i>0 && i<=rows}; bool validCol{j>0 && j<=cols};
    if(validRow && validCol) return (i-1) + (j-1)*cols;
    else throw invalid_argument("Matrix index out of range!");
}

matrix::matrix(const size_t rw, const size_t cl){
    checkRowsCols(rw, cl);
    rows = rw; cols = cl;
    mdata = new double[rows*cols];
    for(size_t i=1; i<=rows; i++)
        for(size_t j=1; j<=cols; j++)
            mdata[index(i,j)] = 0;
}

matrix::matrix(matrix& mat){
    mdata = 0; rows = mat.rowsln(); cols = mat.colsln();
    bool copyCondition{rows > 0 && cols > 0};
    if(copyCondition){
        mdata = new double[rows*cols];
        for(size_t i=1; i<=rows; i++)
            for(size_t j=1; j<=cols; j++)
                mdata[index(i,j)] = mat(i,j);
    }
}

matrix::matrix(matrix&& mat){
    rows = mat.rows; cols = mat.cols;
    mdata = mat.mdata;
    mat.rows = 0; mat.cols = 0; mat.mdata = 0;
}

matrix& matrix::operator=(matrix& mat){
    if(&mat == this) return *this;
    delete[] mdata; mdata = 0; rows = mat.rowsln(); cols = mat.colsln();
    bool copyCondition{rows > 0 && cols > 0};
    if(copyCondition){
        mdata = new double[rows*cols];
        for(size_t i=1; i<=rows; i++)
            for(size_t j=1; j<=cols; j++)
                mdata[index(i,j)] = mat(i,j);
    }
    return *this;
}

matrix& matrix::operator=(matrix&& mat){

    swap(rows, mat.rows); swap(cols, mat.cols);
    swap(mdata, mat.mdata);
    return *this;
}

matrix matrix::operator+(matrix& mat){
    checkCompatDim(rows, mat.rowsln(), cols, mat.colsln());
    matrix matSum(rows, cols);
    for(size_t i=1; i<=rows; i++)
        for(size_t j=1; j<=cols; j++)
            matSum(i,j) = mdata[index(i,j)] + mat(i,j);
    return matSum;
}

matrix matrix::operator-(matrix& mat){
    checkCompatDim(rows, mat.rowsln(), cols, mat.colsln());
    matrix matDiff(rows, cols);
    for(size_t i=1; i<=rows; i++)
        for(size_t j=1; j<=cols; j++)
            matDiff(i,j) = mdata[index(i,j)] - mat(i,j);
    return matDiff;
}

matrix matrix::operator*(matrix& mat){
    checkSquareMat(rows, cols); checkSquareMat(mat.rowsln(), mat.colsln());
    checkCompatDim(rows, mat.rowsln(), cols, mat.colsln());
    matrix matProd(rows, cols); double elemProd{0};
    for(size_t i=1; i<=rows; i++)
        for(size_t j=1; j<=cols; j++)
            for(size_t k=1; k<=cols; k++)
                matProd(i,j) += mdata[index(j,k)]*mat(k,j);
    return matProd;
}

matrix matrix::getMinor(size_t row, size_t col){
    checkRowCol(row, col);
    matrix matMinor(rows-1, cols-1);
    for(size_t i=1; i<rows; i++)
        for(size_t j=1; j<cols; j++){
            if(j<row && i<col)
                matMinor(i,j) = mdata[index(i,j)];
            else if(j<row && i>=col)
                matMinor(i,j) = mdata[index(i+1,j)];
            else if(j>=row && i<col)
                matMinor(i,j) = mdata[index(i,j+1)];
            else if(j>=row && i>=col)
                matMinor(i,j) = mdata[index(i+1,j+1)];
        }
    return matMinor;
}

double matrix::determinant(){
    checkSquareMat(rows, cols);
    if(rows>2){
        double matDet{0};
        for(size_t i=1; i<=rows; i++){
            matrix minorMat(this->getMinor(1,i));
            double term{(*this)(1,i)* minorMat.determinant()};
            matDet += pow(-1,i+1)*term;
        }
        return matDet;
    }
    else
        return (*this)(1,1)*(*this)(2,2) - (*this)(1,2)*(*this)(2,1);
}

ostream& operator<<(ostream& os, matrix& mat){
    if(mat.rowsln()==0) cout<<"Dimensionless matrix!\n";
    for(size_t i=1; i<=mat.rowsln(); i++){
        os<<endl;
        for(size_t j=1; j<=mat.colsln(); j++)
            os<<mat(i,j)<<" ";
    }
    return os;
}

istream& operator>>(istream& is, matrix& mat){
    cout<<"Please give the elements of the matrix.\n";
    for(size_t i=1; i<=mat.rowsln(); i++){
        for(size_t j=1; j<=mat.colsln(); j++)
            is>>mat(i,j);
    }
    return is;
}
