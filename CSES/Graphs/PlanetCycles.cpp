#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int succ[N], indg[N], cnt = 0, ans[N], x;
char vis[N]; 
bool flag = false;
vector<int> cycles[N];

void build_cycle(int u){
    vis[u] = 1;
    if(!vis[succ[u]]) build_cycle(succ[u]);
    else if(vis[succ[u]] == 1){
        x = succ[u];
        flag = true;
        ++cnt;
    }
    vis[u] = 2;
    if(flag) {cycles[cnt].emplace_back(u);}
    if(u == x) flag = false;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> succ[i];
        indg[succ[i]];
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) build_cycle(i);
    }
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<cycles[i].size(); j++) ans[cycles[i][j]] = cycles[i].size();
    }
    for(int i=1;i<=n;i++){
        if(indg[i] == 0){
            int aux = i, t = 0;
            while(!ans[aux]) aux = succ[aux], t++;
            int qtc = ans[aux];
            aux = i;
            while(t) ans[aux] = qtc + t, aux = succ[aux], t--;
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    
}
 