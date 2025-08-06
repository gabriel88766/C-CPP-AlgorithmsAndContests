#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

typedef double type;
const double PI = acos(-1.);
typedef double type;
struct Point{
    type x, y;
    Point(){}
    Point(type x, type y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(type d){ return Point(x * d, y * d);}
    Point operator /(type d){ return Point(x/d, y/d);}

    double abs() {return sqrt(x*x+y*y); }
    double dist(Point p){ return (*this-p).abs();}
    double arg() { return atan2l(y, x); }
    Point rot(type g){// g graus
        assert(std::is_floating_point<type>::value);
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g)); 
    }
    Point rot90(){ 
        return Point(-y, x);
    }

    type cross(Point p){ return x*p.y - y*p.x;}
    type dot(Point p){ return x*p.x + y*p.y;}
};


Point intersectLines(Point a1, Point d1, Point a2, Point d2){ //If Long long, treat d1.cross(d2) == 0
    return a1 + (d1 * ((a2-a1).cross(d2))) / d1.cross(d2); 
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int x, y;
    cin >> x >> y;
    Point A(x, y);
    cin >> x >> y;
    Point B(x, y);
    cin >> x >> y;
    Point C(x, y);


    Point d1 = B - A;
    d1 = d1 / d1.abs();
    Point d2 = C - A;
    d2 = d2 / d2.abs();
    Point bsA = d1 + d2;
    Point d3 = C - B;
    d3 = d3 / d3.abs();
    Point d4 = A - B;
    d4 = d4 / d4.abs();
    Point bsB = d3 + d4;

    auto inC = intersectLines(A, bsA, B, bsB);

    Point xx = intersectLines(A, B-A, inC, (B-A).rot(90));


    cout << fixed << setprecision(6) << inC.x << " " << inC.y << " " << xx.dist(inC) << "\n";
    //find the intersection of A + bsA x and B + bsB x
}
