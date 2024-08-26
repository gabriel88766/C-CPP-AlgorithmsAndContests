#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef double type; //if long long int, EPS = 0
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
    Point rot(type g){// g degrees
        g *= PI/180;
        return Point(x * cosl(g) - y * sinl(g), x * sinl(g) + y * cosl(g)); //double!
    }
    Point rot90(){ //can handle integers.
        return Point(-y, x);
    }
    bool onSeg(Point a, Point b){ //check if point on seg AB
        type rot = (*this - a).cross(b-a); 
        //rot /= (b-a).abs(); //precision issue, divide rot by (b-a).abs() if double
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
    ll sy, a, b;
    cin >> sy >> a >> b;
    int n, m;
    cin >> n;
    vector<tuple<int, int, int>> vsg(n);
    vector<ll> ps(n);
    for(int i=0;i<n;i++){
        int l, r;
        cin >> l >> r;
        vsg[i] = {l, r, i};
        if(i != 0){
            auto [ol, orr, oi] = vsg[i-1];
            ps[i] = ps[i-1];
            ps[i] += l - orr;
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        ll x, y;
        cin >> x >> y;

        Point p(a-x, sy - y);
        double d = abs(y);
        d /= abs(y - sy);
        p = p* d;
        p = p+ Point(x, y);

        Point p2(b-x, sy - y);
        d = abs(y);
        d /= abs(y - sy);
        p2 = p2 * d;
        p2 = p2 + Point(x, y);


        double ans = 0;
        tuple<int,int,int> taux = {p.x+1, 0, 0};
        auto it = lower_bound(vsg.begin(), vsg.end(), taux);
        if(it != vsg.begin()) --it;
        if(le(get<1>(*it), p.x)) ++it;
        if(it == vsg.end() || le(p2.x, get<0>(*it))){
            cout << setprecision(10) << 0 << "\n";
            continue;
        }
        if(p.x < get<0>(*it)){
            ans += get<0>(*it) - p.x;
        }
        taux = {p2.x+1, 0, 0};
        auto it2 = lower_bound(vsg.begin(), vsg.end(), taux);
        --it2;
        if(p2.x > get<1>(*it2)){
            ans += p2.x - get<1>(*it2);
        }
        ans += ps[get<2>(*it2)] - ps[get<2>(*it)];
        ans /= (p2.x - p.x);
        ans *= (b-a);
        ans = (b-a)-ans;





        cout << fixed << setprecision(10) << ans << "\n";
    }
}
