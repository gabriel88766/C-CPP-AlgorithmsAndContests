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
    int n, m;
    cin >> n >> m;
    vector<string> tk;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        tk.push_back(s);
    }
    vector<string> val(m+1);
    for(int i=1;i<=m;i++){
        cin >> val[i];
    }
    int wild = 0;
    map<string, int> mp;
    for(int i=0;i<=m;i++){
        int x;
        cin >> x;
        if(i == 0) wild = x;
        else mp[val[i]] = x;
    }
    int ans = 0;
    for(auto &x : tk){
        if(mp.count(x)) ans += mp[x];
        else ans += wild;
    }
    cout << ans << "\n";
}
