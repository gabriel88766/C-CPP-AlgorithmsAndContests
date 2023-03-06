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
        return this->cross(p) == 0;
    }
    bool operator< (Point p){
        if(x != p.x) return x < p.x;
        else return y < p.y;
    }
};

vector<Point> convex_hull(vector<Point> &p){
    sort(p.begin(), p.end());
    vector<Point> up, down;
    up.emplace_back(p[0]); up.emplace_back(p[1]);
    Point dir(p[1] - p[0]);
    for(int i=2;i<p.size();i++){
        Point dir2 = p[i] - up.back();
        if(dir.cross(dir2) > 0){
            up.pop_back();
            dir2 = p[i] - up.back();
            up.emplace_back(p[i]);
        }else up.emplace_back(p[i]);
        dir = dir2;
    }
    return up;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<Point> v, convex;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        type a, b;
        cin >> a >> b;
        v.push_back(Point(a, b));
    }
    convex = convex_hull(v);
    cout << convex.size() << "\n";
    for(int i=0;i<convex.size();i++){
        cout << convex[i].x << " " << convex[i].y << "\n"; 
    }  
}
