#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 100005;
vector<int> adj[N];
int d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int sqt = sqrt(n);
    int q;
    cin >> q;
    vector<tuple<int,int,int>> vq;
    for(int i=0;i<q;i++){
        int p, k;
        cin >> p >> k;
        vq.push_back({p, k, i});
    }
    sort(vq.begin(), vq.end(), [&](tuple<int,int,int> u, tuple<int,int,int> v){
        auto [p1, k1, i1] = u;
        auto [p2, k2, i2] = v;
        return k1 < k2;
    });
    vector<int> ans(q);
    int cur = 0;
    for(auto [p, k, i] : vq){
        if(cur >= sqt){
            int pcur = p;
            while(pcur <= n){
                pcur = pcur + v[pcur] + k;
                ans[i]++;
            }
        }else{
            if(cur != k){
                cur = k;
                for(int i=1;i<=n+1;i++) {d[i] = INF_INT; adj[i].clear();}
                d[n+1] = 0;
                for(int i=1;i<=n;i++){
                    int dst = i + v[i] + cur;
                    if(dst > n) dst = n+1;
                    adj[dst].push_back(i);
                }
                queue<int> q;
                q.push(n+1);
                while(!q.empty()){
                    auto u = q.front();
                    q.pop();
                    for(auto v : adj[u]){
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
            ans[i] = d[p];   
        } 
    }
    for(auto x : ans) cout << x << "\n";
}
