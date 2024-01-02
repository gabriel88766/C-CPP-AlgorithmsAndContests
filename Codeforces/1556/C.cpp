#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005, M = 12; // M >= log2(N)
ll sparse[N][M];

void build(vector<ll> &v){
    int n = v.size();
    for(int i=0;i < n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1];
        if(i % 2) ps[i] += v[i];
        else ps[i] -= v[i];
    }
    build(ps);
    ll ans = 0;
    for(int i=1;i<=n;i+=2){
        for(int j=i+1;j<=n;j+=2){
            if(i + 1 == j){
                ans += min(v[i], v[j]);
            }else{
                ll mv = abs(query(i+1, j-1) - ps[i]);
                ll bl = ps[j-1] - ps[i] + mv;
                ll d1 = v[i] - mv;
                ll d2 = v[j] - bl;
                if(min(d1, d2) >= 0){
                    ans += min(d1, d2) + 1; 
                }
            }
        }
    }
    cout << ans << "\n";
}
