//Trying to make a template really strong 
//covering "all" cases
// const double PI = acos(-1.);
//T must be double / long double here
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
    Point rot_dg(float_type g){// g degrees, don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g)); 
    }
    Point rot(float_type rad){// rad is [0, 2pi], don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)); 
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

//not sure yet if works good with doubles
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

//untested minkowski sum (only for integers, but can be expanded)
auto find_quadrant = [](const Point<ll> &p) {
    if(p.x > 0 && p.y >= 0) return 0; //[0, 90)
    else if(p.x <= 0 && p.y > 0) return 1;//[90, 180)
    else if(p.x < 0 && p.y <= 0) return 2;//[180, 270]
    else return 3;//[270, 360)
};

auto compare = [](Point<ll> &p1, Point<ll> &p2){
    int q1 = find_quadrant(p1), q2 = find_quadrant(p2);
    if(q1 != q2) return q1 < q2;
    else return p1.cross(p2) > 0;
};


void reorder(vector<Point<ll>> &vp){
    int pbeg = 0;
    for(int i=1;i<vp.size();i++){
        if(vp[i].y < vp[pbeg].y){
            pbeg = i;
        }else if(vp[i].y == vp[pbeg].y && vp[i].x < vp[pbeg].y){
            pbeg = i;
        }
    }
    if(pbeg != 0) rotate(vp.begin(), vp.begin() + pbeg, vp.end());
}

vector<Point<ll>> minkowski(vector<Point<ll>> &a, vector<Point<ll>> &b){
    int n = a.size();
    int m = b.size();
    reorder(a);
    reorder(b);
    a.push_back(a[0]);
    a.push_back(a[1]);
    b.push_back(b[0]);
    b.push_back(b[1]);
    int pa = 0, pb = 0;
    vector<Point<ll>> ans;
    while(pa < n || pb < m){
        ans.push_back(a[pa] + b[pb]);
        Point<ll> d1 = a[pa+1] - a[pa];
        Point<ll> d2 = a[pb+1] - a[pb];
        if((!compare(d1, d2)) && pa < n) pa++;//d1 >= d2
        if((!compare(d2, d1)) && pb < m) pb++;
    }
    return ans;
}