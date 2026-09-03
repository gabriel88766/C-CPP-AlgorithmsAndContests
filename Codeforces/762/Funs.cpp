#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> cv;
void gen(vector<vector<int>> &vc, int s, int lc){
    if(s == 0){
        vc.push_back(cv);
        return;
    }
    for(int i = 1; i <= min(s, lc); i++){
        cv.push_back(i);
        gen(vc, s-i, i);
        cv.pop_back();
    }
}

ll nCr(ll n, ll k){
    ll ans = 1;
    for(int i=n-k+1;i<=n;i++) ans *= i;
    for(int i=1;i<=k;i++) ans /= i;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<vector<int>> vc[12];
    for(int i=1;i<=11;i++){
        gen(vc[i], i, INF_INT);
    }
    vector<vector<pair<int, int>>> vc2[12];
    for(int i=1;i<=11;i++){
        vc2[i].resize(vc[i].size());
        for(int j=0;j<vc[i].size();j++){
            auto &vec = vc[i][j];
            int cn = vec[0];
            int cnt = 1;
            for(int k=1;k<vec.size(); k++){
                if(vec[k] != cn){
                    vc2[i][j].push_back({cn, cnt});
                    cn = vec[k];
                    cnt = 1;
                }else{
                    cnt++;
                }
            }
            vc2[i][j].push_back({cn, cnt});
        }
    }
    
    map<vector<int>, int> mp[13]; //each tree has a set of children and an id;
    mp[1][{}] = 0;
    int id = 0;

    for(int i=2;i<=12;i++){
        for(auto vec : vc2[i-1]){
            vector<vector<int>> allv(1);
            for(auto [x, c] : vec) {
                if(mp[x].size() == 1){
                    //c = 2, 3, 4, ..., 11, x = 1 or 2
                    //this is many children with size 1
                    for(int a = 0; a < allv.size(); a++){
                        for(int y = 0; y < c; y++){
                            allv[a].push_back(mp[x].begin()->second);
                        }
                    }
                }else if(c == 1){
                    //qt[x] = 2, 4, 9, 20, 48, 115, 286, 719, 1842
                    vector<vector<int>> nvs;
                    for(auto vec : allv){
                        for(auto &[k, val] : mp[x]){
                            auto cpv = vec;
                            cpv.push_back(val);
                            nvs.push_back(cpv);
                        }
                    }
                    allv = nvs;
                }else if(c == 2){
                    //qt[x] = 2, 4, 9
                    vector<vector<int>> nvs;
                    for(auto vec : allv){
                        for(auto &[k1, val1] : mp[x]){
                            for(auto &[k2, val2] : mp[x]){
                                if(val1 > val2) continue;
                                auto cpv = vec;
                                cpv.push_back(val1);
                                cpv.push_back(val2);
                                nvs.push_back(cpv);
                            }
                            
                        }
                    }
                    allv = nvs;
                }else if(c == 3){
                    //qt[x] = 2;
                    vector<vector<int>> nvs;
                    for(auto vec : allv){
                        for(auto &[k1, val1] : mp[x]){
                            for(auto &[k2, val2] : mp[x]){
                                if(val1 > val2) continue;
                                for(auto &[k3, val3] : mp[x]){
                                    if(val2 > val3) continue;
                                    auto cpv = vec;
                                    cpv.push_back(val1);
                                    cpv.push_back(val2);
                                    cpv.push_back(val3);
                                    nvs.push_back(cpv);
                                }
                            }
                        }
                    }
                    allv = nvs;
                }else assert(false);
            }
            sort(allv.begin(), allv.end());
            for(auto vec : allv){
                mp[i][vec] = ++id;
            }
        }
    }
    //all preprocessing done.
    int n, m;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> m;
    vector<vector<int>> adj2(m+1);
    for(int i=1;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }
    vector<int> sub(m+1, 0);
    auto bfs = [&](vector<int> &d, int u){
        fill(d.begin(), d.end(), INF_INT);
        d[u] = d[0] = 0;
        queue<int> q;
        q.push(u);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto v : adj2[u]){
                if(d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    };
    function<int(int, int)> dfs1 = [&](int u, int p){
        sub[u] = 1;
        vector<pair<int, int>> vx;
        for(auto v : adj2[u]){
            if(v != p){
                int cv = dfs1(v, u);
                sub[u] += sub[v];
                vx.push_back({sub[v], cv});
            }
        }
        sort(vx.begin(), vx.end());
        vector<int> cv;
        for(auto [a, b] : vx) cv.push_back(b);
        assert(mp[sub[u]].count(cv));
        return mp[sub[u]][cv];
    };  
    vector<int> d(m+1), d2(m+1);
    bfs(d, 1);
    int a = max_element(d.begin(), d.end()) - d.begin();
    bfs(d, a);
    int b = max_element(d.begin(), d.end()) - d.begin();
    int dm = d[b];
    bfs(d2, b);
    vector<int> ct;
    cout << dm << endl;
    for(int i=1;i<=m;i++){
        if(d[i] + d2[i] == dm && d[i] >= dm/2 && d2[i] >= dm/2) ct.push_back(i);
    }
    assert(ct.size() <= 2);
    vector<int> vt;
    bool t1, tx;
    if(ct.size() == 2){
        t1 = false;
        vt.push_back(dfs1(ct[0], ct[1]));
        vt.push_back(dfs1(ct[1], ct[0]));
        if(sub[ct[0]] == sub[ct[1]]) tx = true;
        else tx = false;
    }else{
        t1 = true;
        vt.push_back(dfs1(ct[0], 0));
    }

    if(t1){
        for(int i = 1; i <= n; i++){
            dfs2(i, 0);
        }
    }else{
        for(int i = 1; i <= n; i++){
            for(auto v : adj[i]){
                if(v < i) continue;

            }
        }
    }

}
