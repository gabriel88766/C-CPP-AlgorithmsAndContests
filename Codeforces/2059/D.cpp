#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        //final state = (u1, u1) both need to have some common adjacent vertex
        int n, s1, s2, m1, m2;
        cin >> n >> s1 >> s2;
        vector<vector<int>> adj1(n+1), adj2(n+1);
        cin >> m1;
        for(int i=0;i<m1;i++){
            int a, b;
            cin >> a >> b;
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        cin >> m2;
        for(int i=0;i<m2;i++){
            int a, b;
            cin >> a >> b;
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        vector<bool> isf(n+1, false);
        for(int i=1;i<=n;i++){
            set<int> s2;
            for(auto &v : adj2[i]) s2.insert(v);
            for(auto &x : adj1[i]){
                if(s2.count(x)) isf[i] = true;
            }
        }
        //dijkstra?? looks slow
        //bfs with n*n queues? ok
        vector<vector<int>> d(n+1, vector<int>(n+1, INF_INT));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, s1, s2});
        d[s1][s2] = 0;
        
        while(pq.size()){
            auto [dn, a, b] = pq.top();
            pq.pop();
            for(auto &v1 : adj1[a]){
                for(auto &v2 : adj2[b]){
                    if(d[v1][v2] > d[a][b] + abs(v1-v2)){
                        d[v1][v2] = d[a][b] + abs(v1-v2);
                        pq.push({d[v1][v2], v1,v2});
                    }
                }
            }
        }
        
        int ans = INF_INT;
        for(int i=1;i<=n;i++){
            if(isf[i]) ans = min(ans, d[i][i]);
        }
        if(ans != INF_INT) cout << ans << "\n";
        else cout << "-1\n";
    }
}
 