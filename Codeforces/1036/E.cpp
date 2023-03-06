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

    type abs() {return sqrtl(x*x+y*y); }
    type dist(Point p){ return (*this-p).abs();}
    type arg() { return atan2l(y, x); }

    type dot(Point p){ return x*p.x + y*p.y;}
    type cross(Point p){ return x*p.y - y*p.x;} //if pos, p is in left of vector (x, y), right otherwise
    Point rot(type g){// g degrees
        g *= PI/180;
        return Point(x * cosl(g) - y * sinl(g), x * sinl(g) + y * cosl(g));
    }
    bool onSeg(Point a, Point b){ //check if point on seg AB
        type rot = (*this - a).cross(b-a);
        if(!eq(rot, 0)) return false;
        return ge(x, min(a.x, b.x)) && le(x, max(a.x, b.x)) && ge(y, min(a.y, b.y)) && le(y, max(a.y, b.y));
    }
};

Point intersectLines(Point a1, Point d1, Point a2, Point d2){ //If Long long, treat d1.cross(d2) == 0
    if(d1.cross(d2) != 0) return a1 + (d1 * ((a2-a1).cross(d2))) / d1.cross(d2); 
    else return Point(INF_LL,INF_LL);
}

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
    int n;
    cin >> n;
    vector<pair<int,int>> A(n), B(n);
    for(int i=0;i<n;i++){
        cin >> A[i].first >> A[i].second >> B[i].first >> B[i].second; 
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        int dif1 = abs(B[i].first - A[i].first);
        int dif2 = abs(B[i].second - A[i].second);
        ans += __gcd(dif1, dif2) + 1;
    }
    map<pair<ll,ll>, int> mp;
    set<pair<ll,ll>> inter;
    map<ll,ll> subt;
    for(ll i=1;i<=1000;i++){
        subt[(i*(i+1))/2] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=(i+1);j<n;j++){
            //find inter integers, insert in set, update mp
            Point p1((type)A[i].first, (type)A[i].second);
            Point p2((type)B[i].first, (type)B[i].second);
            Point p3((type)A[j].first, (type)A[j].second);
            Point p4((type)B[j].first, (type)B[j].second);
            Point p5 = intersectLines(p1, p2-p1, p3, p4-p3);
            if(!p5.onSeg(p1,p2) || !p5.onSeg(p3,p4)) continue;

            inter.insert({p5.x,p5.y});
            mp[{p5.x,p5.y}]++;
        }
    }
    for(auto x : inter){
        ans -= subt[mp[x]];
    }
 
    cout << ans;
}