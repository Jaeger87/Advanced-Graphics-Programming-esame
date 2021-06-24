#pragma once

#include <math.h>
#include "vector3.h"
#include "point3.h"
#include "versor3.h"
#include "axis_angle.h"
/* Euler class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all the expected methods    */

class Quaternion;
class AxisAngle;
class Euler;

class Euler{
public:

    /* fields */
    Scalar pitchX, yawY, rollZ; //gradi

    Euler();

    // row major order!
    Euler(Scalar m00, Scalar m01, Scalar m02,
        Scalar m10, Scalar m11, Scalar m12,
        Scalar m20, Scalar m21, Scalar m22);

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
    Euler operator * (Euler b) const;

    //Non la fate (converti prima ad altro)
    Euler inverse() const;

    void invert();

    // specific methods for Eulers...
    Euler transposed() const;

    void transpose();

    // returns a rotation to look toward target, if you are in eye, and the up-vector is up
    static Euler lookAt(Point3 eye, Point3 target, Versor3 up);

    // returns a rotation
    static Euler toFrom(Versor3 to, Versor3 from);

    static Euler toFrom(Vector3 to, Vector3 from);

    // conversions to this representation
    static Euler from( Quaternion m );
    static Euler from( Matrix3 e );     
    static Euler from( AxisAngle e ); 

    // does this Euler encode a rotation?
    bool isRot() const;

    // return a rotation matrix around an axis
    static Euler rotationX( Scalar angleDeg );
    static Euler rotationY( Scalar angleDeg );
    static Euler rotationZ( Scalar angleDeg );

    friend std::ostream& operator<<(std::ostream&, const Euler&);

    void printf() const;
};

inline std::ostream& operator<<(std::ostream& strm, const Euler& a) {
	return strm << "Euler(X:" << a.pitchX << ", y:" << a.yawY << ", z:" << a.rollZ << ")";
}

// interpolation or roations
inline Euler directLerp( const Euler& a,const Euler& b, Scalar t){
    // TODO E-directLerp: how to interpolate Eulers
    return Euler();
}
//Non la fate (converti prima ad altro)
inline Euler lerp( const Euler& a,const Euler& b, Scalar t){
    AxisAngle aAxis = AxisAngle::from(a);
    AxisAngle bAxis = AxisAngle::from(b);
    AxisAngle lerped = lerp(aAxis, bAxis, t);
    return Euler::from(lerped);
}


