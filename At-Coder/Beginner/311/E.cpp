#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;

int ps[N][N];
bool hole[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        hole[a][b] = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ps[i][j] = ps[i-1][j] + ps[i][j-1] -  ps[i-1][j-1];
            if(hole[i][j]) ps[i][j]++;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(hole[i][j]) continue;
            int lo = 0, hi = min(n-i, m-j), mid;
            while(lo != hi){
                mid = lo + (hi-lo+1)/2;
                if((ps[i+mid][j+mid] - ps[i-1][j+mid]-ps[i+mid][j-1]+ps[i-1][j-1]) != 0) hi = mid-1; 
                else lo = mid;
            }
            ans += (lo+1);
        }
    }
    cout << ans;
}
