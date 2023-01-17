#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; //15
using namespace std;

struct Point{
    double x, y;
    Point(){}
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    double x1,y1,r1,x2,y2,r2,dr;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    dr = r1+r2 - EPS;
    
    cout << fixed << setprecision(15);

    Point a(x1, y1), b(x2, y2);
    Point dir = b - a;
    Point dir2 = dir.rot(90);
    Point dira;
    double distance = a.dist(b);

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
    Point p1;
    double lo= (distance-r2)/distance, hi=1-(distance-r1)/distance, midbfs;
    cout << lo << " " << hi << "\n";
    Point mid;
    while((hi - lo) > EPS){
        midbfs = (hi+lo)/2;
        mid = a + (dir * midbfs);
        double lo2 = 0, hi2 = max(r1/dir2.abs(), r2/dir2.abs()), mid2;
        while((hi2-lo2) > EPS){
            mid2 = (lo2+hi2)/2;
            p1 = mid + (dir2 * mid2);
            if(p1.dist(b) > r2) hi2 = mid2;
            else lo2 = mid2;
        }
        if(p1.dist(a) > r1) hi=midbfs;
        else lo = midbfs;
    }
    Point p2 = p1 + ((mid-p1) * 2);
    
    double a1, a2, h;
    h = p1.dist(mid);
    a1 = mid.dist(a);
    a2 = mid.dist(b);
    dira = mid - a;
    cout << midbfs << "\n";
    double ans = atan(h/a1)*r1*r1 + atan(h/a2)*r2*r2;
    if(((dira.x > 0 && dir.x < 0) || (dira.x < 0 && dir.x > 0))) a1 = -a1;
    dir = a - b;
    dira = mid - b;
    if(((dira.x > 0 && dir.x < 0) || (dira.x < 0 && dir.x > 0))) a2 = -a2;
    ans = (a1+a2)*h;
    cout << ans;
}
