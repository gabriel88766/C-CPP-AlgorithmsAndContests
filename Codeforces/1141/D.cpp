#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> a[27], b[27];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s, t;
    cin >> n >> s >> t;
    for(int i=0;i<n;i++){
        if(s[i] == '?') a[26].push_back(i);
        else a[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<n;i++){
        if(t[i] == '?') b[26].push_back(i);
        else b[t[i]-'a'].push_back(i);
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<26;i++){
        int sz = min(a[i].size(), b[i].size());
        for(int j=0;j<sz;j++){
            ans.push_back({a[i].back()+1, b[i].back()+1});
            a[i].pop_back(); b[i].pop_back();
        }
    }
    int bp = 0, sza = a[26].size();
    for(int i=0;i<sza;i++){
        while(b[bp].size() == 0) bp++;
        ans.push_back({a[26].back()+1, b[bp].back()+1});
        a[26].pop_back(); b[bp].pop_back();
    }
    int szb = b[26].size();
    bp = 0;
    for(int i=0;i<szb;i++){
        while(a[bp].size() == 0) bp++;
        ans.push_back({a[bp].back()+1, b[26].back()+1});
        b[26].pop_back(); a[bp].pop_back();
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x.first << " " << x.second << "\n";
}
