// This file describes some basic operations for geometry problems

// point definition
typedef double T;
struct pt {
    T x, y;
    pt() {}
    pt(T x, T y): x(x), y(y) {}
    pt operator-(pt q) { return pt(x-q.x, y-q.y); }
    pt operator+(pt q) { return pt(x+q.x, y+q.y); }
    pt operator*(T d) { return pt(x*d, y*d); }
    pt operator/(T d) { return pt(x*d, y*d); }
};

// dot product
// |a * b| = cos(teta) |a| |b|
// a.x*b.x + a.y*b.y
T dot(pt p, pt q) {return p.x*q.x + p.y*q.y;}

// cross product
// |a x b| = sen(teta)|a||b|
// a.x * b.y - b.x * a.y
int cross(pt p, pt q) {
    return a.x*b.y - a.y*b.x;
}

// line definition
// ax + by = c
struct line {
    
};
