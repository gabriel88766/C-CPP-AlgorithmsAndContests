#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
pair<ll,ll> mv[N];
int m;
bool check(ll &sx, ll &sy, ll &dx, ll &dy, ll &n){
    ll rem = n % m;
    ll div = n / m;
    ll cx = sx + div*mv[m].first + mv[rem].first;
    ll cy = sy + div*mv[m].second + mv[rem].second;
    ll dif = abs(dx - cx) + abs(dy - cy);
    return dif <= n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    ll lo = 0, hi = 1e15;
    cin  >> m;
    int cx = 0, cy = 0;
    for(int i=1;i<=m;i++){
        char cur;
        cin >> cur;
        if(cur == 'U') cy++;
        if(cur == 'D') cy--;
        if(cur == 'L') cx--;
        if(cur == 'R') cx++;
        mv[i] = {cx, cy};    
    }
    if(check(sx, sy, dx, dy, hi)){
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            if(check(sx,sy,dx,dy, mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }else cout << "-1\n";
}
