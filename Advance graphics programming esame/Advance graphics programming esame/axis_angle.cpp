#include <math.h>
#include "versor3.h"
#include "quaternion.h"
#include "euler.h";
#include "axis_angle.h";
#include "matrix3.h";

/* AxisAngle class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all expected methods    */



	AxisAngle::AxisAngle() : axis(Versor3::forward()), angle(0) {}

	// returns a AxisAngle encoding a point
	AxisAngle::AxisAngle(const Point3& p) : axis(normalize(p.asVector())), angle(0) {}

	AxisAngle::AxisAngle(const Versor3 _axis, const Scalar _angle) : axis(_axis), angle(_angle) {}

	Vector3 AxisAngle::apply(Vector3  v) const {
		//Quaternion q = Quaternion::from(*this);
		//return q.apply(v);
		return Vector3();
	}

	// Rotations can be applied to versors or vectors just as well
	Versor3 AxisAngle::apply(Versor3 dir) const {
		return apply(dir.asVector()).asVersor();
	}

	Point3 AxisAngle::apply(Point3 p) const {
		return apply(p.asVector()).asPoint();
	}

	// syntactic sugar: "R( p )" as a synomim of "R.apply( p )"
	Versor3 AxisAngle::operator() (Versor3 p) { return apply(p); }
	Point3  AxisAngle::operator() (Point3  p) { return apply(p); }
	Vector3 AxisAngle::operator() (Vector3 p) { return apply(p); }

	Versor3 AxisAngle::axisX() const { return Versor3::forward(); }  // TODO A-Ax a
	Versor3 AxisAngle::axisY() const { return Versor3::forward(); }  // TODO A-Ax b
	Versor3 AxisAngle::axisZ() const { return Versor3::forward(); }  // TODO A-Ax c

	// conjugate
	AxisAngle AxisAngle::operator * (AxisAngle r) const {
		return AxisAngle();
	}

	AxisAngle AxisAngle::inverse() const {
		return AxisAngle(axis, -angle);
	}

	void AxisAngle::invert() {
		angle = -angle;
	}

	// returns a rotation to look toward target, if you are in eye, and the up-vector is up
	AxisAngle AxisAngle::lookAt(Point3 eye, Point3 target, Versor3 up) {
		// TODO A-LookAt
		return AxisAngle();
	}

	// returns a rotation
	AxisAngle AxisAngle::toFrom(Versor3 to, Versor3 from) {
		// TODO A-ToFrom
		return AxisAngle();
	}

	AxisAngle AxisAngle::toFrom(Vector3 to, Vector3 from) {
		return toFrom(normalize(to), normalize(from));
	}

	// conversions to this representation
	AxisAngle AxisAngle::from(Matrix3 m) { return AxisAngle(); }   // TODO M2A
	AxisAngle AxisAngle::from(Euler e) { return AxisAngle(); }     // TODO E2A

	AxisAngle AxisAngle::from(Quaternion q) // trovata su internet: https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToAngle/index.htm
	{
		Scalar angle = 2 * acos(q.realPart);
		Versor3 axis = normalize(q.imaginaryPart);
		return AxisAngle(axis, angle);
	}

	// does this AxisAngle encode a point?
	bool AxisAngle::isPoint() const {
		// TODO A-isP
		return false;
	}

	void AxisAngle::printf() const {
		std::cout << *this << std::endl;
	}





