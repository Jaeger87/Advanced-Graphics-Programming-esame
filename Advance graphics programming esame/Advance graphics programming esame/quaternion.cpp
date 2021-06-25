#include <math.h>
#include "vector3.h"
#include "point3.h"
#include "versor3.h"
#include "quaternion.h"
#include "euler.h";
#include "axis_angle.h";
#include "matrix3.h";

/* Quaternion class */
/* this class is a candidate to store a rotation! */
/* as such, it implements all expected methods    */

	Quaternion Quaternion::identity() { return Quaternion(0, 0, 0); }

	Quaternion::Quaternion(Scalar _realPart, Vector3 _imaginaryPart) : realPart(_realPart), imaginaryPart(_imaginaryPart) { }

	Quaternion::Quaternion(Scalar a, Scalar b, Scalar c) :realPart(0), imaginaryPart(Vector3(a, b, c)) {}

	Quaternion::Quaternion() :realPart(1), imaginaryPart(Vector3(0, 0, 0)) { }

	// returns a quaternion encoding a point
	Quaternion::Quaternion(const Point3& p) :realPart(0), imaginaryPart(Vector3(p.x, p.y, p.z)) {}

	Vector3 Quaternion::apply(Vector3  v) const {
		Quaternion result = *this * Quaternion(v.asPoint()) * this->conjugated();
		return result.imaginaryPart;
	}

	// Rotations can be applied to versor or vectors just as well
	Versor3 Quaternion::apply(Versor3 dir) const {
		return apply(dir.asVector()).asVersor();
	}

	Point3 Quaternion::apply(Point3 p) const {
		return apply(p.asVector()).asPoint();
	}

	// syntactic sugar: "R( p )" as a synomim of "R.apply( p )"
	Versor3 Quaternion::operator() (Versor3 p) { return apply(p); }
	Point3  Quaternion::operator() (Point3  p) { return apply(p); }
	Vector3 Quaternion::operator() (Vector3 p) { return apply(p); }

	Versor3 Quaternion::axisX() const { return Matrix3::from(*this).axisX(); }
	Versor3 Quaternion::axisY() const { return Matrix3::from(*this).axisY(); }
	Versor3 Quaternion::axisZ() const { return Matrix3::from(*this).axisZ(); } 

	// conjugate
	Quaternion Quaternion::operator * (Quaternion r) const {
		Scalar newRealPart = dot(this->imaginaryPart, r.imaginaryPart) + this->realPart * r.realPart;
		Vector3 newImaginary = this->imaginaryPart * r.realPart + r.imaginaryPart * this->realPart + cross(this->imaginaryPart, r.imaginaryPart);
		return Quaternion(newRealPart, newImaginary);
	}

	Quaternion Quaternion::inverse() const {
		Scalar squaredNorm = this->squaredNorm();
		return Quaternion(realPart / squaredNorm, -imaginaryPart / squaredNorm);
	}

	void Quaternion::invert() {
		imaginaryPart = -imaginaryPart;
	}

	// specific methods for quaternions...
	Quaternion Quaternion::conjugated() const {
		return Quaternion(realPart, -imaginaryPart);
	}

	void Quaternion::conjugate() {
		imaginaryPart = -imaginaryPart;
	}

	Scalar Quaternion::squaredNorm() const
	{
		return pow(realPart, 2) + pow(imaginaryPart.x, 2) + pow(imaginaryPart.y, 2) + pow(imaginaryPart.z, 2);
	}

	// returns a rotation to look toward target, if you are in eye, and the up-vector is up
	Quaternion Quaternion::lookAt(Point3 eye, Point3 target, Versor3 up) {
		// TODO Q-LookAt
		return Quaternion();
	}

	// returns a rotation
	Quaternion Quaternion::toFrom(Versor3 to, Versor3 from) {
		// TODO Q-ToFrom
		return Quaternion();
	}

	Quaternion Quaternion::toFrom(Vector3 to, Vector3 from) {
		return toFrom(normalize(to), normalize(from));
	}

	// conversions to this representation
	Quaternion Quaternion::from(Matrix3 m)
	{
		return Quaternion::from(AxisAngle::from(m));
	}
	Quaternion Quaternion::from(Euler e) // Trovato su internet: https://math.stackexchange.com/questions/2975109/how-to-convert-euler-angles-to-quaternions-and-get-the-same-euler-angles-back-fr
	{
		Scalar qx = sin(e.rollZ / 2) * cos(e.pitchX / 2) * cos(e.yawY / 2) - cos(e.rollZ / 2) * sin(e.pitchX / 2) * sin(e.yawY / 2);
		Scalar qy = cos(e.rollZ / 2) * sin(e.pitchX / 2) * cos(e.yawY / 2) + sin(e.rollZ / 2) * cos(e.pitchX / 2) * sin(e.yawY / 2);
		Scalar qz = cos(e.rollZ / 2) * cos(e.pitchX / 2) * sin(e.yawY / 2) - sin(e.rollZ / 2) * sin(e.pitchX / 2) * cos(e.yawY / 2);
		Scalar qw = cos(e.rollZ / 2) * cos(e.pitchX / 2) * cos(e.yawY / 2) + sin(e.rollZ / 2) * sin(e.pitchX / 2) * sin(e.yawY / 2);
		return Quaternion(qw, Vector3(qx, qy, qz));
	}

	Quaternion Quaternion::from(AxisAngle e) //formula trovata nell'internet: https://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToQuaternion/index.htm
	{
		Scalar sinAngle = sin(e.angle / 2);
		Vector3 newImaginaryPart = Vector3(e.axis.x * sinAngle, e.axis.y * sinAngle, e.axis.z * sinAngle);
		Scalar newRealPart = cos(e.angle / 2);
		return Quaternion(newRealPart, newImaginaryPart);
	}

	// does this quaternion encode a rotation?
	bool Quaternion::isRot() const {
		Scalar squaredNorm = realPart * realPart + imaginaryPart.x * imaginaryPart.x +
			imaginaryPart.y * imaginaryPart.y + imaginaryPart.z * imaginaryPart.z;
		return squaredNorm >= 1 - std::numeric_limits<double>::epsilon() && squaredNorm >= 1 + std::numeric_limits<double>::epsilon();
	}

	// does this quaternion encode a point?
	bool Quaternion::isPoint() const {
		// TODO Q-isP
		return false;
	}

	void Quaternion::printf() const {
		std::cout << *this << std::endl;
	}
