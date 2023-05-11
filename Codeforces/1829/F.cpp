#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> adj[205];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ind1;
        for(int i=1;i<=n;i++){
            if(adj[i].size() == 1){
                ind1 = i;
                break;
            }
        }
        int ind2 = adj[ind1][0], ind3;
        int y = adj[ind2].size() - 1;
        for(auto x : adj[ind2]){
            if(adj[x].size() != 1){
                ind3 = x;
                break;
            }
        }
        int x = adj[ind3].size();
        cout << x << " " << y << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
