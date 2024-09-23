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

struct inter{
    double l, r, a, y;
    bool operator< (const inter &u) const{
        if(eq(l, u.l)) return r < u.r;
        else return l < u.l;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
        set<inter> cht;
        for(int i=0;i<n;i++){
            double bb = b[i];
            double cc = c[i] / bb;
            double aa = a[i] / bb;
            //y = cc - aa * x
            if(i == 0) cht.insert({0, cc/aa, -aa, cc});
            else{
                auto it = cht.begin();
                auto it2 = prev(cht.end());

                auto doLeft = [&](){
                    while(true){
                        assert(cht.size());
                        auto ix = cht.begin();
                        assert(ge(ix->l * ix->a + ix->y, cc-ix->r*aa));
                        if(ge(ix->r * ix->a + ix->y, cc - ix->r * aa)) cht.erase(cht.begin());
                        else{
                            //find the intersection and fix
                            Point p1 = {0, cc};
                            Point dir1 = {aa, -cc};
                            Point p2 = {0, ix->y};
                            Point dir2 = {-ix->a, -ix->y};
                            Point ins = intersectLines(p1, dir1, p2, dir2);
                            cout << cc << " " << ix->y << "\n";
                                cout << -aa << " " << ix->a << "\n";
                                cout << ins.x << " " << ins.y << "\n";
                            if(ge(ins.x, ix->l) && le(ins.x, ix->r));
                            else{
                                
                                cout.flush();
                            }
                            auto nv = *ix;
                            nv.r = ins.x;
                            cht.erase(ix);
                            cht.insert(nv);
                            cht.insert({0, ins.x, -aa, cc});
                            break;
                        }
                    }
                };
                auto doRight = [&](){
                    while(true){
                        assert(cht.size());
                        auto ix = prev(cht.end());
                        if(ge(ix->l * ix->a + ix->y, cc - ix->r * aa)) cht.erase(ix);
                        else{
                            //find the intersection and fix
                            Point p1 = {0, cc};
                            Point dir1 = {-aa, cc};
                            Point p2 = {0, ix->y};
                            Point dir2 = {ix->a, ix->y};
                            Point ins = intersectLines(p1, dir1, p2, dir2);
                            assert(ge(ins.x, ix->l) && le(ins.x, ix->r));
                            auto nv = *ix;
                            nv.r = ins.x;
                            cht.erase(ix);
                            cht.insert(nv);
                            cht.insert({ins.x, cc/aa, -aa, cc});
                            break;
                        }
                    }
                };

                if(eq(cc, it->y)){
                    if(aa - EPS > abs(it->a)) doLeft();
                }else if(ge(cc, it->y)){
                    if(eq(it2->r, cc/aa)){
                        if(aa + EPS < abs(it2->a)) doRight();
                    }else if(ge(it2->r, cc/aa)){
                        doRight();
                    }else{
                        //doMid
                        double l = 0, r = cc/aa;
                        while(r  > l + EPS){
                            double x = (r-l)/3;
                            double m1 = l + x;
                            double m2 = l + 2*x;
                            auto it = prev(cht.lower_bound({m1,1e18,1e18,1e18}));
                            auto it2 = prev(cht.lower_bound({m2,1e18,1e18,1e18}));
                            double r1 = -aa * m1 + cc;
                            double r2 = -aa * m2 + cc;
                            double v1 = it->a * m1 + it->y - r1;
                            double v2 = it2->a * m2 + it2->y - r2;
                            if(v1 > v2) r = m2;
                            else l = m1;
                        }
                        auto it = prev(cht.lower_bound({l,1e18,1e18,1e18}));
                        double vl = it->a * l + it->y + aa * l - cc;
                        if(vl > 0){
                            //then intersect, lol
                            cout << "not supported" << endl;
                        }
                    }
                }else if(le(cc, it->y)){
                    if(ge(it2->r, cc/aa)){
                        cht.clear();
                        cht.insert({0, cc/aa, -aa, cc});
                    }else{
                        //has intersection, remove all left
                        doLeft();
                    }
                }else{
                    assert(1 == 0);
                }
            }

        }

    }
}
