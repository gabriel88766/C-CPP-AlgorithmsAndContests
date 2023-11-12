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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> fs(n+1, 0);
    int rt;
    bool ok = true;
    for(int i=1;i<n;i++){
        cin >> v[i];
        if(!fs[v[i]]) fs[v[i]] = i;
        if(i == 1) rt = v[i];
    }
    map<int,int> mp;
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        if(!fs[i]){
            mp[i] = i;
        }
    }
    for(int i=n-1;i>=1;i--){
        int u = v[i];
        if(!mp.size()){
            ok = false;
            break;
        }
        auto p = *mp.begin();
        mp.erase(mp.begin());
        ans.push_back({u, p.first});
        if(fs[u] == i) mp[u] = max(mp[u], max(u, p.second));
        
    }
    if(ok){
        cout << rt << "\n";
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout << x.first << " " << x.second << "\n";
    }else cout << "-1\n";
    
}
