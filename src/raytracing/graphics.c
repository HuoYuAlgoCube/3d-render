#include "graphics.h"

#include <math.h>
#include <stdlib.h>

Vec3 pSub(Point3 p1,Point3 p2){
    Vec3 v;
    v.x = p1.x - p2.x;
    v.y = p1.y - p2.y;
    v.z = p1.z - p2.z;
    return v;
}
Point3 pvAdd(Point3 p,Vec3 v){
    Point3 p1;
    p1.x = p.x + v.x;
    p1.y = p.y + v.y;
    p1.z = p.z + v.z;
    return p1;
}
Vec3 vAdd(Vec3 v1,Vec3 v2){
    Vec3 v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    return v3;
}
Vec3 vSmul(Vec3 v,double k){
    Vec3 v1;
    v1.x = v.x*k;
    v1.y = v.y*k;
    v1.z = v.z*k;
    return v1;
}
double vDot(Vec3 v1,Vec3 v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
Vec3 vCross(Vec3 v1,Vec3 v2){
    Vec3 v3;
    v3.x = v1.y*v2.z - v1.z*v2.y;
    v3.y = v1.z*v2.x - v1.x*v2.z;
    v3.z = v1.x*v2.y - v1.y*v2.x;
    return v3;
}
double vLen(Vec3 v){
    return sqrt(vDot(v,v));
}

Vec3 vNorm(Vec3 v){
    Vec3 v1 = vSmul(v,1.0/vLen(v));
    return v1;
}
Vec3 vNeg(Vec3 v){
    return vSmul(v,-1);
}

Point3 pointOnRay(Ray ray,double t){
    Point3 p = pvAdd(ray.O,vSmul(ray.D,t));
    return p;
}

int solveQuadratic(double a, double b, double c, double *x1, double *x2)
{
    if (x1 == NULL || x2 == NULL) {
        return -1;
    }

    if (a == 0.0) {
        if (b == 0.0) {
            return -3;
        }
        return -2;
    }

    double disc = b * b - 4.0 * a * c;

    if (disc < 0.0) {
        return 0;
    }

    double r1, r2;

    if (disc == 0.0) {
        r1 = r2 = -b / (2.0 * a);
        *x1 = r1;
        *x2 = r2;
        return 1;
    }

    double sqrt_disc = sqrt(disc);
    double q = -0.5 * (b + copysign(sqrt_disc, b));

    r1 = q / a;
    r2 = c / q;

    if (r1 > r2) {
        double tmp = r1;
        r1 = r2;
        r2 = tmp;
    }

    *x1 = r1;
    *x2 = r2;

    return 2;
}

int intersectRaySphere(Ray ray,Sphere sphere, double *t0, double *t1){
    if (t0 == NULL || t1 == NULL) {
        return -1;
    }
    Vec3 CO = pSub(ray.O,sphere.C);
    double a = vDot(ray.D,ray.D);
    double b = vDot(CO,ray.D)*2;
    double c = vDot(CO,CO) - sphere.r*sphere.r;
    return solveQuadratic(a,b,c,t0,t1);
}
