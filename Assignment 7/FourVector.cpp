#include "FourVector.h"
using namespace std;

vector fourVector::spacePart(){
    vector sPart(3);
    for(size_t i=1; i<=3; i++) sPart(i) = components[i];
    return sPart;
}

double fourVector::dot(fourVector& fourV){
    double dotProduct{components[0]*fourV.getct()};
    for(size_t i=2; i<=dimension; i++) dotProduct += -components[i-1]*fourV(i);
    return dotProduct;
}

fourVector fourVector::boost(vector& beta){
    beta = checkValidBeta(beta); fourVector boostedFourV;
    double gamma{1/sqrt(1 - beta.dot(beta))};
    vector sPart{(*this).spacePart()}; double factor{beta.dot(sPart)};
    boostedFourV(1) = gamma*(components[0] - factor);
    for(size_t i=2; i<=4; i++)
        boostedFourV(i) = components[i-1] + ((gamma-1)*factor/beta.dot(beta) - \
                          gamma*components[0])*beta(i-1);
    return boostedFourV;
}

ostream& operator<<(ostream& os, fourVector& fourV){
    if(fourV.getDimension() == 0) os<<"Dimensionless vector, nothing to display!";
    else{
        os<<"(";
        for(size_t i=1; i<4; i++) os<<fourV(i)<<", "; os<<fourV(4)<<")";
    }
    return os;
}

istream& operator>>(istream& is, fourVector& fourV){
    for(size_t i=1; i<=4; i++)
        is>>fourV(i);
    return is;
}
