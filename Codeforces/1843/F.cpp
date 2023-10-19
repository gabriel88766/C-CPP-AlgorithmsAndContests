#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
const int M = 20;
int w[N];
int anc[N][M];
int maxv[N][M];
int minv[N][M];
int sum[N];
int h[N];
void add(int u){
    for(int i=1;i<M;i++){
        anc[u][i] = anc[anc[u][i-1]][i-1];
        maxv[u][i] = max(maxv[u][i-1], maxv[anc[u][i-1]][i-1]);
        minv[u][i] = min(minv[u][i-1], minv[anc[u][i-1]][i-1]);
    }
}
int lca(int a, int b){
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[b][i];
    if(a == b) return a;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}

int maxval(int u, int d){
    int ans = -INF_INT;
    for(int i = M-1; i>=0;i--) if(d & (1 << i)){
         ans = max(ans, maxv[u][i]);
         u = anc[u][i];
    }
    return ans;
}
int minval(int u, int d){
    int ans = INF_INT;
    for(int i = M-1; i>=0;i--) if(d & (1 << i)){
         ans = min(ans, minv[u][i]);
         u = anc[u][i];
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> q;
        n = q;
        for(int i=0;i<=n;i++){
            sum[i] = 0;
            h[i] = 0;
            for(int j=0;j<M;j++){
                maxv[i][j] = -INF_INT;
                minv[i][j] = INF_INT;
                anc[i][j] = 0;
            }
        }
        sum[1] = w[1] = 1;
        int cur = 1;
        for(int i=1;i<=q;i++){
            char c;
            cin >> c;
            if(c == '?'){
                int a, b, c;
                cin >> a >> b >> c;
                if(a == b){
                    if(c == w[a]) cout << "YES\n";
                    else cout << "NO\n";
                    continue;
                }
                int lc = lca(a, b);
                int min1 = minval(a, h[a]-h[lc]);
                int min2 = minval(b, h[b]-h[lc]);
                int max1 = maxval(a, h[a]-h[lc]);
                int max2 = maxval(b, h[a]-h[lc]);
                if(lc == a || lc == b){
                    if(lc == a) swap(min1, min2); swap(max1, max2);
                    if(c <= abs(max1-min1))
                }else{

                }
            }else{
                int a, b;
                cin >> a >> b;
                ++cur;
                w[cur] = b;
                sum[cur] = sum[a] + b;
                anc[cur][0] = a;
                maxv[cur][0] = minv[cur][0] = sum[cur];
                h[cur] = h[a] + 1;
                add(cur);
            }
        }
    }
}
