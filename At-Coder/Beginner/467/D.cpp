#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef long long type;
template<typename T>
struct Point{
    T x, y;
    Point(){}
    Point(T x, T y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(T d){ return Point(x * d, y * d);}
    Point operator /(T d){ return Point(x/d, y/d);} //integer division, maybe not what you want.
    bool operator ==(Point p){
        if(std::is_floating_point<T>::value){
            return eq(x, p.x) && eq(y, p.y);
        }else{
            return x == p.x && y == p.y;
        }
    }
    double abs() {return sqrt(x*x+y*y); } //remove sqrt and use long long for more precision 
    double dist(Point p){ return (*this-p).abs();} //long long too
    // returns arg ∈ [0, 2π)
    double arg() { 
        double ang = atan2l(y, x);
        if(ang < 0) ang += 2*PI;
        return ang;
    }
    T abs2() {return x*x + y*y;} //for integers
    T dist2(Point p) {return (*this-p).abs2(); } //integers too
    Point rot(type g){// g degrees, don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g)); 
    }
    Point rot90(){ 
        return Point(-y, x);
    }
    type cross(Point p){ return x*p.y - y*p.x;}
    type dot(Point p){ return x*p.x + y*p.y;}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll p1, p2, q1, q2, r1, r2, s1, s2;
        cin >> p1 >> p2 >> q1 >> q2 >> r1 >> r2 >> s1 >> s2;
        p1 *= 2, p2 *= 2, q1 *= 2, q2 *= 2, r1 *= 2, r2 *= 2, s1 *= 2, s2 *= 2;
        Point<ll> pt1(p1, p2);
        Point<ll> pt2(q1, q2);
        Point<ll> pt3(r1, r2);
        Point<ll> pt4(s1, s2);
        Point<ll> m1 = pt1 + pt2;
        Point<ll> m2 = pt3 + pt4;
        m1 = m1/2, m2 = m2/2;
        Point<ll> dir1 = pt1 - pt2;
        Point<ll> dir2 = pt3 - pt4;
        dir1 = dir1.rot90(), dir2 = dir2.rot90();

        //if cross product is 0, same dir
        if(dir1.cross(dir2) == 0){
            auto px1 = m2 - m1;
            if(dir1.cross(px1) == 0) cout << "Yes\n";
            else cout << "No\n";
        }else cout << "Yes\n";  
    }
}
