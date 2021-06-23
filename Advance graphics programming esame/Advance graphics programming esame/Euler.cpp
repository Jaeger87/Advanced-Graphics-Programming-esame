#pragma once

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

	// TODO E-Ide: this constructor construct the identity rotation
	Euler::Euler() {}

	// TODO E-Constr
	// row major order!
	Euler::Euler(Scalar m00, Scalar m01, Scalar m02,
		Scalar m10, Scalar m11, Scalar m12,
		Scalar m20, Scalar m21, Scalar m22)
	{
	}

	Vector3 Euler::apply(Vector3  v) const {
		// TODO E-App: how to apply a rotation of this type?
		return Vector3();
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

	Versor3 Euler::axisX() const { return Versor3::forward(); }  // TODO E-Ax a
	Versor3 Euler::axisY() const { return Versor3::forward(); }   // TODO E-Ax b
	Versor3 Euler::axisZ() const { return Versor3::forward(); }   // TODO E-Ax c

	// conjugate
	Euler Euler::operator * (Euler b) const {
		return Euler();
	}

	//Non la fate (converti prima ad altro)
	Euler Euler::inverse() const {
		// TODO E-Inv a
		return Euler();
	}

	void Euler::invert() const {
		// TODO E-Inv b
	}

	// specific methods for Eulers...
	Euler Euler::transposed() const {
		// TODO E-Transp a
		return Euler();
	}

	void Euler::transpose() {
		// TODO E-Transp b
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
	Euler Euler::from(Quaternion m) { return Euler(); }// TODO Q2M
	Euler Euler::from(Euler e) { return Euler(); }     // TODO E2M
	Euler Euler::from(AxisAngle e) { return Euler(); } // TODO E2M

	// does this Euler encode a rotation?
	bool Euler::isRot() const {
		// TODO E-isR
		return false;
	}

	// return a rotation matrix around an axis
	Euler Euler::rotationX(Scalar angleDeg) { return Euler(); }   // TODO E-Rx
	Euler Euler::rotationY(Scalar angleDeg) { return Euler(); }   // TODO E-Rx
	Euler Euler::rotationZ(Scalar angleDeg) { return Euler(); }   // TODO E-Rx

	void Euler::printf() const { std::cout << *this << std::endl; } 


