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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> eq(26);
    for(int i=0;i<s.size();i++){
        eq[s[i]-'a'].push_back(i);
    }
    bool ok = true;
    for(int i=0;i<26;i++){
        vector<bool> hl(26, false);
        int cnt = 0;
        for(auto &x : eq[i]){
            if(!hl[t[x]-'a']){
                cnt++;
                hl[t[x]-'a'] = 1;
            }
        }
        if(cnt >= 2) ok = false;
    }
    if(!ok){
        cout << "No\n";
        return 0;
    }
    vector<int> adj(26, -1);
    for(int i=0;i<26;i++){
        if(eq[i].size()) adj[i] = t[eq[i][0]] - 'a';
    }
    for(int i=0;i<26;i++){
        int cur = 0;
        for(int j=0;j<26;j++){
            if(adj[j] == i) cur++;
        }
        if(cur > 1) ok = false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
