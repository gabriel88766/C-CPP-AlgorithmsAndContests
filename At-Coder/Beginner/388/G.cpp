#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 200005, M = 20; // M >= log2(N)
int sparse[N][M];
vector<int> vp;

void build(){
    int n = vp.size();
    for(int i=0;i<n;i++) sparse[i][0] = vp[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

int query(int a, int b){
    if(a > b) return 0;
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    vp.resize(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        auto it = lower_bound(v.begin(), v.end(), 2*v[i]);
        if(it == v.end()) vp[i] = INF_INT;
        else vp[i] = (it - v.begin()) - i;
    }
    build();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int lo = 0, hi = (r - l + 1) / 2;
        while(lo != hi){
            int mid = lo + (hi - lo + 1) / 2;
            if(query(l, l + mid - 1) <= (r-l-mid+1)) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
