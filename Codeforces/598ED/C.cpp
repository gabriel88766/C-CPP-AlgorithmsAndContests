#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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

int checkQ(const Point &p){
    if(p.x == 0){
        if(p.y > 0) return 2;
        else return 4;
    }else if(p.y == 0){
        if(p.x > 0) return 1;
        else return 3;
    }else{
        if(p.x > 0 && p.y > 0) return 1;
        else if(p.x < 0 && p.y > 0) return 2;
        else if(p.x < 0 && p.y < 0) return 3;
        else if(p.x > 0 && p.y < 0) return 4;
        else{
            assert(1 == 0);
            return 0;
        }
    }
}


bool comp(pair<Point, int> &u, pair<Point, int> &v){
    auto p1 = u.first;
    auto p2 = v.first;
    int q1 = checkQ(p1);
    int q2 = checkQ(p2);
    //cout << q1 << " " << q2 << "\n";
    if(q1 != q2) return q1 < q2;
    if(p1.cross(p2) > 0) return true;
    else return false;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<Point,int>> v(n);
    for(int i=0;i<n;i++){
         cin >> v[i].first.x >> v[i].first.y;
         v[i].second = i+1;
    }
    if(n == 2){
        cout << "1 2\n";
        return 0;
    }//else, there is an angle less than 180

    sort(v.begin(), v.end(), comp);
    pair<int,int> ans = {0,0};
    long double ang = 1e12;
    //do double
    for(int i=0;i<n;i++){
        auto p1 = v[i].first;
        auto p2 = v[(i+1) % n].first;
        
        auto dt = p1.dot(p2);
        auto crs = p1.cross(p2);
        if(crs <= 0) continue; // >= 180 dg
        long double a = atan2l(crs, dt);
        if(a < ang){
            ang = a;
            ans = {v[i].second, v[(i+1) %n].second};
        }
    }
    cout << ans.first << " " << ans.second << "\n";
    

}
