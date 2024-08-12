#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
struct Edge{
    int a, b, w;
    bool operator< (const Edge &v) const {
        return w > v.w;
    }
};

vector<int> adj[N], adjw[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> ans(n);
    vector<bool> inT(n);
    inT[s] = true;
    ans[s] = s;
    ll tw = 0;
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
    }
    priority_queue<Edge> pq;
    for(int i=0;i<adj[s].size();i++){
        pq.push({s, adj[s][i], adjw[s][i]});
    }

    while(!pq.empty()){
        auto [a, b, c] = pq.top();
        cout << c << "\n";
        pq.pop();
        if(inT[b]) continue;
        inT[b] = true;
        ans[b] = a;
        tw += c;
        for(int i=0;i<adj[b].size();i++){
            pq.push({b, adj[b][i], adjw[b][i]});
        }
    }
    cout << tw << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}