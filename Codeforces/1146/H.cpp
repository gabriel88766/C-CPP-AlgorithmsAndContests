#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


typedef double type;
bool ge(type a, type b){
    return a + EPS >= b;
}
bool le(type a, type b){
    return a - EPS <= b;
}
bool eq(type a, type b){
    return ge(a,b) && le(a,b);
}

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
    //Fraction or double:
    Point<T> intersectLines(Line<T> xl){
        T den = xl.a * b - a * xl.b;
        T nx = c * xl.b - xl.c * b;
        T ny = xl.c * a - c * xl.a;
        //please!! use only if den != 0
        return Point<T>(nx/den, ny/den);
    }
    bool onLine(Point<T> p){
        T val = p.x*a + p.y*b + c;
        return eq(0, val);
    }
};


template<typename T>
bool onSeg(Point<T> a, Point<T> b, Point<T> c){ //check if point on seg AB
    type rot = (c - a).cross(b - a); 
    rot /= (b-a).abs(); //precision issue
    if(!eq(rot, 0)) return false;
    return ge(c.x, min(a.x, b.x)) && le(c.x, max(a.x, b.x)) && ge(c.y, min(a.y, b.y)) && le(c.y, max(a.y, b.y));
}

const int N = 305;
int rg[N][N];
int lf[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            //check if point is left or right
            for(int k=0;k<n;k++){
                if(i == k || j == k) continue;
                if(onSeg(Point<double>(vp[i].first, vp[i].second), Point<double>(vp[j].first, vp[j].second), Point<double>(vp[k].first, vp[k].second))) continue;
                Line<double> ln(Point<double>(vp[k].first, vp[k].second), Point<double>(vp[i].first - vp[j].first, vp[i].second - vp[j].second).rot90());
                Line<double> l2(Point<double>(vp[i].first, vp[i].second), Point<double>(vp[i].first - vp[j].first, vp[i].second - vp[j].second));
                auto inter = ln.intersectLines(l2);
                if(onSeg(Point<double>(vp[i].first, vp[i].second), Point<double>(vp[j].first, vp[j].second), inter)){
                    //check if left or right
                    Point<ll> p1(vp[j].first - vp[i].first, vp[j].second - vp[i].second);
                    Point<ll> p2(vp[k].first - vp[i].first, vp[k].second - vp[i].second);
                    if(p1.cross(p2) > 0) lf[i][j]++;
                    else rg[i][j]++;
                }
            }
        }
    }
    ll ans = 0;
    map<vector<int>, int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            for(int k=0;k<n;k++){
                if(k == i || k == j) continue;
                Point<ll> p1(vp[i].first, vp[i].second);
                Point<ll> p2(vp[j].first, vp[j].second);
                Point<ll> p3(vp[k].first, vp[k].second);
                if((p2-p1).cross(p3-p2) <= 0) continue;
                vector<int> oki;
                for(int l=0;l<n;l++){
                    if(l == k || l == i || l == j) continue;
                    
                    Point<ll> p4(vp[l].first, vp[l].second);
                    if((p2-p1).cross(p4-p1) > 0 && (p3-p2).cross(p4-p2) > 0){
                        oki.push_back(l);
                    }
                }
                for(auto u : oki){
                    for(auto v : oki){
                        if(u == v) continue;
                        Point<ll> p4(vp[u].first, vp[u].second);
                        Point<ll> p5(vp[v].first, vp[v].second);
                        if((p5-p4).cross(p1-p5) > 0 && (p4-p3).cross(p5-p4) > 0){
                            ans++;
                            // cout << i << " " << j << " " << k << " " << u << " " << v << "\n";
                            vector<int> vx = {i, j, k, u, v};
                            sort(vx.begin(), vx.end());
                            vector<int> ux = {0, 1, 2, 3, 8};
                            if(vx == ux){
                                cout << i <<  " " << j << " " << k << " " << u << " " << v << "\n";
                            }
                            mp[vx]++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n"; //just debug.
    ans /= 5;
    cout << ans << "\n";
    cout << mp.size() << "\n";
    for(auto [k, v] : mp){
        for(auto u : k){
            cout << u << " ";
        }
        cout << " = " << v << "\n";
        // cout << "\n";
    }
}
