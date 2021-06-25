#pragma once

#include <math.h>

/* Matrix3 class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all the expected methods    */

class Quaternion;
class AxisAngle;
class Euler;

class Versor3;
class Point3;
class Vector3;

class Matrix3{
    
public:

    /* fields */
    Versor3 matrix[3];

    Matrix3();
    

    // constructor that takes as input the coefficient (RAW-MAJOR order!)
    Matrix3(Scalar m00, Scalar m01, Scalar m02,
        Scalar m10, Scalar m11, Scalar m12,
        Scalar m20, Scalar m21, Scalar m22);

   // Matrix3(Versor3 column1, Versor3 column2, Versor3 column3):{matrix[0] = column1; matrix[1] = column2; matrix[2] = column3; }

    Matrix3(Versor3 column1, Versor3 column2, Versor3 column3);


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

    // combine two rotations (r goes first!)
    Matrix3 operator * (Matrix3 r) const;

    Matrix3 inverse() const;

    void invert();

    // returns a rotation to look toward target, if you are in eye, and the up-vector is up
    static Matrix3 lookAt(Point3 eye, Point3 target, Versor3 up);

    // returns a rotation
    static Matrix3 toFrom(Versor3 to, Versor3 from);

    static Matrix3 toFrom(Vector3 to, Vector3 from);

    // conversions to this representation
    static Matrix3 from( Quaternion m );
    static Matrix3 from( Euler e );     
    static Matrix3 from( AxisAngle e );

    // does this Matrix3 encode a rotation?
    bool isRot() const;

    // return a rotation matrix around an axis
    static Matrix3 rotationX( Scalar angleDeg ); 
    static Matrix3 rotationY( Scalar angleDeg );  
    static Matrix3 rotationZ( Scalar angleDeg );   

    friend std::ostream& operator<<(std::ostream&, const Matrix3&);

    void printf() const;
};


inline std::ostream& operator<<(std::ostream& strm, const Matrix3& a) {
    return strm << "Matrix3: [" << a.axisX()[0] << ", " << a.axisY()[0] << ", " << a.axisZ()[0] << std::endl <<
        a.axisX()[1] << ", " << a.axisY()[1] << ", " << a.axisZ()[1] << std::endl <<
        a.axisX()[2] << ", " << a.axisY()[2] << ", " << a.axisZ()[2] << "]";

}  

// interpolation of roations
inline Matrix3 directLerp( const Matrix3& a,const Matrix3& b, Scalar t){
    // TODO M-directLerp: how to interpolate Matrix3s
    return Matrix3();
}

//Non la fate (converti prima ad altro)
inline Matrix3 lerp( const Matrix3& a,const Matrix3& b, Scalar t){
	AxisAngle aAxis = AxisAngle::from(a);
	AxisAngle bAxis = AxisAngle::from(b);
	AxisAngle lerped = lerp(aAxis, bAxis, t);
    return Matrix3::from(lerped);
}




