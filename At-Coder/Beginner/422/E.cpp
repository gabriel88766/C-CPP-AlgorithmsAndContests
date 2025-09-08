#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


template<typename T>
struct Point{
    T x, y;
    Point(){}
    Point(T x, T y) { this->x = x; this->y = y;}
    Point(pair<T, T> p){this->x = p.first; this->y = p.second;}
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
    Point rot(T g){// g degrees, don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g)); 
    }
    Point rot90(){ 
        return Point(-y, x);
    }
    T cross(Point p){ return x*p.y - y*p.x;}
    T dot(Point p){ return x*p.x + y*p.y;}
};

template<typename T>
struct Line{
    T a, b, c;
    Line(T a, T b, T c){
        this->a = a, this->b = b, this->c = c;
    }
    //from P + Qt
    Line(Point<T> p, Point<T> q){
        a = -q.y;
        b = q.x;
        c = q.y * p.x - q.x * p.y;
    } 
    //from 2 points.
    //example usage: Line<double> l1 = Line<double>::from_Points(Point<double>(1, 5), Point<double>(6, 8));
    static Line from_Points(Point<T> p, Point<T> q){
        return Line(p, q-p);
    }
    bool onLine(Point<T> p){
        T val = p.x*a + p.y*b + c;
        return val == 0;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int mn = (n+1)/2;
    vector<pair<ll, ll>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first >> vp[i].second;
    //choose 2 points, they are in the same line with ~ 25% chance
    //go random brrr, 100 times then 0.75^100 not choosing two points
    Line<ll> ln(0, 0, 0);
    bool ok = false;
    for(int i=0;i<100;i++){
        int p1 = uniform_int_distribution<int>(0, n-1)(rng);
        int p2 = uniform_int_distribution<int>(0, n-1)(rng);
        while(p1 == p2) p2 = uniform_int_distribution<int>(0, n-1)(rng);
        //colinear implies cross product is 0
        int cnt = 2;
        Point a(vp[p1]);
        Point b(vp[p2]);
        ln = Line<ll>::from_Points(a, b);
        for(int j=0;j<n;j++){
            if(j == p1 || j == p2) continue;
            Point c(vp[j]);
            if(ln.onLine(c)) cnt++;
        }
        if(cnt >= mn){
            ok = true;
            break;
        }
    }
    if(ok){
        cout << "Yes\n";
        cout << ln.a << " " << ln.b << " " << ln.c << "\n";

    }else cout << "No\n";
    
}
