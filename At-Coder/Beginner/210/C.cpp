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
    map<int, int> mp;
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        mp[v[i]]++;
        if(i >= k){
            ans = max(ans, (int)mp.size());
            mp[v[i-k+1]]--;
            if(mp[v[i-k+1]] == 0) mp.erase(v[i-k+1]);
        }
    }
    cout << ans << "\n";
}
