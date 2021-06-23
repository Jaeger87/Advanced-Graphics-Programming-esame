#include <iostream>
#include <math.h>

#include "transform.h"
#include "matrix3.h"



void check(bool condition, std::string descr ){
    std::cout << "Test " << descr << ": "
              << ((condition)?"PASSED":"FAILED" )
              << "\n";

}

void unitTestInverse(){
    Transform t;
    t.translation = Vector3(2,0,0);
    t.scale = 3;

    Point3 p0,q,p1;

    q = t.apply(p0);

    Transform ti = t.inverse();
    p1 = ti.apply(q); // VOGLIO RIOTTENERE p

    check( p0.isEqual(p1) , "INVERSE");
}


void unitTestCumlate(){
    Transform t1,t2;
    t1.translation = Vector3(2,0,0);
    t1.scale = 4;
    t2.translation = Vector3(4,-3,1);
    t2.scale = 0.4;
    Point3 p(3,1,3);
    Point3 q0 = t2.apply ( t1.apply(p) );
    Point3 q1 = (t2*t1).apply ( p );

    check( q0.isEqual(q1) , "CUMULATE" );

}




int main()
{
    Vector3::left().printf();
    Versor3 testSlerp = slerp(Versor3::down(), Versor3::right(), 0.5f);
    Versor3::down().printf();

    Matrix3 matrix = Matrix3();
    //std::cout << matrix << std::endl;

    unitTestInverse();
    unitTestCumlate();
    return 0;
}
