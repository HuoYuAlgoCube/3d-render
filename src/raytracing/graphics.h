#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct {
    double x,y;
}Point2;

typedef struct {
    double x,y,z;
}Point3;

typedef struct {
    double x,y,z;
}Vec3;

typedef struct {
    double x,y;
}Vec2;

typedef struct {
    double w,h,x,y;
}Rect;

typedef struct {
    Point3 O;
    Vec3 D;
}Ray;

typedef struct{
    double r;
    Point3 C;
}Sphere;

Vec3 pSub(Point3 p1,Point3 p2);
Point3 pvAdd(Point3 p,Vec3 v);
Vec3 vAdd(Vec3 v1,Vec3 v2);
Vec3 vSmul(Vec3 v,double k);
double vDot(Vec3 v1,Vec3 v2);
Vec3 vCross(Vec3 v1,Vec3 v2);
double vLen(Vec3 v);
Vec3 vNorm(Vec3 v);
Vec3 vNeg(Vec3 v);

int solveQuadratic(double a,double b,double c,double* x1,double* x2);
Point3 pointOnRay(Ray ray,double t);

int intersectRaySphere(Ray ray,Sphere sphere, double *t0, double *t1);

#endif
