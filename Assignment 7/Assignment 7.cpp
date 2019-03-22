#include "Assignment 7.h"
#include "Vector.h"
#include "FourVector.h"
#include "Particle.h"
using namespace std;

void separator(){
    cout<<"------------------\n\n";
}

void vectorConstructorDemo(){
    vector a;
    cout<<"Default constructor demonstration: "<<a<<endl;
    separator();
}

void vectorParamConstructorDemo(){
    vector a(4);
    cout<<"Parametrized constructor (n-dim=4) demonstration: "<<a<<endl;
    separator();
}

void vectorCopyConstructorDemo(){
    cout<<"Copy constructor demonstration. "\
          "Please input dimension followed by vector.\n";
    size_t n; cin>>n; vector a(n); cin>>a;
    cout<<"Copy a to b, change a(2) to 7, and display both...\n";
    vector b(a); a(2) = 7;
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void vectorCopyAssignmentDemo(){
    cout<<"Copy assignment demonstration. "\
          "Please input dimension followed by vector.\n";
    size_t n; cin>>n; vector a(n); cin>>a;
    cout<<"Copy a to b, change a(2) to 7, and display both...\n";
    vector b; b = a; a(2) = 7;
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void vectorMoveConstructorDemo(){
    cout<<"Move constructor demonstration. "\
          "Please input dimension followed by vector.\n";
    size_t n; cin>>n; vector a(n); cin>>a;
    cout<<"Move a to b and display both...\n";
    vector b(move(a));
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void vectorMoveAssignmentDemo(){
    cout<<"Move assignment demonstration. "\
          "Please input dimension followed by vector.\n";
    size_t n; cin>>n; vector a(n); cin>>a;
    cout<<"Move a to b and display both...\n";
    vector b; b = move(a);
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void vectorDotProductDemo(){
    cout<<"Vector dot product demonstration. ";
    cout<<"Please give dimension followed by vector for two vectors:\n";
    size_t n; cin>>n; vector a(n); cin>>a;
    size_t m; cin>>m; vector b(m); cin>>b;

    cout<<a<<"."<<b<<" = "<<a.dot(b)<<endl;
    separator();
}

void fourVectorConstructorDemo(){
    fourVector a;
    cout<<"Default constructor demonstration: "<<a<<endl;
    separator();
}

void fourVectorParamConstructorOneDemo(){
    fourVector a(1, 2, 3, 4);
    cout<<"Parametrized constructor demonstration one (see code): "<<a<<endl;
    separator();
}

void fourVectorParamConstructorTwoDemo(){
    vector a(3); a(1) = 1; a(2) = 2; a(3) = 3;
    fourVector b(0, a);
    cout<<"Parametrized constructor demonstration two (see code): "<<b<<endl;
    separator();
}

void fourVectorCopyConstructorDemo(){
    cout<<"Copy constructor demonstration. "\
          "Please input fourVector.\n";
    fourVector a; cin>>a;
    cout<<"Copy a to b, change a(2) to 7, and display both...\n";
    fourVector b(a); a(2) = 7;
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void fourVectorCopyAssignmentDemo(){
    cout<<"Copy assignment demonstration. "\
          "Please by fourVector.\n";
    fourVector a; cin>>a;
    cout<<"Copy a to b, change a(2) to 7, and display both...\n";
    fourVector b; b = a; a(2) = 7;
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void fourVectorMoveConstructorDemo(){
    cout<<"Move constructor demonstration. "\
          "Please input fourVector.\n";
    fourVector a; cin>>a;
    cout<<"Move a to b and display both...\n";
    fourVector b(move(a));
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void fourVectorMoveAssignmentDemo(){
    cout<<"Move assignment demonstration. "\
          "Please input fourVector.\n";
    fourVector a; cin>>a;
    cout<<"Move a to b and display both...\n";
    fourVector b; b = move(a);
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    separator();
}

void fourVectorDotProductDemo(){
    cout<<"fourVector dot product demonstration. ";
    cout<<"Please two vectors:\n";
    fourVector a; cin>>a;
    fourVector b; cin>>b;
    cout<<a<<"."<<b<<" = "<<a.dot(b)<<endl;
    separator();
}

void fourVectorBoostDemo(){
    cout<<"fourVector boost demonstration. ";
    cout<<"Please input a vector and a velocity (with components < 1).\n";
    cout<<"a: "; fourVector a; cin>>a;
    cout<<"beta: "; vector beta(3); cin>>beta;
    cout<<"Boosted a : ";
    fourVector boosted; boosted = a.boost(beta); cout<<boosted<<endl;
    separator();
}

void particleConstructorDemo(){
    particle p;
    cout<<"Default constructor demonstration:\n";
    cout<<p;
    separator();
}

void particleParamConstructorDemo(){
    cout<<"Parametrized constructor demonstration:\n";
    cout<<"Please give a mass: "; double m; cin>>m;
    cout<<"Please give a position (4D): "; fourVector r; cin>>r;
    cout<<"Please give a velocity (3D): "; vector be(3); cin>>be;
    particle p(m, r, be);
    cout<<p;
    separator();
}

void particleQuantitiesDemo(){

    cout<<"Particle quantities demonstration: \n";
    cout<<"Please give a mass: "; double m; cin>>m;
    cout<<"Please give a position (4D): "; fourVector r; cin>>r;
    cout<<"Please give a velocity (3D): "; vector be(3); cin>>be;
    particle p(m, r, be);

    double gamma{p.gamma()};
    double energy{p.energy()};
    double momentum{p.momentum()};

    cout<<"Gamma: "<<gamma<<endl;
    cout<<"energy: "<<energy<<endl;
    cout<<"momentum: "<<momentum<<endl;
}

int main(){
    cout<<"VECTOR CLASS DEMONSTRATIONS:\n";
    vectorConstructorDemo();
    vectorParamConstructorDemo();
    vectorCopyConstructorDemo();
    vectorCopyAssignmentDemo();
    vectorMoveConstructorDemo();
    vectorMoveAssignmentDemo();
    vectorDotProductDemo();
    cout<<"FOUR VECTOR CLASS DEMONSTRATIONS:\n";
    fourVectorConstructorDemo();
    fourVectorParamConstructorOneDemo();
    fourVectorParamConstructorTwoDemo();
    fourVectorCopyConstructorDemo();
    fourVectorCopyAssignmentDemo();
    fourVectorMoveConstructorDemo();
    fourVectorMoveAssignmentDemo();
    fourVectorDotProductDemo();
    fourVectorBoostDemo();
    cout<<"PARITCLE DEMONSTRATIONS: \n";
    particleConstructorDemo();
    particleParamConstructorDemo();
    particleQuantitiesDemo();

}
