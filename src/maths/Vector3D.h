/*
 * File:   Vector3D.h
 * Author: nadrieril
 *
 * Created on March 11, 2014, 7:57 PM
 */

#ifndef VECTOR3D_H
#define	VECTOR3D_H
#include <cmath>

class Vector3D {
public:
    Vector3D() : v {0., 0., 0.}{};
    Vector3D(double x, double y, double z) : v {x, y, z}{};
    Vector3D(const Vector3D& orig);
    virtual ~Vector3D();

	void set(double x, double y, double z){v[0]=x; v[1]=y; v[2]=z;};
	void setX(double x){v[0]=x;};
	void setY(double y){v[1]=y;};
	void setZ(double z){v[2]=z;};
	double getX(){return v[0];};
	double getY(){return v[1];};
	double getZ(){return v[2];};

	double length() const;
	double length2() const;
	double length3() const;

	friend Vector3D operator+(Vector3D const& v1, Vector3D const& v2);
	Vector3D operator+=(Vector3D const& other);
	friend Vector3D operator-(Vector3D const& v1, Vector3D const& v2);
	Vector3D operator-=(Vector3D const& other);

	friend double operator*(Vector3D const& v1, Vector3D const& v2);

	friend Vector3D operator*(Vector3D const& v, double const& k);
	friend Vector3D operator*(double const& k, Vector3D const& v) {return v * k;};
	Vector3D operator*=(double const& k);
	friend Vector3D operator/(Vector3D const& v, double const& k);
	friend Vector3D operator/(double const& k, Vector3D const& v) {return v / k;};
	Vector3D operator/=(double const& k);

protected:
    double v[3];
};




#endif	/* VECTOR3D_H */

