#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
    T cross(Point p){ return x*p.y - y*p.x;}
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Point<ll>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].x >> vp[i].y;
    int ans = n/3;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cnt = 2;
            for(int k=0;k<n;k++){
                if(k == i) continue;
                if(k == j) continue;
                if((vp[i] - vp[j]).cross(vp[k] - vp[i]) == 0) cnt++;
            }
            ans = min(ans, n-cnt);
        }
    }
    cout << ans << "\n";
}
