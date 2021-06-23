#pragma once
#include <math.h>

/* AxisAngle class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all expected methods    */

class Matrix3;
class Euler;
class Quaternion;
class Versor3;
class Point3;
class Vector3;

class AxisAngle{
public:

    /* fields */
    Scalar angle;
    Versor3 axis;

    AxisAngle();

    // returns a AxisAngle encoding a point
    AxisAngle(const Point3& p);

    AxisAngle(const Versor3 _axis, const Scalar _angle);

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
    AxisAngle operator * (AxisAngle r) const;

    AxisAngle inverse() const;

    void invert();

    // returns a rotation to look toward target, if you are in eye, and the up-vector is up
    static AxisAngle lookAt(Point3 eye, Point3 target, Versor3 up);

    // returns a rotation
    static AxisAngle toFrom(Versor3 to, Versor3 from);

    static AxisAngle toFrom(Vector3 to, Vector3 from);

    // conversions to this representation
    static AxisAngle from( Matrix3 m );
    static AxisAngle from( Euler e );
    
    static AxisAngle from(Quaternion q);

    // does this AxisAngle encode a point?
    bool isPoint() const;

    friend std::ostream& operator<<(std::ostream&, const AxisAngle&);

    void printf() const;
};

inline std::ostream& operator<<(std::ostream& strm, const AxisAngle& a) {
    return strm << "AxisAngle: Axis(" << a.axis << "), " << "Angle(" << a.angle << ")";
}

// interpolation or rotations
inline AxisAngle lerp( const AxisAngle& a,const AxisAngle& b, Scalar t){
    // TODO A-Lerp: how to interpolate AxisAngles
    // hints: shortest path! Also, consider them are 4D unit vectors.
    return AxisAngle();
}





