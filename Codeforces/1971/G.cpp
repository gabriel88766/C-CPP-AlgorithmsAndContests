#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init(n);
        vector<int> v(n+1);
        map<int, vector<int>> mp;
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            mp[v[i]].push_back(i);
        }
        for(auto &[k, vx] : mp){
            int f = vx[0];
            for(auto x : vx) unite(f, x);
        }
        for(auto &[k, vx]: mp){
            for(int i=1;i<=3;i++){
                if(mp.count(k^i)){
                    unite(mp[k][0], mp[k^i][0]);
                }
            }
        }
        vector<vector<int>> cmp(n+1);
        for(int i=1;i<=n;i++){
            cmp[get(i)].push_back(i);
        }
        vector<int> ans(n+1);
        for(auto vx : cmp){
            if(vx.size() == 0) continue;
            vector<int> curv;
            for(auto x : vx){
                curv.push_back(v[x]);
            }
            sort(curv.begin(), curv.end());
            int p = 0;
            for(auto x : vx){
                ans[x] = curv[p++];
            }
        }

        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }   
}
