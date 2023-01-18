#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; //15
using namespace std;

struct Point{
    long double x, y;
    Point(long double x, long double y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(long double d){ return Point(x * d, y * d);}

    long double abs() {return sqrtl(x*x+y*y); }
    long double dist(Point p){ return (*this-p).abs();}

    Point rot(double g){// g degrees
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g));
    }
};

long double sqrtest(long double a, long double b){
    return sqrtl(a*a+b*b);
}

double sqrtest2(double a, double b){
    return sqrt(a*a+b*b);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    long double x1,y1,r1,x2,y2,r2,dr;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    dr = r1+r2 - EPS;
    
    cout << fixed << setprecision(15);

    Point a(x1, y1), b(x2, y2);
    /*Point dir = b - a;
    Point dir2 = dir.rot(90);
    Point dira;*/
    long double distance = a.dist(b);

    if(distance >= dr){ //pythagoras no intersect
        cout << "0.000000000000000";
        return 0;
    }
    distance -= EPS;
    if((distance + r1) < r2 || (distance + r2) < r1){ // circle A in circle B
        if(r1 < r2) cout << PI*r1*r1;
        else cout << PI*r2*r2;
        return 0;
    }
    distance += EPS;
    long double d = a.dist(b); 
    long double ang1 = acosl((r1*r1+d*d-r2*r2)/(2*d*r1));
    long double ang2 = acosl((r2*r2+d*d-r1*r1)/(2*d*r2));
    long double ans = -(r1 *cosl(ang1)) * (r1 * sinl(ang1));
    ans -= (r2 * cosl(ang2)) * (r2 * sinl(ang2));
    ans += ang1 * r1 * r1;
    ans += ang2 * r2 * r2;
    cout << ans;

}
