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
    vector<tuple<int, int, int>> vx;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        vx.push_back({a, b, i});
    }
    sort(vx.begin(), vx.end(), greater<tuple<int, int, int>>());
    vector<int> ans;
    int mn = INF_INT;
    for(auto [a, b, c] : vx){
        if(b < mn){
            mn = b;
            ans.push_back(c);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
