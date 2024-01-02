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
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<int>());
        if(v[0] + v[1] > d) cout << "No\n";
        else{
            if(2*v[0] >= d){
                //v[0] is in diameter
                bitset<2005> bs;
                bs[0] = 1;
                for(int i=1;i<n;i++){
                    bs |= (bs << v[i]);
                }
                if(bs[d - v[0]]) cout << "Yes\n";
                else cout << "No\n";
            }else{
                //check if possible with v[0] included;
                bitset<2005> bs;
                bs[0] = 1;
                for(int i=1;i<n;i++){
                    bs |= (bs << v[i]);
                }
                if(bs[d - v[0]]){
                    cout << "Yes\n";
                    continue;
                }
                //otherwise subset sum problem
                vector<vector<int>> adj(d+1);
                vector<int> dp(d+1, 0);
                dp[0] = 1;
                for(int i=0;i<n;i++){
                    for(int j=d;j>=d-v[i];j--){
                        if(dp[j-v[i]]){
                            adj[j].push_back(i);
                            dp[j] = 1;
                        }
                    }
                }
                if(dp[d]){
                    vector<int> vis(d+1, false);
                    queue<int> q;
                    q.push(d);
                    vis[d] = true;
                    while(!q.empty()){
                        auto u = q.front();
                        q.pop();
                        for(auto v : adj[u]){
                            if(!vis[v]){
                                vis[v] = true;
                                q.push(v);
                            }
                        }
                    }
                    bool ok = false;
                    vector<int> ch;
                    for(int i=0;i<=d;i++){
                        if(vis[i]){
                            if(v[0] >= i && i + v[0] <= d){
                                ch.push_back()
                            }
                        }
                    }
                    if(ok) cout << "Yes\n";
                    else cout << "No\n";
                }else cout << "No\n";
            }
        }
    }
}

//UNSOLVED!