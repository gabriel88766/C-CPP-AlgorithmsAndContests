#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef long long T;

struct Point{
    T x, y;
    Point(){}
    Point(T x, T y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(T d){ return Point(x * d, y * d);}
    Point operator /(T d){ return Point(x/d, y/d);} //integer division, maybe not what you want.
};

long long areaT(Point a, Point b, Point c){
    return a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
}

Point bary(Point a, Point b, Point c){
    Point x = a + b + c;
    return x;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<Point> p(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i].x >> p[i].y;
    }
    cout << fixed << setprecision(10);
    //total area;
    long long Stt = 0;
    Point bar = {0, 0};
    vector<Point> barps(n+1);
    vector<long long> arps(n+1, 0);
    for(int i=2;i<n;i++){
        long long A = areaT(p[1], p[i], p[i+1]);
        Point curb = bary(p[1], p[i], p[i+1]) * A;
        bar = bar + curb;
        Stt += A;
        arps[i+1] = arps[i] + A;
        barps[i+1] = barps[i] + curb;
    }
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(b > a){
            //a -> a+1 -> ... -> b; 
            if(a == 1){
                Point ans = barps[b];
                cout << ans.x/(3.0*arps[b]) << " " << ans.y/(3.0*arps[b]) << "\n";
            }else{
                Point ans = barps[a] + barps[n] - barps[b];
                long long  A = arps[a] + arps[n] - arps[b];
                long long  cA = areaT(p[1], p[a], p[b]);
                Point cB = bary(p[1], p[a], p[b]) * cA;
                ans = ans + cB;
                A += cA;
                ans = bar - ans;
                A = Stt - A;
                cout << ans.x / (3.0*A) << " " << ans.y / (3.0 * A) << "\n";
            }
        }else{
            swap(a, b);
            Point ans = barps[a] + barps[n] - barps[b];
            long long  A = arps[a] + arps[n] - arps[b];
            long long  cA = areaT(p[1], p[a], p[b]);
            Point cB = bary(p[1], p[a], p[b]) * cA;
            ans = ans + cB;
            A += cA;
            cout << ans.x / (3.0 * A) << " " << ans.y / (3.0 * A) << "\n";
        }
    }

}
