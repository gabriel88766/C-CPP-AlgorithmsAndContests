#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.);
long long  EPS = 0; 
using namespace std;

//looks like type is necessary 600D(codeforces)
typedef long long int type; //if long long int, EPS = 0
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

    type abs() {return x*x+y*y; }
    type dist(Point p){ return (*this-p).abs();}
    //long double arg() { return atan2l(y, x); }

    type dot(Point p){ return x*p.x + y*p.y;}
    type cross(Point p){ return x*p.y - y*p.x;} //if pos, p is in left of vector (x, y), right otherwise
    /*Point rot(type g){// g degrees
        g *= PI/180;
        return Point(x * cosl(g) - y * sinl(g), x * sinl(g) + y * cosl(g)); //double!
    }*/
    Point rot90(){ //can handle integers.
        return Point(-y, x);
    }
    bool onSeg(Point a, Point b){ //check if point on seg AB
        type rot = (*this - a).cross(b-a); 
        //rot /= (b-a).abs(); //precision issue, divide rot by (b-a).abs() if double
        if(!eq(rot, 0)) return false;
        return ge(x, min(a.x, b.x)) && le(x, max(a.x, b.x)) && ge(y, min(a.y, b.y)) && le(y, max(a.y, b.y));
    }
    //for set
    bool operator< (const Point &b) const{
        if(y != b.y) return y < b.y;
        else return x < b.x;
    }
};

//if long long, d1.cross(d2) != 0, Point returned will have integers coordinates. test onSeg.
Point intersectLines(Point a1, Point d1, Point a2, Point d2){ //If Long long, treat d1.cross(d2) == 0
    return a1 + (d1 * ((a2-a1).cross(d2))) / d1.cross(d2); 
}
//ToLine => return x.dist(y);
type distanceToSeg(Point a, Point b, Point x){
    Point y = intersectLines(a, b-a, x, (b-a).rot90());
    if(y.onSeg(a,b)) return x.dist(y);
    else return min(x.dist(a), x.dist(b));
}


ll mysqrt(ll n){
    ll lo = 1, hi = 3e9;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        if(mid*mid <= n) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i=0;i<n;i++) cin >> v[i].x >> v[i].y;
    set<Point> s;
    sort(v.begin(), v.end(), [&](Point &a, Point &b){
        if(a.x != b.x) return a.x < b.x;
        else return a.y < b.y;
    });
    ll mind = 9e18;
    int p = 0;
    for(int i=0;i<n;i++){
        while(v[i].x - v[p].x > mind) s.erase(v[p++]);
        if(!s.empty()){
            ll sqt = mysqrt(mind) + 1;
            auto it = s.lower_bound({-INF_INT, v[i].y - sqt});
            while(it != s.end() && it->y <= v[i].y + sqt){
                Point d = *it;
                mind = min(mind, d.dist(v[i]));
                ++it;
            }
        }
        s.insert(v[i]);
    }
    cout << mind << "\n";
}
