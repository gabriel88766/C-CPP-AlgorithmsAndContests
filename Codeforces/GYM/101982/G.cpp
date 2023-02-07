#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef long double type;
//features will be added soon.
//looks like type is necessary 600D(codeforces)
bool ge(type a, type b){
    return a + EPS > b;
}
bool le(type a, type b){
    return a - EPS < b;
}
bool eq(type a, type b){
    return ge(a,b) && le(a,b);
}

struct Point{
    type x, y;
    Point(){}
    Point(type x, type y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(type d){ return Point(x * d, y * d);}
    Point operator /(type d){ return Point(x/d, y/d);}

    type abs() {return sqrtl(x*x+y*y); }
    type dist(Point p){ return (*this-p).abs();}
    type arg() { return atan2l(y, x); }

    type dot(Point p){ return x*p.x + y*p.y;}
    type cross(Point p){ return x*p.y - y*p.x;} //if pos, p is in left of vector (x, y), right otherwise
    Point rot(type g){// g degrees
        g *= PI/180;
        return Point(x * cosl(g) - y * sinl(g), x * sinl(g) + y * cosl(g));
    }
    bool onSeg(Point a, Point b){ //check if point on seg AB
        type rot = (*this - a).cross(b-a);
        if(!eq(rot, 0)) return false;
        return ge(x, min(a.x, b.x)) && le(x, max(a.x, b.x)) && ge(y, min(a.y, b.y)) && le(y, max(a.y, b.y));
    }
};

Point intersectLines(Point a1, Point d1, Point a2, Point d2){
    return (a1 + (d1 * ((a2-a1).cross(d2) / d1.cross(d2)))); 
}

type distanceToSeg(Point a, Point b, Point x){
    Point y = intersectLines(a, b-a, x, (b-a).rot(90));
    if(y.onSeg(a,b)) return x.dist(y);
    else return min(x.dist(a), x.dist(b));
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    type x,y,x1,x2,y1,y2,d,mind;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    Point a(x,y), p1(x1,y1), p2(x1,y2), p3(x2,y2), p4(x2,y1); //p1=p2 and p4, p3=p2 and p4
    Point dir;
    //test 4 distances
    d = distanceToSeg(p1, p2, a);
    mind = d;
    d = distanceToSeg(p1, p4, a);
    mind = min(mind,d);
    d = distanceToSeg(p3, p2, a);
    mind = min(mind,d);
    d = distanceToSeg(p3, p4, a);
    mind = min(mind,d);
    cout << fixed << setprecision(3) << mind;
}
