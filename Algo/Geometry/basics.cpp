//features will be added soon.
struct Point{
    double x, y;
    Point(double x, double y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(double d){ return Point(x * d, y * d);}

    double abs() {return sqrt(x*x+y*y); }
    double dist(Point p){ return (*this-p).abs();}

    Point rot(double g){// g degrees
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g));
    }

};