//UNSOLVED, circle to circle intersection
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Point{
    long double x, y;
    Point(){}
    Point(long double x, long double y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(long double d){ return Point(x * d, y * d);}
    Point operator /(long double d){ return Point(x/d, y/d);}

    long double abs() {return sqrtl(x*x+y*y); }
    long double dist(Point p){ return (*this-p).abs();}

    long double scalar(Point p){ return x*p.x + y*p.y;}
    long double cross(Point p){ return x*p.y - y*p.x;} //if pos, p is in left of vector (x, y), right otherwise
    Point rot(long double g){// g degrees
        g *= PI/180;
        return Point(x * cosl(g) - y * sinl(g), x * sinl(g) + y * cosl(g));
    }
};

Point intersectLines(Point a1, Point dir1, Point a2, Point dir2){
    return a1 + dir1 * ((a2-a1).cross(dir2) / dir1.cross(dir2)); 
}

vector<Point> circle_circle_intersection(Point a, Point b, long double r, long double R) {
    vector<Point> ret;
    long double d = a.dist(b);
    if (d > r + R || d + min(r, R) < max(r, R)) return ret;
    long double x = (d*d - R*R + r*r)/(2*d);
    long double y = (r*r - x*x);
    Point v = (b - a)/d;
    ret.push_back(a + v*x + v.rot(90)*y);
    if (y-EPS > 0)
        ret.push_back(a + v*x - v.rot(90)*y);
    return ret;
}

long double ansr1, ansr2;
Point ansC1, ansC2;

//first check r1 != r2
void findL(long double &ansr, Point &ansC, Point p1, long double r1, Point p2, long double r2){
    if(r2 < r1) swap(r1,r2), swap(p1,p2);
    Point dir = p1 - p2;
    long double dps = p1.dist(p2);
    long double a = dps/(1+r2/r1);
    long double d = r1*(r1/(r2-r1) * (dps/(r1+r2)));
    ansC = p1 + dir * (d/dir.abs());
    ansr = a+d;
}

bool equals(long double a, long double b){
    if(a - EPS < b && a + EPS > b) return true;
    else return false;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    long double x1,x2,y1,y2,x3,y3,r1,r2,r3=1005;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;
    cout << fixed << setprecision(5);

    Point p1(x1,y1), p2(x2,y2), p3(x3,y3);
    if(equals(r1,r2) || equals(r1,r3) || equals(r2,r3)){
        //3 equals or 1 equal?
        if(equals(r1,r2) && equals(r1,r3) && equals(r2,r3)){
            //1st case
            Point dir1 = p2-p1, dir2 = p3-p1;
            dir1 = dir1.rot(90), dir2 = dir2.rot(90);
            Point pm1 = p1 + (p2-p1)/2, pm2 = p1 + (p3-p1)/2;
            long double lo = -1e9, hi = 1e9, mid;
            int stlo = dir1.cross(pm2+dir2*lo-pm1) > 0 ? 1 : -1;
            Point intersect = intersectLines(pm1, dir1, pm2, dir2);
            /*while(hi - lo > EPS){
                mid = (lo+hi)/2;
                intersect = pm2 + dir2 * mid;
                int now = dir1.cross(intersect - pm1) > 0 ? 1 : -1;
                if(now == stlo) lo = mid;
                else hi = mid;
            }*/
            cout << intersect.x << " " << intersect.y;
            return 0;
        }else{
            //2nd case
            if(equals(r1,r3)) swap(r1,r2), swap(p1,p2);
            else if(equals(r1,r2)) swap(r1,r3), swap(p1,p3);
            //now, r2 == r3, if p3 
            // r1 r2 and r1 r3 lies in 3rd case
        }
    }
    //3rd case
    findL(ansr1, ansC1, p1, r1, p2, r2);
    findL(ansr2, ansC2, p1, r1, p3, r3);
    //find intersects
    vector<Point> inters = circle_circle_intersection(ansC1,ansC2,ansr1,ansr2);
    if(!inters.empty()){
        int indans;
        long double mindist = 1e300;
        for(int i=0;i<inters.size();i++){
            if(p1.dist(inters[i])){
                mindist = p1.dist(inters[i]);
                indans = i;
            }
        }
        cout << inters[indans].x << " " << inters[indans].y;
    }
}
