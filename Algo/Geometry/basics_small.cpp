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