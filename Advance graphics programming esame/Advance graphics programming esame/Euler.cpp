#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "vector3.h"
#include "point3.h"
#include "versor3.h"
#include "quaternion.h"
#include "euler.h";
#include "axis_angle.h";
#include "matrix3.h";
/* Euler class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all the expected methods    */

	Euler::Euler(): pitchX(0), yawY(0),rollZ(0) {}

	// TODO E-Constr
	Euler::Euler(Scalar m00, Scalar m01, Scalar m02,
		Scalar m10, Scalar m11, Scalar m12,
		Scalar m20, Scalar m21, Scalar m22)
	{
		Matrix3 matrix3 = Matrix3(m00, m01, m02, m10, m11, m12, m20, m21, m22);
		Euler e = Euler::from(matrix3);
		Euler::pitchX = e.pitchX;
		Euler::yawY = e.yawY;
		Euler::rollZ = e.rollZ;
	}

	Euler::Euler(Scalar _pitchX, Scalar _yawY, Scalar _rollZ):pitchX(_pitchX), yawY(_yawY), rollZ(_rollZ) {}

	Vector3 Euler::apply(Vector3  v) const {
		Matrix3 matrix3 = Matrix3::from(*this);
		return matrix3.apply(v);
	}

	// Rotations can be applied to versors or vectors just as well
	Versor3 Euler::apply(Versor3 dir) const {
		return apply(dir.asVector()).asVersor();
	}

	Point3 Euler::apply(Point3 p) const {
		return apply(p.asVector()).asPoint();
	}

	// syntactic sugar: "R( p )" as a synomim of "R.apply( p )"
	Versor3 Euler::operator() (Versor3 p) { return apply(p); }
	Point3  Euler::operator() (Point3  p) { return apply(p); }
	Vector3 Euler::operator() (Vector3 p) { return apply(p); }

	Versor3 Euler::axisX() const { return Matrix3::from(*this).axisX(); } 
	Versor3 Euler::axisY() const { return Matrix3::from(*this).axisY(); }
	Versor3 Euler::axisZ() const { return Matrix3::from(*this).axisZ(); }

	// conjugate
	Euler Euler::operator * (Euler b) const {
		Quaternion thisAsQ = Quaternion::from(*this);
		Quaternion bAsQ = Quaternion::from(b);
		Quaternion newQuaternion = thisAsQ * bAsQ;
		return Euler::from(newQuaternion);
	}

	//Non la fate (converti prima ad altro)
	Euler Euler::inverse() const {
		return Euler::from(Quaternion::from(*this).inverse());
	}

	void Euler::invert() {
		Euler inverse = Euler::inverse();
		pitchX = inverse.pitchX;
		rollZ = inverse.rollZ;
		yawY = inverse.yawY;
	}

	//non fatela!
	// specific methods for Eulers...
	Euler Euler::transposed() const {
		return Euler::from(Matrix3::from(*this));
	}

	void Euler::transpose() {
		Euler transposed = Euler::transposed();
		this->rollZ = transposed.rollZ;
		this->yawY = transposed.yawY;
		this->pitchX = transposed.pitchX;
	}

	// returns a rotation to look toward target, if you are in eye, and the up-vector is up
	Euler Euler::lookAt(Point3 eye, Point3 target, Versor3 up = Versor3::up()) {
		// TODO E-LookAt
		return Euler();
	}

	// returns a rotation
	Euler Euler::toFrom(Versor3 to, Versor3 from) {
		// TODO E-ToFrom
		return Euler();
	}

	Euler Euler::toFrom(Vector3 to, Vector3 from) {
		return toFrom(normalize(to), normalize(from));
	}

	// conversions to this representation
	Euler Euler::from(Quaternion q) {
		return Euler::from(Matrix3::from(q));
	}
	Euler Euler::from(Matrix3 m) {
		Euler e;
		Scalar sp = -m.matrix[1].z;
		if (sp <= -1.0)
			e.pitchX = -M_PI_2;
		else if (sp >= 1.0)
			e.pitchX = M_PI_2;
		else
			e.pitchX = asin(sp);

		//Check for the Gimbal Lock, give some tolerance
		Scalar tol = 1.0 - std::numeric_limits<double>::epsilon();
		if (abs(sp) > tol)
		{
			//looking straight up or down
			e.rollZ = 0.0;
			e.yawY = atan2(-m.matrix[2].y, m.matrix[0].x);
		}
		else
		{
			e.yawY = atan2(m.matrix[0].z, m.matrix[2].z);
			e.rollZ = atan2(m.matrix[1].x, m.matrix[1].y);
		}
		return e;
	}  
	Euler Euler::from(AxisAngle e) { 
		return Euler::from(Matrix3::from(e)); 
	}

	// does this Euler encode a rotation?
	bool Euler::isRot() const {
		return Matrix3::from(*this).isRot();
	}

	// return a rotation matrix around an axis
	Euler Euler::rotationX(Scalar angleDeg) { return Euler(angleDeg,0,0); }  
	Euler Euler::rotationY(Scalar angleDeg) { return Euler(0,angleDeg,0); } 
	Euler Euler::rotationZ(Scalar angleDeg) { return Euler(0,0,angleDeg); } 

	void Euler::printf() const { std::cout << *this << std::endl; } 


