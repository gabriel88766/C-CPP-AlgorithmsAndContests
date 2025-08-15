//Trying to make a template really strong 
//covering "all" cases
// const double PI = acos(-1.);
//T must be double / long double here
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