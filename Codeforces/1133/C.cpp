#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    map<int,int> mp;
    set<int> nums;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        nums.insert(aux);
        mp[aux]++;
    }
    int ans = 0;
    for(auto u : nums){
        int cur = 0;
        cur += mp[u] + mp[u+1] + mp[u+2] + mp[u+3] + mp[u+4] + mp[u+5];
        ans = max(ans, cur);
    }
    cout << ans;
}
