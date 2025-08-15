#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


typedef double type;
bool ge(type a, type b){
    return a + EPS >= b;
}
bool le(type a, type b){
    return a - EPS <= b;
}
bool eq(type a, type b){
    return ge(a,b) && le(a,b);
}

template<typename T>
struct Point{
    T x, y;
    Point(){}
    Point(T x, T y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(T d){ return Point(x * d, y * d);}
    Point operator /(T d){ return Point(x/d, y/d);} //integer division, maybe not what you want.
    bool operator ==(Point p){
        if(std::is_floating_point<T>::value){
            return eq(x, p.x) && eq(y, p.y);
        }else{
            return x == p.x && y == p.y;
        }
    }
    double abs() {return sqrt(x*x+y*y); } //remove sqrt and use long long for more precision 
    double dist(Point p){ return (*this-p).abs();} //long long too
    // returns arg ∈ [0, 2π)
    double arg() { 
        double ang = atan2l(y, x);
        if(ang < 0) ang += 2*PI;
        return ang;
    }
    T abs2() {return x*x + y*y;} //for integers
    T dist2(Point p) {return (*this-p).abs2(); } //integers too
    Point rot(type g){// g degrees, don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g)); 
    }
    Point rot90(){ 
        return Point(-y, x);
    }
    type cross(Point p){ return x*p.y - y*p.x;}
    type dot(Point p){ return x*p.x + y*p.y;}
};

template<typename T>
struct Line{
    T a, b, c;
    Line(T a, T b, T c){
        this->a = a, this->b = b, this->c = c;
    }
    //from P + Qt
    Line(Point<T> p, Point<T> q){
        a = -q.y;
        b = q.x;
        c = q.y * p.x - q.x * p.y;
    } 
    //from 2 points.
    //example usage: Line<double> l1 = Line<double>::from_Points(Point<double>(1, 5), Point<double>(6, 8));
    static Line from_Points(Point<T> p, Point<T> q){
        return Line(p, q-p);
    }
    //Fraction or double:
    Point<T> intersectLines(Line<T> xl){
        T den = xl.a * b - a * xl.b;
        T nx = c * xl.b - xl.c * b;
        T ny = xl.c * a - c * xl.a;
        //please!! use only if den != 0
        return Point<T>(nx/den, ny/den);
    }
    bool onLine(Point<T> p){
        T val = p.x*a + p.y*b + c;
        return eq(0, val);
    }
};

template<typename T>
struct Circle{
    T R; //radius
    Point<T> C; //center
    Circle(Point<T> C, T R){
        static_assert(std::is_floating_point<T>::value);
        this->C = C;
        this->R = R;
    }
    //Let's make the line intersect the Circle (maybe won't)
    vector<Point<T>> intersectLine(Line<T> l){
        //vector because there is 0 1 or 2 points
        Point<T> dir(l.a, l.b); //  perpendicular
        Point<T> inter = l.intersectLines(Line(C, dir));
        vector<Point<T>> ans;
        T d = inter.dist(C);
        if(eq(d, R)){
            //1 point
            ans.push_back(inter);
        }else if(le(d, R)){
            //2 points
            Point<T> rt = dir.rot90();
            rt = rt / rt.abs(); 
            T pc = sqrtl(R * R - d*d); //T is double or long double?? hell!!!
            ans.push_back(inter + rt*pc);
            ans.push_back(inter - rt*pc);
        }
        return ans;
    }
    vector<Point<T>> intersectCircle(Circle<T> cx){
        Line lx(2*(cx.C.x - C.x), 2*(cx.C.y - C.y), -R*R + cx.R*cx.R - cx.C.abs2() + C.abs2());
        auto inter = intersectLine(lx);
        return inter;
    }
    bool operator== (Circle c){
        return eq(c.R, R) && c.C == C;
    }
};

template<typename T>
bool onSeg(Point<T> a, Point<T> b, Point<T> c){ //check if point on seg AB
    type rot = (c - a).cross(b - a); 
    rot /= (b-a).abs(); //precision issue
    if(!eq(rot, 0)) return false;
    return ge(c.x, min(a.x, b.x)) && le(c.x, max(a.x, b.x)) && ge(c.y, min(a.y, b.y)) && le(c.y, max(a.y, b.y));
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n, d;
    cin >> n >> d;
    vector<tuple<int, int, int>> vt(n);
    vector<vector<int>> tog(3001);
    for(int i=0;i<n;i++){
        int x, y, r;
        cin >> x >> y >> r;
        vt[i] = {x, y, r};
        double dst = sqrt(x*x + y*y);
        int fc = (dst) / d;
        int lc = fc;
        fc = max(1, fc - 13);
        lc = lc + 13;
        // cout << lc << endl;
        assert(lc + 1 <= 3000);
        tog[fc].push_back(i);
        tog[lc+1].push_back(i);
    }
    set<int> chk;
    multiset<double> add, rem;
    for(int i=1;i<=3000;i++){
        for(auto x : tog[i]){
            if(chk.count(x)) chk.erase(x);
            else chk.insert(x);
        }
        Circle<double> cur(Point<double>(0, 0), d*i);
        for(auto xx : chk){
            auto [x, y, r] = vt[xx];
            Circle<double> cx(Point<double>(x, y), r);
            auto inter = cur.intersectCircle(cx);
            if(inter.size() == 1){
                double arg = inter[0].arg();
                add.insert(arg);
                rem.insert(arg);
            }else if(inter.size() == 2){
                double a1 = inter[0].arg();
                double a2 = inter[1].arg();
                //intersection is less than PI;
                if(a1 > a2) swap(a1, a2);
                if(a2 - a1 < PI){
                    add.insert(a1);
                    rem.insert(a2);
                }else{
                    add.insert(0);
                    rem.insert(a1);
                    add.insert(a2);
                }
            }
        }
    }
    int ans = 0, cur = 0;
    auto it1 = add.begin();
    auto it2 = rem.begin();
    while(it1 != add.end() || it2 != rem.end()){
        if(it1 != add.end() && it2 != rem.end()){
            if(le(*it1, *it2)){
                cur++;
                it1++;
            }else{
                cur--;
                it2++;
            }
        }else if(it1 != add.end()){
            cur++;
            it1++;
        }else{
            cur--;
            it2++;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";

}
