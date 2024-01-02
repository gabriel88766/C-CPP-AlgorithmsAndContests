#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> inv[N];
int vis[N], outdg[N], ans[N];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        inv[b].push_back(a);
        outdg[a]++;
    }
    priority_queue<int> pq;
    vector<int> topo;
    for(int i=1;i<=n;i++) if(outdg[i] == 0) pq.push(i);
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        topo.push_back(u);
        for(auto v : inv[u]){
            outdg[v]--;
            if(outdg[v] == 0) pq.push(v);
        }
    }
    reverse(topo.begin(), topo.end());
    for(auto x : topo) cout << x <<  " ";
    cout << "\n";
}
