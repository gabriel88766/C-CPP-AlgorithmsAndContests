#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n;
    vector<int> ans;
    ans.push_back(1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        adj[i].push_back(a);
        adj[i].push_back(b);
    }
    if(n == 3){
        cout << "1 2 3";
        return 0;
    }
    int cur = ans.back();
    for(int i=1;i<n;i++){
        int a = adj[cur][0], b = adj[cur][1];
        if(adj[a][0] == b || adj[a][1] == b) cur = a;
        else cur = b;
        ans.push_back(cur);
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    
}
