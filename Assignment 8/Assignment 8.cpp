#include "Shapes.h"
#include "Shape2D.h"
#include "Shape3D.h"
#include <iostream>
using namespace std;

int main(){
    cout<<"DEMONSTRATIONS:\n";
    shape** shapesArray = new shape*[8];
    shapesArray[0] = new rectangle(2,4);
    shapesArray[1] = new square(2);
    shapesArray[2] = new ellipse(4,2);
    shapesArray[3] = new circle(2);
    shapesArray[4] = new cuboid(3,4,5);
    shapesArray[5] = new cube(3);
    shapesArray[6] = new ellipsoid(3,4,5);
    shapesArray[7] = new sphere(3);

    cout<<"Rectangle area: "<<shapesArray[0]->area()<<endl;
    cout<<"Square area: "<<shapesArray[1]->area()<<endl;
    cout<<"Ellipse area: "<<shapesArray[2]->area()<<endl;
    cout<<"Circle area: "<<shapesArray[3]->area()<<endl<<endl;

    cout<<"Cuboid volume: "<<shapesArray[4]->volume()<<endl;
    cout<<"Cube volume: "<<shapesArray[5]->volume()<<endl;
    cout<<"Ellipsoid volume: "<<shapesArray[6]->volume()<<endl;
    cout<<"Sphere volume: "<<shapesArray[7]->volume()<<endl<<endl;

    cout<<"Prism demonstration\n";
    shape2D* aRectangle(new rectangle(2,4));
    prism aPrism(3, aRectangle);
    cout<<"Prism volume: "<<aPrism.volume()<<endl<<endl;

    delete shapesArray[0];
    delete shapesArray[1];
    delete shapesArray[2];
    delete shapesArray[3];
    delete shapesArray[4];
    delete shapesArray[5];
    delete shapesArray[6];
    delete shapesArray[7];
    delete[] shapesArray;
    return 0;
}
