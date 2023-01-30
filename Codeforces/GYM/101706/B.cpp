//Unsolved.
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9, INF = 1e20; 
using namespace std;

//features will be added soon.
//looks like long double is necessary 600D(codeforces)
typedef long double type;
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
    type aux1, aux2;
    cin >> aux1 >> aux2;
    Point a(aux1,aux2);
    cin >> aux1 >> aux2;
    Point b(aux1,aux2);
    cin >> aux1 >> aux2;
    Point c(aux1,aux2);
    cin >> aux1 >> aux2;
    Point d(aux1,aux2);
    cout << fixed << setprecision(15);
    //A to C
    cout << a.dist(c) << "\n";
    //A to CD
    Point y = intersectLines(d, d-c, a, (d-c).rot(90));
    if(y.onSeg(c,d)) cout << a.dist(y) << "\n";
    else cout << min(a.dist(c), a.dist(d)) << "\n";
    //A to half infinite ray CD
    if(y.onSeg(c, c+(d-c)*3e4)) cout << a.dist(y) << "\n";
    else cout << a.dist(c) << "\n";
    //A to line CD
    cout << a.dist(y) << "\n";
    //AB to point C
    y = intersectLines(a, b-a, c, (b-a).rot(90));
    if(y.onSeg(a,b)) cout << c.dist(y) << "\n";
    else cout << min(c.dist(a), c.dist(b)) << "\n";
    //AB to seg CD
    //fuck this shit!!
    //check if paralel, if no, check if intersect.
    cout << "\n";

    //Line AB to C
    y = intersectLines(a, b-a, c, (b-a).rot(90));
    cout << y.dist(c) << "\n";
    //line ab to seg cd
}
