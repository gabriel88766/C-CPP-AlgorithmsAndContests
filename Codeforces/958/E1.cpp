#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef long double type; //if long long int, EPS = 0
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
    int r, b;
    cin >> r >> b;
    vector<Point> vp1(r), vp2(b);
    for(int i=0;i<r;i++) cin >> vp1[i].x >> vp1[i].y;
    for(int i=0;i<b;i++) cin >> vp2[i].x >> vp2[i].y;
    vector<int> perm;
    for(int i=0;i<b;i++) perm.push_back(i);
    if(r == b){
        bool ok = false;
        do{
            //assign vp1[i] -> vp2[perm[i]]
            bool cok = true;
            for(int i=0;i<r;i++){
                for(int j=i+1;j<r;j++){
                    //line i intersect line j ?
                    int x = perm[i], y = perm[j];
                    Point d1 = vp2[x] - vp1[i];
                    Point d2 = vp2[y] - vp1[j];
                    if(eq(d1.cross(d2), 0.0)) continue;
                    auto p = intersectLines(vp1[i], d1, vp1[j], d2);
                    if(p.onSeg(vp1[i], vp2[x]) && p.onSeg(vp1[j], vp2[y])){
                        cok = false;
                    }
                }
            }

            if(cok){
                ok = true;
                break;
            }
        }while(next_permutation(perm.begin(), perm.end()));
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }else cout << "No\n";
}
 