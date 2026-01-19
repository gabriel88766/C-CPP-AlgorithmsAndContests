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
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(T d){ return Point(x * d, y * d);}
    Point operator /(T d){ return Point(x/d, y/d);} //integer division, maybe not what you want.
    bool operator ==(Point p){
        return x == p.x && y == p.y;
    }
    T abs2() {return x*x + y*y;} //for integers
    T dist2(Point p) {return (*this-p).abs2(); } //integers too
    Point rot90(){ 
        return Point(-y, x);
    }
    T cross(Point p){ return x*p.y - y*p.x;}
    T dot(Point p){ return x*p.x + y*p.y;}
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Point<ll>> vp;
    for(int i=0;i<n;i++){
        Point<ll> p;
        cin >> p.x >> p.y;
        if(p.x != 0 || p.y != 0) vp.push_back(p);
    }
    n = vp.size();
    auto find_quadrant = [](const Point<ll> &p) {
        if(p.x > 0 && p.y >= 0) return 0; //[0, 90)
        else if(p.x <= 0 && p.y > 0) return 1;//[90, 180)
        else if(p.x < 0 && p.y <= 0) return 2;//[180, 270]
        else return 3;//[270, 360)
    };

    sort(vp.begin(), vp.end(), [&](Point<ll> &p1, Point<ll> &p2){
        int q1 = find_quadrant(p1), q2 = find_quadrant(p2);
        if(q1 != q2) return q1 < q2;
        else return p1.cross(p2) > 0;
    });
    ll md = 0;
    for(int i=0;i<n;i++){
        //starts at 0 and just go
        Point<ll> cp = {0, 0};
        for(int j=i;j<n;j++){
            cp = cp + vp[j];
            md = max(md, cp.abs2());
        }
        for(int j=0;j<i;j++){
            cp = cp + vp[j];
            md = max(md, cp.abs2());
        }
    }
    cout << setprecision(20) << fixed << sqrtl(md) << "\n";
}
