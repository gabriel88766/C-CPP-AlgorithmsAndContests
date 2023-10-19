#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 35005;
vector<int> v[N];
ll vl[N], vr[N];
ll b[N];
ll a[N];
int p1 = 1, p2 = 1;
ll ans = 0;
vector<vector<ll>> dp(2, vector<ll>(N));
ll C(int l, int r){
    while(p2 <= r){
        int num = a[p2];
        if(vr[num] > vl[num]) ans -= v[num][vr[num]] - v[num][vl[num]];
        vr[num]++;
        ans += v[num][vr[num]] - v[num][vl[num]];
        p2++;
    } //ans += (b[a[p2++]]++);
    while(p1 > l){
        --p1;
        int num = a[p1];
        if(vr[num] > vl[num]) ans -= v[num][vr[num]] - v[num][vl[num]];
        vl[num]--;
        ans += v[num][vr[num]] - v[num][vl[num]];
    } //ans += (b[a[--p1]]++);
    while(p1 < l){
        int num = a[p1];
        ans -= v[num][vr[num]] - v[num][vl[num]];
        vl[num]++;
        if(vr[num] > vl[num]) ans += v[num][vr[num]] - v[num][vl[num]];
        p1++;
    } //ans -= (--b[a[p1++]]);
    while(p2 > r+1){
        p2--;
        int num = a[p2];
        ans -= v[num][vr[num]] - v[num][vl[num]];
        --vr[num];
        if(vr[num] > vl[num]) ans += v[num][vr[num]] - v[num][vl[num]];
        
    } //ans -= (--b[a[--p2]]);
    return ans;
}

void dcdp(int l, int r, int opl, int opr){
    int m = (l+r)/2;
    int opm = opl;
    ll best = INF_LL;
    for(int u = opl; u <= min(opr, m-1); u++){
        if(best > dp[0][u] + C(u+1, m)){
            best = dp[0][u] + C(u+1, m);
            opm = u;
        }
    }
    dp[1][m] = best;
    if(l == r) return;
    dcdp(l, m, opl, opm);
    dcdp(m+1, r, opm, opr);
}

void solve(int n, int k){
    for(int i=1;i<=n;i++){
        dp[1][i] = C(1, i);
    }
    for(int i=2;i<=k;i++){
        dp[0] = dp[1];
        dcdp(1, n, i-1, n-1);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    memset(vr, 0xFF, sizeof(vr));
    solve(n, k);
    cout << dp[1][n] << "\n"; 
}
