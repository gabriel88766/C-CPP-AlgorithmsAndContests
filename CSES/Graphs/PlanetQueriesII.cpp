//Hard!!!
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;
int succ[N][M], cn[N], cnt = 0, dist[N], ord[N], sz[N]; //dist = distance to cycle, cn cycle number, sz size of cycle, ord order in cycle(only if i in cycle)
char vis[N]; 

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> succ[i][0];
    }
    for(int i=1;i<M;i++) for(int j=1;j<=n;j++) succ[j][i] = succ[succ[j][i-1]][i-1];
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int a = i, b = i, t = 0, d = 0;
            do{
                a = succ[a][0];
                b = succ[b][1];
                t++;
                if(vis[a]) break;
            }while(a != b);
            if(vis[a]){
                int c = i;
                for(int i=0;i<t;i++){
                    dist[c] = dist[a] + t - i;
                    cn[c] = cn[a];
                    vis[c] = true;
                    c = succ[c][0];
                }
            }else{
                int c = i;
                while(c != a){
                    d++;
                    c = succ[c][0];
                    a = succ[a][0];
                }
                ++cnt; //cycle number cnt;
                c = i;
                for(int i=0;i<d;i++){
                    cn[c] = cnt;
                    vis[c] = true;
                    dist[c] = d-i;
                    c = succ[c][0];
                }
                sz[cnt] = t;
                for(int i=0;i<t;i++){
                    ord[c] = i;
                    cn[c] = cnt;
                    vis[c] = true;
                    dist[c] = 0;
                    c = succ[c][0];
                }
            }   
        }
    }
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(cn[a] != cn[b] || dist[b] > dist[a]) cout << "-1\n";
        else{
            int k = dist[a] - dist[b];
            int cur = a;
            for(int j = M-1;j>=0;j--) if(k & (1 << j)) cur = succ[cur][j];
            if(dist[b] != 0){
                if(cur != b) cout << "-1\n";
                else cout << k << "\n";
            }else{
                if(ord[b] >= ord[cur]) cout << k + ord[b] - ord[cur] << "\n";
                else cout << k + sz[cn[b]] + ord[b] - ord[cur] << "\n"; 
            }
        }
    }
}
