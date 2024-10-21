#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef long long type; //if long long int, EPS = 0
bool ge(type a, type b){
    return a >= b;
}
bool le(type a, type b){
    return a <= b;
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

    type abs() {return x*x+y*y; }
    type dist(Point p){ return (*this-p).abs();}
    type dot(Point p){ return x*p.x + y*p.y;}
    type cross(Point p){ return x*p.y - y*p.x;} //if pos, p is in left of vector (x, y), right otherwise

    Point rot90(){ //can handle integers.
        return Point(-y, x);
    }
    bool onSeg(Point a, Point b){ //check if point on seg AB
        type rot = (*this - a).cross(b-a); 
        //rot /= (b-a).abs(); //precision issue, divide rot by (b-a).abs() if double
        if(!eq(rot, 0)) return false;
        return ge(x, min(a.x, b.x)) && le(x, max(a.x, b.x)) && ge(y, min(a.y, b.y)) && le(y, max(a.y, b.y));
    }
    bool onLine(Point a, Point b){ //check if point on seg AB
        type rot = (*this - a).cross(b-a); 
        //rot /= (b-a).abs(); //precision issue, divide rot by (b-a).abs() if double
        return eq(rot, 0);
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    freopen("in.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector<Point> vp(n+1);
        for(int j=1;j<=n;j++){
            int a, b;
            cin >> a >> b;
            vp[j] = {a, b};
        }
        int minv = INF_INT;
        for(int j=0;j<=200;j++){
            //if there is a line with at least n/2 points, then ~(0.75)^j is the probability of never
            //chose 2 of them
            int p1 = uniform_int_distribution<int>(1, n)(rng);
            int p2 = p1;
            while(p1 == p2) p2 = uniform_int_distribution<int>(1, n)(rng);
            int cur = 0;
            for(int k=1;k<=n;k++){
                if(!vp[k].onLine(vp[p1], vp[p2])) cur++;
            }
            minv = min(cur, minv);
        }

        cout << "Case #" << i << ": " << minv << "\n";

    }
}
