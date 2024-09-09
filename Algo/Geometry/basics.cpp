//looks like type is necessary 600D(codeforces)
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
//ToLine => return x.dist(y);
type distanceToSeg(Point a, Point b, Point x){
    Point y = intersectLines(a, b-a, x, (b-a).rot(90));
    if(y.onSeg(a,b)) return x.dist(y);
    else return min(x.dist(a), x.dist(b));
}

vector<Point> convex_hull(vector<Point> &p){ //at least 2 points
    Point pvt = {INF_LL, INF_LL};
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
    sort(p.begin()+1, p.end(), [&](Point &u, Point &v){
        Point a1 = u - p[0];
        Point a2 = v - p[0];
        if(a1.cross(a2) == 0){
            return a1.abs() < a2.abs();
        }else return a1.cross(a2) > 0;
    });
    vector<Point> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    for(int i=2;i<p.size();i++){
        while(hull.size() >= 2){
            int sz = hull.size();
            Point dir1 = hull[sz-1] - hull[sz-2];
            Point dir2 = p[i] - hull[sz-1];
            if(dir1.cross(dir2) <= 0) hull.pop_back();
            else break;
        }
        hull.push_back(p[i]);
    }
    //this convex hull is working, but it doesn't contain some colinear points.
    //to fix it, change < to <= and add points colinear to hull[0] and hull.back() manually (O(n))
    return hull;
}
