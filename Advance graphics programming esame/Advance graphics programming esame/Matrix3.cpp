#pragma once

#include <math.h>
#include "vector3.h"
#include "point3.h"
#include "versor3.h"
#include "matrix3.h"
#include "quaternion.h"
#include "euler.h"
#include "axis_angle.h"

/* Matrix3 class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all the expected methods    */

class Quaternion;
class AxisAngle;
class Euler;



    Matrix3::Matrix3() : Matrix3(Versor3::right(), Versor3::up(), Versor3::forward()) {}


    // constructor that takes as input the coefficient (RAW-MAJOR order!)
    Matrix3::Matrix3(Scalar m00, Scalar m01, Scalar m02,
        Scalar m10, Scalar m11, Scalar m12,
        Scalar m20, Scalar m21, Scalar m22) : Matrix3(Vector3(m00, m10, m20).asVersor(),
            Vector3(m01, m11, m21).asVersor(),
            Vector3(m02, m12, m22).asVersor()) {
    }

    Matrix3::Matrix3(Versor3 column1, Versor3 column2, Versor3 column3) :matrix{ column1, column2, column3 } {}


    Vector3 Matrix3::apply(Vector3  v) const {
        // Matrice per vettore: dot product per ogni riga col vettore v

        Vector3 row1 = Vector3(matrix[0].x, matrix[1].x, matrix[2].x);
        Vector3 row2 = Vector3(matrix[0].y, matrix[1].y, matrix[2].y);
        Vector3 row3 = Vector3(matrix[0].z, matrix[1].z, matrix[2].z);
        return Vector3(dot(row1, v), dot(row2, v), dot(row3, v));
    }

    // Rotations can be applied to versors or vectors just as well
    Versor3 Matrix3::apply(Versor3 dir) const {
        return apply(dir.asVector()).asVersor();
    }

    Point3 Matrix3::apply(Point3 p) const {
        return apply(p.asVector()).asPoint();
    }

    // syntactic sugar: "R( p )" as a synomim of "R.apply( p )"
    Versor3 Matrix3::operator() (Versor3 p) { return apply(p); }
    Point3  Matrix3::operator() (Point3  p) { return apply(p); }
    Vector3 Matrix3::operator() (Vector3 p) { return apply(p); }

    Versor3 Matrix3::axisX() const
    {
        return matrix[0];
    }
    Versor3 Matrix3::axisY() const
    {
        return matrix[1];
    }
    Versor3 Matrix3::axisZ() const
    {
        return matrix[2];
    }

    // combine two rotations (r goes first!)
    Matrix3 Matrix3::operator * (Matrix3 r) const {
        Vector3 row1 = Vector3(matrix[0].x, matrix[0].y, matrix[0].z);
        Vector3 row2 = Vector3(matrix[1].x, matrix[1].y, matrix[1].z);
        Vector3 row3 = Vector3(matrix[2].x, matrix[2].y, matrix[2].z);
        return Matrix3(dot(row1,matrix[0].asVector()), dot(row1, matrix[1].asVector()), dot(row1, matrix[2].asVector()),
            dot(row2, matrix[0].asVector()), dot(row2, matrix[1].asVector()), dot(row2, matrix[2].asVector()),
            dot(row3, matrix[0].asVector()), dot(row3, matrix[1].asVector()), dot(row3, matrix[2].asVector()));
    }

    Matrix3 Matrix3::inverse() const {
        return Matrix3(matrix[0].x, matrix[0].y, matrix[0].z,
            matrix[1].x, matrix[1].y, matrix[1].z,
            matrix[2].x, matrix[2].y, matrix[2].z);
    }

    void Matrix3::invert() {
        Matrix3 newMatrix = inverse();
        matrix[0] = newMatrix.axisX();
        matrix[1] = newMatrix.axisY();
        matrix[2] = newMatrix.axisZ();
    }

    // returns a rotation to look toward target, if you are in eye, and the up-vector is up
    Matrix3 Matrix3::lookAt(Point3 eye, Point3 target, Versor3 up) {
        // TODO M-LookAt
        return Matrix3();
    }

    // returns a rotation
    Matrix3 Matrix3::toFrom(Versor3 to, Versor3 from) {
        // TODO M-ToFrom
        return Matrix3();
    }

    Matrix3 Matrix3::toFrom(Vector3 to, Vector3 from) {
        return toFrom(normalize(to), normalize(from));
    }

    // conversions to this representation
    Matrix3 Matrix3::from(Quaternion m) { return Matrix3(); }// TODO Q2M
    Matrix3 Matrix3::from(Euler e) {

        return Matrix3(); 
    }     // TODO E2M
    Matrix3 Matrix3::from(AxisAngle e) { return Matrix3(); } // TODO A2M

    // does this Matrix3 encode a rotation?
    bool Matrix3::isRot() const {
        // TODO M-isR
        return false;
    }

    // return a rotation matrix around an axis
    Matrix3 Matrix3::rotationX(Scalar angleDeg) { return Matrix3(); }   // TODO M-Rx
    Matrix3 Matrix3::rotationY(Scalar angleDeg) { return Matrix3(); }   // TODO M-Ry
    Matrix3 Matrix3::rotationZ(Scalar angleDeg) { return Matrix3(); }   // TODO M-Rz


    void Matrix3::printf() const {
        std::cout << *this << std::endl;
    }


/*
std::ostream& operator<<(std::ostream& strm, const Matrix3& a) {
    return strm << "Matrix3: [" << a.axisX()[0] << ", " << a.axisY()[0] << ", " << a.axisZ()[0] << std::endl <<
        a.axisX()[1] << ", " << a.axisY()[1] << ", " << a.axisZ()[1] << std::endl <<
        a.axisX()[2] << ", " << a.axisY()[2] << ", " << a.axisZ()[2] << "]";

}
*/




