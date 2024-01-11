#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


bool check(vector<int> &adj){
    for(int i=0;i<adj.size();i++) if(__builtin_popcount(adj[i]) > 2) return false;
    vector<int> vis(12, 0);
    for(int i=0;i<12;i++){
        if(!vis[i] && adj[i] != 0){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                if(vis[u]) return false;
                vis[u] = 1;
                for(int j=0;j<12;j++){
                    if(adj[u] & (1 << j)){
                        if(!vis[j]) q.push(j);
                    }
                }
            }
        }
    }
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> adj(12, 0);
    map<vector<int>, int> dp;
    while(n--){
        int c;
        string s;
        cin >> c >> s;
        auto v = adj;
        for(int i=0;i<s.size();i++){
            if(i != 0){
                v[s[i]-'a'] |= (1 << (s[i-1]-'a'));
            }
            if(i != (s.size()-1)){
                v[s[i]-'a'] |= (1 << (s[i+1]-'a'));
            }
        }
        if(check(v)){
            map<vector<int>, int> mod;
            for(auto [vec, xx] : dp){
                //merge dp[i] and dq
                auto nv = v;
                for(int j=0;j<12;j++) nv[j] |= vec.at(j);
                if(check(nv)){
                    if(nv == vec) mod[nv] = 0;
                    else mod[nv] += xx;
                }
            }
            dp[v] += c;
            for(auto [k, x] : mod){
                if(k != v) dp[k] += (x + c);
                else dp[k] += x;
            }
        }
    }
    if(dp.empty()) cout << "abcdefghijkl\n";
    else{
        cout << dp.size() << "\n";
        int maxv = 0;
        vector<int> ans;
        for(auto x : dp){
            if(maxv < x.second){
                maxv = x.second;
                ans = x.first;
            }
        }
        assert(check(ans));
        vector<int> vis(12, 0);
        deque<char> rans;
        for(int i=0;i<12;i++){
            if(!vis[i]){
                deque<char> cd;
                vector<int> aux(12, 0);
                int cur = i;
                aux[cur] = true;
                while(__builtin_popcount(ans[cur]) == 2){
                    for(int j=0;j<12;j++){
                        if(ans[cur] & (1 << j)){
                            if(!aux[j]){
                                cur = j;
                                aux[cur] = true;
                                break;
                            }
                        }
                    }
                }
                while(!vis[cur]){
                    cd.push_back(cur + 'a');
                    vis[cur] = true;
                    for(int j=0;j<12;j++){
                        if(ans[cur] & (1 << j) ){
                            if(!vis[j]){
                                cur = j;
                                break;
                            }
                        }
                    }
                }
                for(auto x : cd) rans.push_back(x);
            }
        }
        cout << maxv << "\n";
        for(auto x : rans) cout << x;
        cout << "\n";
    }
}
