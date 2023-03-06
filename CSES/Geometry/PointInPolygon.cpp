#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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

    bool operator ==(Point p){ return eq(x, p.x) && eq(y, p.y);}
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
        type rot = (*this - a).cross(b-a); 
        rot /= (b-a).abs(); //precision issue, divide rot by (b-a).abs() if double
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


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<Point> v;
    for(int i=0;i<n;i++){
        long double a, b;
        cin >> a >> b;
        Point aux(a, b);
        v.push_back(aux);
    }
    v.push_back(v[0]);
    for(int i=0;i<m;i++){
        long double a, b;
        cin >> a >> b;
        Point c(a, b);
        bool on = false;
        for(int j=0;j<n;j++){
            if(c.onSeg(v[j], v[j+1])) on = true;
        }
        if(on) cout << "BOUNDARY\n";
        else{
            Point dir = Point(1.451644845121, 1.2356412558482);
            int cnt = 0;
            for(int j=0;j<n;j++){
                auto x = intersectLines(c, dir, v[j], v[j+1] - v[j]);
                auto y = x - c;
                if(le(x.x, a) || le(x.y, b)) continue;
                if(x.onSeg(v[j], v[j+1])) cnt++;
            }
            if(cnt % 2) cout << "INSIDE\n";
            else cout << "OUTSIDE\n";
            
        }
    }
}
