#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
set<int> ss[N];
vector<int> cl[N];
int vis[N];
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
        set<int> us;
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            cl[a].push_back(c);
            cl[b].push_back(c);
            ss[c].insert(a);
            ss[c].insert(b);
            us.insert(c);
        }
        int s, dst;
        cin >> s >> dst;
        vector<int> d(n+1, INF_INT);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto cs : cl[u]){
                if(!vis[cs]){
                    vis[cs] = true;
                    for(auto v : ss[cs]){
                        if(d[v] > d[u] + 1){
                            d[v] = d[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }
        }
        cout << d[dst] << "\n";






        for(auto x : us){
            ss[x].clear();
            vis[x] = false;
        }
        for(int i=1;i<=n;i++) cl[i].clear();
    }
}
