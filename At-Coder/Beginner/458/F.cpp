#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b, ll m){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]) % m;
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll b, ll  m){
    int size = a.size();
    vector<vector<ll>> ans(size,vector<ll>(size)); //idt
    for(int i=0;i<size;i++) ans[i][i] = 1; //idt

    while(b > 0){
        if(b & 1) 
            ans = multMatrix(ans, a, m);
        a = multMatrix(a, a, m);
        b >>= 1;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    //there are at most 10x10 = 100 states, and each state has 26 possible next state
    //if the state is final, give a 0 number, 1 is initial (all 0) from 0 all goes to 0.
    //some states are impossible to reach, but we are going to ignore them anyway... 
    vector<string> vs(k);
    for(int i=0;i<k;i++) cin >> vs[i];
    
    int st = 1;
    map<pair<int, int>, int> mp;
    for(int i=0;i<k;i++){
        for(int j=0;j<vs[i].size() - 1;j++) {
            mp[{i, j}] = ++st;
        }
    }
    vector<vector<ll>> adj(st+1, vector<ll>(st+1));
    adj[0][0] = 26;

    set<char> us;
    int tt1 = 26;
    for(int i=0;i<k;i++){
        if(vs[i].size() == 1 && !us.count(vs[i][0])){
            us.insert(vs[i][0]);
            adj[1][0]++;
            tt1--;
        }
    }
    for(int i=0;i<k;i++){
        if(us.count(vs[i][0])) continue;
        else{
            us.insert(vs[i][0]);
            adj[1][mp[{i, 0}]]++;
            tt1--;
        }
    }
    adj[1][1] = tt1;
    for(int i=0;i<k;i++){
        for(int j=0;j<vs[i].size()-1;j++){
            vector<vector<int>> cmx(k);
            for(int u = 0; u <= j; u++){
                int sz = j - u + 1;
                string ss = vs[i].substr(u, sz);
                for(int v = 0; v < k; v++){
                    //< sz, take only non finished states. if {i, j} is a finished, shouldn't be accounted anyway.
                    if(vs[v].size() > sz && vs[v].substr(0, sz) == ss){
                        cmx[v].push_back(sz);
                    }
                }
            }
            for(int v = 0; v < k; v++) cmx[v].push_back(0);
            int cn = mp[{i, j}];
            for(int x = 0; x < 26; x++){
                vector<int> bst(k, -1);
                for(int v = 0; v < k; v++){
                    for(auto y : cmx[v]){
                        if(vs[v][y] - 'a' == x){
                            bst[v] = y;
                            break;
                        }
                    }
                }
                int rbst = -1, idx = -1;
                bool endst = false;
                for(int v = 0; v < k; v++){
                    if(bst[v] > rbst){
                        rbst = bst[v];
                        idx = v;
                    }
                    if(bst[v] == vs[v].size() - 1){
                        endst = true;
                        adj[cn][0]++;
                        break;
                    }
                }
                if(!endst){
                    if(idx == -1) adj[cn][1]++;
                    else adj[cn][mp[{idx, rbst}]]++;
                } 
            }
        }
    }
    ll ans = 0;
    adj = binpow(adj, n, MOD);
    for(int i=1;i<=st;i++) ans = (ans + adj[1][i]) % MOD;
    cout << ans << "\n";
}
