#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6+3;
const ll mod[] = {1000000453, 1000000459, 1000000483};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll pv[3];
ll pt[N][3];
ll inv[N][3];
ll pts[N][3];
ll invs[N][3];
ll binpow(ll a, ll b, ll m){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int j=0;j<=2;j++) pv[j] = uniform_int_distribution<int>(257, 1000000000)(rng);
    for(int j=0;j<=2;j++){
        pt[0][j] = inv[0][j] = 1;
        pt[1][j] = pv[j];
        inv[1][j] = binpow(pv[j], mod[j] - 2, mod[j]);
    }
    for(int i=2;i<N;i++){
        for(int j=0;j<=2;j++){
            pt[i][j] = (pt[i-1][j] * pt[1][j]) % mod[j];
            inv[i][j] = (inv[i-1][j] * inv[1][j]) % mod[j];
        }
    }
    int n;
    string s;
    cin >> n >> s;
    bool ok = false;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<=2;j++){
            if(i != 0) pts[i][j] = pts[i-1][j];
            pts[i][j] += pt[i][j] * (s[i]-'a');
            pts[i][j] %= mod[j];
        }
    }
    for(int i=2*n-1;i>=0;i--){
        for(int j=0;j<=2;j++){
            invs[i][j] = (invs[i+1][j] + pt[2*n-1 - i][j] * (s[i]-'a')) % mod[j];
        }
    }
    for(int i=0;i<=n;i++){
        int l = i;
        int r = i + n - 1;
        array<ll, 3> revv;
        array<ll, 3> dirv;
        for(int j=0;j<3;j++) revv[j] = dirv[j] = 0;
        for(int j=0;j<3;j++){
            revv[j] = (invs[l][j] - invs[r+1][j]) * inv[2*n - (r + 1)][j];
            if(i != 0) dirv[j] = pts[l-1][j];
            if(i != n) dirv[j] += (pts[2*n-1][j] - pts[r][j]) * inv[n][j];
            dirv[j] %= mod[j];
            if(dirv[j] < 0) dirv[j] += mod[j];
            revv[j] %= mod[j];
            if(revv[j] < 0) revv[j] += mod[j];
        }
        if(revv == dirv){
            ok = true;
            cout << s.substr(0, l) + s.substr(r+1, n-l) << "\n";
            cout << i << "\n";
            break;
        }
    }
    if(!ok) cout << "-1\n";
}
