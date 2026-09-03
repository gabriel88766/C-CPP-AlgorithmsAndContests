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
    map<pair<int, int>, int> mp;
    vector<int> cnt(n+1);
    int a, b;
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        if(a > b) swap(a, b); //a < b
        cnt[a]++;
        cnt[b]++;
        mp[{a, b}]++;
    }
    set<pair<int, int>> st;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int ca = i;
        int cb = a;
        if(ca > cb) swap(ca, cb);
        if(ca != cb && cnt[ca] + cnt[cb] - mp[{ca, cb}] == m) st.insert({ca, cb});
        ca = i;
        cb = b;
        if(ca > cb) swap(ca, cb);
        if(ca != cb && cnt[ca] + cnt[cb] - mp[{ca, cb}] == m) st.insert({ca, cb});
    }
    cout << st.size() << "\n";
}
