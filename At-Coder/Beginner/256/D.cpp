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
    vector<pair<int, int>> v(n), ans;
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int l = v[0].first, r = v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first > r){
            ans.push_back({l, r});
            l = v[i].first, r = v[i].second;
        }else r = max(r, v[i].second);
    }
    ans.push_back({l, r});
    for(auto &[a, b] : ans) cout << a << " " << b << "\n";
}
