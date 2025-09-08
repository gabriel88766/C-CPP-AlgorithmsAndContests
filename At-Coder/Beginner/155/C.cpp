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
    map<string, int> mp;
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        mp[x]++;
    }
    int mx = 0;
    vector<string> ans;
    for(auto [str, k] : mp) mx = max(mx, k);
    for(auto [str, k] : mp){
        if(mx == k) ans.push_back(str);
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << "\n";
}
