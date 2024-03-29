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
    vector<ll> ans(n+1, 0);
    set<int> row;
    set<pair<int,int>> back;
    for(int i=1;i<=n;i++) row.insert(i);
    for(int i=0;i<m;i++){
        ll t, w, s;
        cin >> t >> w >> s;
        while(back.size() && back.begin()->first <= t){
            row.insert(back.begin()->second);
            back.erase(back.begin());
        }
        if(!row.size()) continue;
        int f = *row.begin();
        row.erase(row.begin());
        ans[f] += w;
        back.insert({t+s, f});
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
}
