#include "Vector.h"
#include "Checks.h"
using namespace std;

double& vector::operator()(const size_t idx){
    checkIndexInside(idx, dimension);
    return components[idx-1];
}

vector::vector(const size_t dim){
    checkValidDimension(dim); dimension = dim;
    components = new double[dim];
    for(size_t i=0; i<dimension; i++)
        components[i] = 0;
}

vector::vector(vector& v){
    components = 0; dimension = v.getDimension();
    bool copyCondition{dimension > 0};
    if(copyCondition){
        components = new double[dimension];
        for(size_t i=1; i<=dimension; i++)
            components[i-1] = v(i);
    }
}

vector::vector(vector&& v){
    dimension = v.dimension;
    components = v.components;
    v.dimension = 0; v.components = 0;
}

vector& vector::operator=(vector& v){
    if(&v == this) return *this;
    delete[] components; components = 0; dimension = v.getDimension();
    bool copyCondition{ dimension > 0 };
    if(copyCondition){
        components = new double[dimension];
        for(size_t i=1; i<=dimension; i++)
            components[i-1] = v(i);
    }
    return *this;
}

vector& vector::operator=(vector&& v){
    swap(dimension, v.dimension);
    swap(components, v.components);

    return *this;
}

double vector::dot(vector& v){
    checkEqualDimensions(dimension, v.getDimension());
    double dotProduct{0};
    for(size_t i=1; i<=dimension; i++)
        dotProduct += components[i-1]*v(i);
    return dotProduct;
}

ostream& operator<<(ostream& os, vector& v){
    if(v.getDimension() == 0) os<<"Dimensionless vector, nothing to display!";
    else{
        os<<"("; size_t i=1;
        for(i; i<v.getDimension(); i++) os<<v(i)<<", "; os<<v(i)<<")";
    }
    return os;
}

istream& operator>>(istream& is, vector& v){
    for(size_t i=1; i<=v.getDimension(); i++)
        is>>v(i);
    return is;
}
