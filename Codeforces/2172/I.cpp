#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef double float_type; //floating point type

template<typename T>
bool ge(T a, T b){
    if(std::is_floating_point<T>::value){
        return a + EPS >= b;
    }else{
        return a >= b;
    }
    
}
template<typename T>
bool le(T a, T b){
    if(std::is_floating_point<T>::value){
        return a - EPS <= b;
    }else{
        return a <= b;
    }
}

template<typename T>
bool eq(T a, T b){
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
    float_type abs() {return sqrt(x*x+y*y); } //remove sqrt and use long long for more precision 
    float_type dist(Point p){ return (*this-p).abs();} //long long too
    // returns arg ∈ [0, 2π)
    float_type arg() { 
        float_type ang = atan2l(y, x);
        if(ang < 0) ang += 2*PI;
        return ang;
    }
    T abs2() {return x*x + y*y;} //for integers
    T dist2(Point p) {return (*this-p).abs2(); } //integers too
    Point rot(float_type g){// g degrees, don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g)); 
    }
    Point rot90(){ 
        return Point(-y, x);
    }
    T cross(Point p){ return x*p.y - y*p.x;}
    T dot(Point p){ return x*p.x + y*p.y;}
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
    T zr = 0;
    float_type rot = (c - a).cross(b - a); 
    rot /= (b-a).abs(); //precision issue
    if(!eq(rot, zr)) return false;
    return ge(c.x, min(a.x, b.x)) && le(c.x, max(a.x, b.x)) && ge(c.y, min(a.y, b.y)) && le(c.y, max(a.y, b.y));
}

template<typename T>
vector<Point<T>> convex_hull(vector<Point<T>> &p){ //at least 2 points
    T zr = 0; //double or long long
    Point<T> pvt = {(T)INF_LL, (T)INF_LL};
    for(int i=0;i<p.size();i++){
        if(p[i].x < pvt.x){
            pvt = p[i];
            swap(p[i], p[0]);
        }else if(p[i].x == pvt.x && p[i].y < pvt.y){
            pvt = p[i];
            swap(p[i], p[0]);
        }
    }
    assert(pvt == p[0]);
    sort(p.begin()+1, p.end(), [&](Point<T> &u, Point<T> &v){
        Point<T> a1 = u - p[0];
        Point<T> a2 = v - p[0];
        if(eq(a1.cross(a2), zr)){
            return a1.abs() < a2.abs();
        }else return a1.cross(a2) > 0;
    });
    vector<Point<T>> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    for(int i=2;i<p.size();i++){
        while(hull.size() >= 2){
            int sz = hull.size();
            Point<T> dir1 = hull[sz-1] - hull[sz-2];
            Point<T> dir2 = p[i] - hull[sz-1];
            if(le(dir1.cross(dir2), zr)) hull.pop_back();
            else break;
        }
        hull.push_back(p[i]);
    }
    //this convex hull is working, but it doesn't contain some colinear points.
    //to fix it, change < to <= and add points colinear to hull[0] and hull.back() manually (O(n))
    return hull;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    double r;
    cin >> n >> r;
    vector<Point<ll>> px(n);
    for(int i=0;i<n;i++){
        cin >> px[i].x >> px[i].y;
    }
    double mang = 0;
    if(n <= 2){
        mang = PI;
        cout << fixed << setprecision(10) << (r * r * mang - r * r * sin(mang))/2 << "\n";
        return 0;
    }
    vector<double> args;
    for(int j=0;j < n; j++) args.push_back(px[j].arg());
    sort(args.begin(), args.end());
    for(int j=1;j < n; j++){
        if(ge(args[j] - args[j-1], PI)) mang = PI;
    }
    if(ge(2*PI - args[n-1] + args[0], PI)) mang = PI;


    auto hullx = convex_hull(px);
    vector<Point<double>> hull(hullx.size());
    for(int i=0;i<hull.size();i++){
        hull[i].x = hullx[i].x;
        hull[i].y = hullx[i].y;
    }
    for(int i=0;i<hull.size();i++){
        auto p1 = hull[i];
        auto p2 = hull[(i+1) % hull.size()];
        Line line =  Line<double>::from_Points(p1, p2);
        Circle cir(Point<double>(0, 0), r);
        auto vx = cir.intersectLine(line);
        assert(vx.size() == 2);
        double ang = 2 * asin(vx[0].dist(vx[1])/(2*r));
        mang = max(mang, ang);
    }
    cout << fixed << setprecision(10) << (r * r * mang - r * r * sin(mang))/2 << "\n";
}
