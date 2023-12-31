// Defined a struct of point, and named it Point(x,y).
#ifndef AREA_H
#define AREA_H

typedef struct point {
    const double x;
    const double y;
} Point;

// Defined a struct of circle, and named it Circle(Point(x,y), r).
typedef struct circle {
    Point center; // center point of the circle
    double radius;
} Circle;

static double square(const double x) {
    return x * x;
}

// calculate the squared distance of two points
static double distanceSquared(const Point p1, const Point p2) {
    return square(p1.x - p2.x) + square(p1.y - p2.y);
}

// predicate the point(x, y) whether inside the circle(circleX, circleY, circleRadius)
static int isInside(const Point point, const Circle circle) {
    return distanceSquared(point, circle.center) < square(circle.radius);
}
#endif // AREA_H
