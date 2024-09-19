#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 300005, M = 20; // M >= log2(N)
ll sparse[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=1;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 1; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = gcd(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return gcd(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    v.resize(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    vector<int> ans;
    int sz = 0;
    for(int i=1;i<=n;i++){
        int l = i, r = i;
        for(int k=n/2;k>=1;k>>=1){
            while(l - k >= 1 && query(l-k, i) >= v[i]) l -= k;
        }
        for(int k=n/2;k>=1;k>>=1){
            while(r + k <= n && query(i, r+k) >= v[i]) r += k;
        }
        int csz = r - l;
        if(csz > sz){
            sz = csz;
            ans = {l};
        }else if(csz == sz){
            ans.push_back(l);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << " " << sz << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
} 
