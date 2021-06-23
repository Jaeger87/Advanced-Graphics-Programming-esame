#pragma once

#include <math.h>

/* Quaternion class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all expected methods    */

class Matrix3;
class Euler;
class AxisAngle;
class Versor3;
class Point3;


class Quaternion{
public:

    /* fields */

    Vector3 imaginaryPart;
    Scalar realPart;

    static Quaternion identity();

    Quaternion(Scalar _realPart, Vector3 _imaginaryPart);

    Quaternion(Scalar a, Scalar b, Scalar c);

    Quaternion();

    // returns a quaternion encoding a point
    Quaternion(const Point3& p);

    Vector3 apply(Vector3  v) const;

    // Rotations can be applied to versors or vectors just as well
    Versor3 apply(Versor3 dir) const;

    Point3 apply(Point3 p) const;

    // syntactic sugar: "R( p )" as a synomim of "R.apply( p )"
    Versor3 operator() (Versor3 p);
    Point3  operator() (Point3  p);
    Vector3 operator() (Vector3 p);

    Versor3 axisX() const;
    Versor3 axisY() const;
    Versor3 axisZ() const; 

    // conjugate
    Quaternion operator * (Quaternion r) const;

    Quaternion inverse() const;

    void invert();

    // specific methods for quaternions...
    Quaternion conjugated() const;

    void conjugate();

    Scalar squaredNorm() const;

    // returns a rotation to look toward target, if you are in eye, and the up-vector is up
    static Quaternion lookAt(Point3 eye, Point3 target, Versor3 up = Versor3::up());

    // returns a rotation
    static Quaternion toFrom(Versor3 to, Versor3 from);

    static Quaternion toFrom(Vector3 to, Vector3 from);

    // conversions to this representation
    static Quaternion from( Matrix3 m ); 
    static Quaternion from( Euler e );     
    
    static Quaternion from(AxisAngle e);

    // does this quaternion encode a rotation?
    bool isRot() const;


    // does this quaternion encode a point?
    bool isPoint() const;

    //friend std::ostream& operator<<(std::ostream&, const Quaternion&);

    void printf() const;
};
/*
std::ostream& operator<<(std::ostream& strm, const Quaternion& a) {
	return strm << "Quaternion with real part:" << a.realPart
		<< ", and imaginary part:" << a.imaginaryPart << std::endl;
}
*/
// interpolation or rotations
inline Quaternion lerp( const Quaternion& a,const Quaternion& b, Scalar t){
    // TODO Q-Lerp: how to interpolate quaternions
    // hints: shortest path! Also, consdider them are 4D unit vectors.
    return Quaternion();
}



