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
    map<int,int> mp;
    vector<int> v(n);
    int ind;
    for(int i=0;i<n;i++){
         cin >> v[i];
         if(v[i] == m) ind = i;
    }
    int cur = 0;
    for(int i=ind;i<n;i++){
        if(v[i] > m) cur++;
        if(v[i] < m) cur--;
        mp[cur]++;
    }
    cur = 0;
    ll ans = 0;
    for(int i=ind;i>=0;i--){
        if(v[i] > m) cur++;
        if(v[i] < m) cur--;
        ans += mp[1-cur] + mp[-cur]; 
    }
    cout << ans << "\n";
}
