#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int num[N];
map<int, int> qnt;
int tt = 0;
bool ans[N];
void dfs(int u, int p){
    qnt[num[u]]++;
    if(qnt[num[u]] == 2) tt++;
    if(tt) ans[u] = true;
    else ans[u] = false;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }

    qnt[num[u]]--;
    if(qnt[num[u]] == 1) tt--;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> num[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
