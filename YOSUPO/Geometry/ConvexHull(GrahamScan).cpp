#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.);
using namespace std;
 
typedef long long int type; //if long long int, EPS = 0
const type EPS = 0;
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
 
    long double abs() {return sqrtl(x*x+y*y); }
    long double dist(Point p){ return (*this-p).abs();}
    long double arg() { return atan2l(y, x); }
 
    type dot(Point p){ return x*p.x + y*p.y;}
    type cross(Point p){ return x*p.y - y*p.x;} //if pos, p is in left of vector (x, y), right otherwise
    Point rot90(){ //can handle intergers.
        return Point(-y, x);
    }
    bool operator== (Point p){
        return x == p.x && y == p.y;
    }
};
 
vector<Point> convex_hull(vector<Point> &p){ //at least 2 points
    Point pvt = {INF_LL, INF_LL};
    for(int i=0;i<p.size();i++){
        if(p[i].x < pvt.x){
            pvt = p[i];
            swap(p[i], p[0]);
        }else if(p[i].x == pvt.x && p[i].y < pvt.y){
            pvt = p[i];
            swap(p[i], p[0]);
        }
    }
    assert(pvt == p[0]);
    sort(p.begin()+1, p.end(), [&](Point &u, Point &v){
        Point a1 = u - p[0];
        Point a2 = v - p[0];
        if(a1.cross(a2) == 0){
            return a1.abs() < a2.abs();
        }else return a1.cross(a2) > 0;
    });
    vector<Point> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    for(int i=2;i<p.size();i++){
        while(hull.size() >= 2){
            int sz = hull.size();
            Point dir1 = hull[sz-1] - hull[sz-2];
            Point dir2 = p[i] - hull[sz-1];
            if(dir1.cross(dir2) <= 0) hull.pop_back();
            else break;
        }
        hull.push_back(p[i]);
    }
    //this convex hull is working, but it doesn't contain some colinear points.
    //to fix it, change < to <= and add points colinear to hull[0] and hull.back() manually (O(n))
    return hull;
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        vector<Point> v, convex;
        int n;
        cin >> n;
        map<pair<int,int>, int> mp;
        for(int i=0;i<n;i++){
            type a, b;
            cin >> a >> b;
            if(!mp.count({a, b})) v.push_back(Point(a, b));
            mp[{a, b}]++;
        }
        if(v.size() <= 2){
            cout << v.size() << "\n";
            for(auto [x, y] : v) cout << x << " " << y << "\n";
            continue;
        }
        convex = convex_hull(v);
        cout << convex.size() << "\n";
        for(int i=0;i<convex.size();i++){
            cout << convex[i].x << " " << convex[i].y << "\n"; 
        }  
    }
}