/*
 * File:   Vector3D.cpp
 * Author: nadrieril
 *
 * Created on March 11, 2014, 7:57 PM
 */

#include "Vector3D.h"

Vector3D::Vector3D(const Vector3D& orig) {
    set(orig.v[0], orig.v[1], orig.v[2]);
}

Vector3D::~Vector3D() {
}


double Vector3D::length2() const {
    return (*this) * (*this);
};
double Vector3D::length() const {
    return sqrt(length2());
};
double Vector3D::length3() const {
    double l = length2();
    return l * sqrt(l);
};

Vector3D operator+(Vector3D const& v1, Vector3D const& v2) {return Vector3D(v1)+=v2;}
Vector3D Vector3D::operator+=(Vector3D const& other) {
    v[0]+=other.v[0]; v[1]+=other.v[1]; v[2]+=other.v[2];
    return *this;
}

Vector3D operator-(Vector3D const& v1, Vector3D const& v2) {return Vector3D(v1)-=v2;}
Vector3D Vector3D::operator-=(Vector3D const& other) {
    v[0]-=other.v[0]; v[1]-=other.v[1]; v[2]-=other.v[2];
    return *this;
}

Vector3D operator*(Vector3D const& v, double const& k) {return Vector3D(v)*=k;}
Vector3D Vector3D::operator*=(double const& k) {
    v[0]*=k; v[1]*=k; v[2]*=k;
    return *this;
}

Vector3D operator/(Vector3D const& v, double const& k) {return Vector3D(v)/=k;}
Vector3D Vector3D::operator/=(double const& k) {
    v[0]/=k; v[1]/=k; v[2]/=k;
    return *this;
}

double operator*(Vector3D const& v1, Vector3D const& v2) {
	return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2];
}
