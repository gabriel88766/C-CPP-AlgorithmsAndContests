#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 100005, M = 18; // M >= log2(N)
ll sparse[N][M];
int v[N];
int n;

void build(){
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> n >> k;
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            vp[i].first = aux;
        }
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            vp[i].second = aux;
        }
        sort(vp.begin(), vp.end());
        for(int i=0;i<n;i++){
            v[i] = vp[i].second;
        }
        build();
        int h = 0, bp = 0;
        while(k > 0){
            h += k;
            while(bp < n && vp[bp].first <= h) bp++;
            if(bp == n){
                cout << "YES\n";
                break;
            }
            k -= query(bp, n-1);
        }
        if(k <= 0){
            cout << "NO\n";
        }
    }
}
