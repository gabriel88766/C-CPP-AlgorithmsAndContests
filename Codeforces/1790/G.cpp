#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool tk[N], bn[N], dr[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, p, b;
        cin >> n >> m;
        cin >> p >> b;
        for(int i=1;i<=p;i++){
            int x;
            cin >> x;
            tk[x] = true;
        }
        for(int j=1;j<=b;j++){
            int x;
            cin >> x;
            bn[x] = true;
        }
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(bn[i]){
                for(auto v : adj[i]){
                    if(bn[v]){
                        dr[i] = true;
                    }
                }
            }
        }
        vector<int> d(n+1, INF_INT);
        d[1] = 0;
        queue<int> q;
        q.push(1);
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    if(bn[v]){
                        q.push(v); //v is red
                    }
                }
            }
        }
        vector<int> good;
        for(int i=1;i<=n;i++){
            if(tk[i] && d[i] != INF_INT) good.push_back(i);
        }
        
        if(good.size() == 0) cout << "NO\n";
        else if(good.size() >= 2) cout << "YES\n";
        else{
            int sum = 0;
            for(int i=1;i<=n;i++){
                if(tk[i] && i != good[0]){
                    int cur = 0;
                    for(auto v : adj[i]){
                        if(dr[v]) sum = INF_INT;
                        if(bn[v]) cur = 1;
                    }
                    sum += cur;
                }
            }
            if(sum + 1 >= d[good[0]]) cout << "YES\n";
            else cout << "NO\n";
        }   

        //clear
        for(int i=1;i<=n;i++){
            adj[i].clear();
            tk[i] = bn[i] = false;
            dr[i] = false;
        }
    }
}