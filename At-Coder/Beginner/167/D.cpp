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
    ll n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int ans = 1;
    if(k <= n){
        for(int i=0;i<k;i++) ans = v[ans];
        cout << ans << "\n";
    }else{
        for(int i=1;i<=n;i++) ans = v[ans];
        k -= n;
        vector<int> prm;
        int cur = ans;
        prm.push_back(cur);
        while(v[prm.back()] != ans){
            prm.push_back(v[prm.back()]);
        }
        cout << prm[k % prm.size()] << "\n";
    }
    
}   
