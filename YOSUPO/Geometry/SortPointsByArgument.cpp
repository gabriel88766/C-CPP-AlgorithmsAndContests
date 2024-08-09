#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef long long int type; //if long long int, EPS = 0
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
    //long double arg() { return atan2l(y, x); }

    type dot(Point p){ return x*p.x + y*p.y;}
    type cross(Point p){ return x*p.y - y*p.x;} 
    Point rot90(){ //can handle integers.
        return Point(-y, x);
    }
    bool onSeg(Point a, Point b){ //check if point on seg AB
        type rot = (*this - a).cross(b-a); 
        //rot /= (b-a).abs(); //precision issue, divide rot by (b-a).abs() if double
        if(!eq(rot, 0)) return false;
        return ge(x, min(a.x, b.x)) && le(x, max(a.x, b.x)) && ge(y, min(a.y, b.y)) && le(y, max(a.y, b.y));
    }
    //sort by argument xD
    int checkQuad() const {
        if(x >= 0 && y > 0) return 3; // 1 > >=
        else if(x < 0 && y >= 0) return 4; // 2 <= >
        else if(x <= 0 && y < 0) return 1; // 3 < <=
        else if(x > 0 && y <= 0) return 2; // 4 , >= <
        else{
            assert(false);
            return -1;
        }
    }
    bool operator< (const Point &b) const{
        Point aux = *this;
        int x = aux.checkQuad();
        int y = b.checkQuad();
        if(x != y) return x < y;
        else return aux.cross(b) > 0;
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].x >> v[i].y;
        //case 0 0 
        if(v[i].x == 0 && v[i].y == 0) v[i].x = INF_INT;
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        if(v[i].x == INF_INT) v[i].x = 0;
        cout << v[i].x << " " << v[i].y << "\n";
    
    }
}
