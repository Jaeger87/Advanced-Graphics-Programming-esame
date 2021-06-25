# Advanced Graphics Programming esame


Classe | Metodo 
------------ | -------------
Vector3|void printf()
Point3|void printf()
Versor3|void printf()
Versor3|nlerp( const Versor3& a,const Versor3& b, Scalar t)
Versor3|slerp( const Versor3& a,const Versor3& b, Scalar t)
Versor3|Vector3::asVersor()
quaternion|Vector3::printf()
quaternion|Q-Fields and constructor
quaternion|Q-Ide: this constructor construct the identity rotation
Transform|lerp( const Transform &a, const Transform &b, float t )
quaternion|printf()
Matrix3|M-Ide: this constructor construct the identity rotation
Matrix3|M-Fields: which fields to store? (also add a constuctor taking these fields).
Matrix3|Vector3 apply( Vector3  v) const.
Matrix3|Versor3 axisX()
Matrix3|Versor3 axisY()
Matrix3|Versor3 axisZ()
Matrix3|inverse() const
Matrix3|invert() const
Matrix3|printf() const
Transform|invert() 
Euler|E-Fields
AxisAngle|A-Field
AxisAngle|invert()
AxisAngle|inverse()
Quaternion|invert()
Quaternion|inverse()
Quaternion|conjugated()
Quaternion|conjugate()
Quaternion|Q-Constr
Quaternion|Q-FromPoint()
Quaternion|apply(Vector3  v)
Quaternion|from(AxisAngle e)
AxisAngle|A-Ide: this constructor construct the identity rotation
AxisAngle|A-FromPoint
AxisAngle|apply( Vector3  v)
AxisAngle|from(Quaternion q)
AxisAngle|printf()
Euler|printf()
Euler|from(Matrix3 m)
Quaternion|from(Euler e)
Euler|isRot()
Euler|from(Quaternion q)
Euler|inverse()
Euler|invert()
Euler|lerp()
Euler|axisX()
Euler|axisY()
Euler|axisZ()
Matrix3|operator *
Quaternion|axisX()
Quaternion|axisY()
Quaternion|axisZ()
Euler|operator *
AxisAngle|axisX()
AxisAngle|axisY()
AxisAngle|axisZ()
Euler|transposed()
Euler|transpose()
Euler|Euler()
Euler|Euler(Scalar m00, Scalar m01, Scalar m02,Scalar m10, Scalar m11, Scalar m12,Scalar m20, Scalar m21, Scalar m22)
Euler|apply(Vector3 v)
Quaternion|from(Matrix3 m)
Matrix3|lerp( const Matrix3& a,const Matrix3& b, Scalar t)
Euler|from(AxisAngle e)
AxisAngle|from(Matrix3 m)
AxisAngle|from(Euler e) 
Quaternion|isRot()
Euler|rotationX(Scalar angleDeg)
Euler|rotationY(Scalar angleDeg)
Euler|rotationZ(Scalar angleDeg)
Matrix3|rotationX(Scalar angleDeg)
Matrix3|rotationY(Scalar angleDeg)
Matrix3|rotationZ(Scalar angleDeg)
Matrix3|from(Quaternion q)
Matrix3|from(AxisAngle a)