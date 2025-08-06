//use Point with long long and make EPS = 0;
//T must be double / long double here
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