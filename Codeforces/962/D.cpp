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
    map<ll, set<int>> mp;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        mp[x].insert(i);
    }
    vector<pair<ll,ll>> vp;
    for(auto &[val, s] : mp){
        if(s.size() % 2){
            vp.push_back({*prev(s.end()), val});
        }
        for(auto it = s.begin(); it != s.end(); ++it){
            if(next(it) == s.end()) break;
            mp[2*val].insert(*next(it));
            ++it;
        }
        s.clear();
    }
    sort(vp.begin(), vp.end());
    cout << vp.size() << "\n";
    for(auto [a, b]: vp) cout << b << " ";
    cout << "\n";
}
