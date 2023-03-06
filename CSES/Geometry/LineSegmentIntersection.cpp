#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


//features will be added soon.
//looks like type is necessary 600D(codeforces)
typedef long double type; //if long long int, EPS = 0
bool ge(type a, type b){
    return a + EPS >= b;
}
bool le(type a, type b){
    return a - EPS <= b;
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

    Point rot90(){ //can handle intergers.
        return Point(-y, x);
    }
    bool onSeg(Point a, Point b){ //check if point on seg AB
        type rot = ((*this - a).cross(b-a))/(b-a).abs();
        if(!eq(rot, 0)) return false;
        return ge(x, min(a.x, b.x)) && le(x, max(a.x, b.x)) && ge(y, min(a.y, b.y)) && le(y, max(a.y, b.y));
    }
};

//if long long, d1.cross(d2) != 0, Point returned will have integers coordinates. test onSeg.
Point intersectLines(Point a1, Point d1, Point a2, Point d2){ //If Long long, treat d1.cross(d2) == 0
    return a1 + (d1 * ((a2-a1).cross(d2))) / d1.cross(d2); 
}
//ToLine => return x.dist(y);
type distanceToSeg(Point a, Point b, Point x){
    Point y = intersectLines(a, b-a, x, (b-a).rot(90));
    if(y.onSeg(a,b)) return x.dist(y);
    else return min(x.dist(a), x.dist(b));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    while(n--){
        long double x,y;
        cin >> x >> y;
        Point a(x,y);
        cin >> x >> y;
        Point b(x,y);
        cin >> x >> y;
        Point c(x,y);
        cin >> x >> y;
        Point d(x,y);
        if(eq((b-a).cross(d-c), 0)){
            if(b.onSeg(c,d) || a.onSeg(c,d) || c.onSeg(a,b) || d.onSeg(a,b)) cout << "YES\n";
            else cout << "NO\n";
        }else{
            Point y = intersectLines(a, b-a, c, d-c);
            if(y.onSeg(a,b) && y.onSeg(c,d)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}