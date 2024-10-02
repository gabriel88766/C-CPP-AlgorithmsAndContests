#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 100005, M = 18; // M >= log2(N)
int sparse[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = gcd(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

int query(int a, int b){
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
    map<int, ll> mp;
    for(int i=1;i<=n;i++){
        int lc = i;
        while(lc <= n){
            int cg = query(i, lc);
            int rc = lc;
            for(int k=n/2;k>=1;k>>=1){
                while(rc + k <= n && query(i, rc + k) == cg) rc += k;
            }
            mp[cg] += (rc - lc + 1);
            lc = rc + 1;
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(mp.count(x)) cout << mp[x] << "\n";
        else cout << "0\n";
    }
}
