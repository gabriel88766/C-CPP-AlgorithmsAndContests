//unsolved;
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll N = 2e5+3;
bool vis[N];
int ing[N];
int nums[N];
int n;

vector<int> topo;
void dfs_topo(int u){
    vis[u] = true;
    int nxt = u + nums[u];
    if(nxt > n) nxt = 0;
    if(nxt <= 0) nxt = 0;
    if(!vis[nxt]) dfs_topo(nxt);
    topo.push_back(u);
}
void topo_sort(int n){ 
    vis[0] = true;
    for(int i=1;i<=n;i++) vis[i] = false;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs_topo(i);
    reverse(topo.begin(), topo.end());   
}

void dfs(int u, int cnt){
    vis[u] = true;
    ing[u] = cnt;
    int nxt = u + nums[u];
    if(nxt > n) nxt = 0;
    if(nxt <= 0) nxt = 0;
    if(!vis[nxt]){
        dfs(nxt, cnt+1);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
            cin >> n;
            cout << 2 << "\n";
            continue;
        }
        ll ans = 0;
        
        for(int i=1;i<=n;i++){
            cin >> nums[i];
        }
        set<int> cycle;
        bool hasc = false;
        int cur = 1;
        for(int i=1;i<=n;i++) vis[i] = false;
        while(!vis[cur]){
            vis[cur] = true;
            cycle.insert(cur);
            if((cur + nums[cur] <= n) && (cur + nums[cur] > 0)) {cur += nums[cur];}
            else{
                cur = 0;
                break;
            }
        }
        if(vis[cur]) hasc = true;
        if(hasc){
            ans = (2*n+1-cycle.size());
            ans *= cycle.size();
        }else{
            ans = ((ll)(n-cycle.size())) * (2*n+1);
            ans += ((ll)cycle.size()) * (2 * n);
            ans -= ((ll)cycle.size() * (cycle.size()-1))/2;
            if(cycle.size() == 1) ans--;
        }
        cout << ans << "\n";
    }
}
