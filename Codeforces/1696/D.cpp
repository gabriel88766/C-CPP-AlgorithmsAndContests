#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 250005, M = 20; // M >= log2(N)
int sparse1[N][M], sparse2[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse1[i][0] = sparse2[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n){
                sparse1[i][j] = min(sparse1[i][j-1], sparse1[i + (1 << (j-1))][j-1]);
                sparse2[i][j] = max(sparse2[i][j-1], sparse2[i + (1 << (j-1))][j-1]);
            }else{
                sparse1[i][j] = sparse1[i][j-1];
                sparse2[i][j] = sparse2[i][j-1];
            }
        }
    }
}

int query1(int a, int b){
    if(a == b) return sparse1[a][0]; 
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse1[a][pot], sparse1[b - (1 << pot) + 1][pot]);
}

int query2(int a, int b){
    if(a == b) return sparse2[a][0]; 
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse2[a][pot], sparse2[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        v.resize(n);
        vector<int> inv(n+1);
        for(int i=0;i<n;i++){
             cin >> v[i];
             inv[v[i]] = i;
        }
        build();
        int ans = 0;
        int cur = 0;
        while(cur != (n-1)){
            ans++;
            if(v[cur+1] > v[cur]){
                //min to max
                int mx = cur;
                for(int i=n/2;i>=1;i>>=1){
                    while(mx + i < n && query1(cur, mx+i) == v[cur]) mx += i;
                }
                int nxt = query2(cur, mx);
                cur = inv[nxt];
            }else{
                //max to min
                int mx = cur;
                for(int i=n/2;i>=1;i>>=1){
                    while(mx + i < n && query2(cur, mx+i) == v[cur]) mx += i;
                }
                int nxt = query1(cur, mx);
                cur = inv[nxt];
            }
        }
        cout << ans << "\n";
    }
}
