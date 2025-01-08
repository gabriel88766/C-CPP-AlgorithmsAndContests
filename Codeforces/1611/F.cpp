#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



const int N = 200005, M = 20; // M >= log2(N)
ll sparse[N][M];
vector<ll> v;
void build(vector<ll> &ps){
    int n = ps.size();
    for(int i=0;i<n;i++) sparse[i][0] = ps[i];
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
    int t;
    cin >> t;
    int c = 0;
    while(t--){
        c++;
        ll n, s;
        cin >> n >> s;
        vector<ll> v(n+1);
        v[0] = -INF_INT;
        for(int i=1;i<=n;i++) cin >> v[i];
        if(*max_element(v.begin(), v.end()) + s < 0) cout << "-1\n";
        else{
            vector<ll> ps(n+1);
            for(int i=1;i<=n;i++){
                ps[i] = v[i] + ps[i-1];
            }
            build(ps);
            pair<int, int> ans = {0, -1};
            for(int i=1;i<=n;i++){
                int cl = ans.second - ans.first + 1;
                int j = i-1;    
                for(int k=n;k>=1;k>>=1){
                    while(j + k <= n && ps[i-1] - query(i-1, j+k) <= s) j += k;
                }
                if(j - i + 1 > cl) ans = {i, j};
            }
            cout << ans.first << " " << ans.second << "\n";

        }
    }
}
