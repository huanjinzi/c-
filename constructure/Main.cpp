#include<iostream>

using namespace std;

/**
 * reference and value.
 * 
 * g++ -std=c++11 -fno-elide-constructors -o main Main.cpp
 * 
 * -fno-elide-constructors: close Return Value Optimization.
*/

class Shape {
    public:
    int area = 5;

    // constructure
    Shape() {
        cout << "constructure method called" << endl;
    }

    // deconstructure
    ~Shape() {
        cout << "deconstructure method called!" << endl;
    }

    // copy constructure
    Shape(Shape& shape) : area(shape.area){
        cout << "copy constructure called!" << endl;
    }

    // copy assignment
    Shape& operator= (Shape& shape) {
        cout << "copy assignment called!" << endl;
    }

    // move constructure
    Shape(Shape&& shape) : area(shape.area) {
        cout << "move constructure called!" << endl;
    }

    // move assignment
    Shape& operator= (Shape&& shape) {
        cout << "move assignment called!" << endl;
    }

};

int getArea1(Shape);
int getArea2(Shape &);

int main(void) {

    cout << "shape_prt------------------------------" << endl;
    Shape *shape_prt = new Shape;
    cout << "shape_prt------------------------------\n" << endl;

    cout << "shape_cp------------------------------" << endl;
    Shape shape_cp(*shape_prt);
    Shape shape_cp_as;
    shape_cp_as = shape_cp;
    cout << "shape_cp------------------------------\n" << endl;


    cout << "ps_value------------------------------" << endl;
    getArea1(*shape_prt);
    cout << "ps_value------------------------------\n" << endl;

    cout << "ps_ref------------------------------" << endl;
    getArea2(*shape_prt);
    cout << "ps_ref------------------------------\n" << endl;

    cout << "del_ptr------------------------------" << endl;
    delete shape_prt;
    cout << "del_ptr------------------------------\n" << endl;

    cout << "shape_mv------------------------------" << endl;
    Shape shape_mv = Shape();
    Shape shape_mv_as;
    shape_mv_as = Shape();
    cout << "shape_mv------------------------------\n"<< endl;

    return 0;
}


int getArea1(Shape shape) {
    return shape.area;
}

int getArea2(Shape &shape)
{
    return shape.area;
}