#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
bool blk[N];
vector<int> adj[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> b >> a;
        adj[a].push_back(b);
    }
    cin >> q;
    for(int i=1; i<=q;i++){
        int tq, v;
        cin >> tq >> v;
        if(tq == 1){
            queue<int> q;
            if(!blk[v]){
                q.push(v);
                blk[v] = true;
            }
            while(q.size()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(!blk[v]){
                        q.push(v);
                        blk[v] = true;
                    }
                }
            }
        }else{
            if(blk[v]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
