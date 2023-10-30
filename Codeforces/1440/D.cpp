#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//fact 1 : if (k*(k-1))/2 > m, then impossible (for m=10^5, k >= 448 is impossible)
//fact 2 : at most 2m / k vertices has k or k-1(dont care) neighbors (if k == 200, at most 1000, for example)
//fact 2.5 : this implies O(x*k) = O(m), x = #vertices possible
//throw all away and go greedy!
const int N = 1e5+3;
unordered_set<int> adj[N];
bool in[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int k2 = k-1;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            in[i] = true;
        }
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        vector<int> rml;
        for(int i=1;i<=n;i++){
            if(adj[i].size() < k2){
                 rml.push_back(i);
                 in[i] = false;
            }
        }
        while(rml.size()){
            auto now = rml.back();
            rml.pop_back();
            for(auto x : adj[now]){
                adj[x].erase(now);
                if(adj[x].size() < k2){
                    if(in[x]){
                        rml.push_back(x);
                        in[x] = false;
                    }
                }
            }
        }
        //vertex in set, so at least k-1 degree
        queue<int> hn1;
        for(int i=1;i<=n;i++){
            if(adj[i].size() == k2) hn1.push(i);
        }
        
        int ans = -1;
        while(hn1.size()){
            int now = hn1.front();
            hn1.pop();
            if(adj[now].size() != k2){
                for(auto x : adj[now]){
                    adj[x].erase(now);
                    if(adj[x].size() == k2){
                        hn1.push(x);
                    }
                }
                in[now] = false;
                continue;
            }
            bool ok = true;
            for(auto x: adj[now]){
                for(auto y: adj[now]){
                    if(x == y) continue;
                    if(!adj[x].count(y)){
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok){
                ans = now;
                break;
            }
            for(auto x : adj[now]){
                adj[x].erase(now);
                if(adj[x].size() == k2){
                    hn1.push(x);
                }
            }
            in[now] = false;
        }
        if(ans == -1){
            vector<int> ansv;
            for(int i=1;i<=n;i++) if(in[i]) ansv.push_back(i);
            if(ansv.size()){
                cout << "1 " << ansv.size() << "\n";
                for(auto x : ansv) cout << x << " ";
                cout << "\n";
            }else cout << "-1\n";
        }else{
            cout << "2\n" << ans << " ";
            for(auto x : adj[ans]) cout << x << " ";
            cout << "\n";
        }
        

        
    }
}
