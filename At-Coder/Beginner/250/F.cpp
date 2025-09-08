#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Point{
    ll x, y;
    Point(){x = y = 0;}
    Point(ll x, ll y) { this->x = x; this->y = y;}
    ll cross(Point p){ return x*p.y - y*p.x;}
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Point> vp(n+1);
    for(int i=1;i<=n;i++){
        cin >> vp[i].x >> vp[i].y;
    }
    ll S = 0;
    for(int i=1;i<n;i++) S += vp[i].cross(vp[i+1]);
    S += vp[n].cross(vp[1]);
    vector<ll> ps(2*n+1);
    for(int i=1;i<=2*n-1;i++){
        int v1 = i;
        int v2 = i + 1;
        if(v1 > n) v1 -= n;
        if(v2 > n) v2 -= n;
        ps[i+1] = ps[i] + vp[v1].cross(vp[v2]);
    }
    ll ans = INF_LL;
    for(int i=1;i<=n;i++){
        int ax = i;
        for(int jmp=n;jmp>=1;jmp>>=1){
            while(ax + jmp <= 2*n && 4*(ps[ax+jmp] - ps[i] + vp[ax+jmp > n ? ax + jmp - n : ax + jmp].cross(vp[i])) <= S) ax += jmp;
        }
        ans = min(ans, abs(S - 4*(ps[ax] - ps[i] + vp[ax > n ? ax - n : ax].cross(vp[i]))));
        if(ax + 1 <= 2*n) ax++;
        ans = min(ans, abs(S - 4*(ps[ax] - ps[i] + vp[ax > n ? ax - n : ax].cross(vp[i]))));
    }
    cout << ans << "\n";
}   
