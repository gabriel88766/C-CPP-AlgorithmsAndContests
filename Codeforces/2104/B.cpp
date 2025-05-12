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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> ans;
        vector<ll> v(n);
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
        }
        ll mxn = 0;
        for(int i=0;i<n;i++){
            sum -= v[i];
            mxn = max(mxn, v[i]);
            ans.push_back(sum + mxn);
        }
        reverse(ans.begin(), ans.end());
        for(auto &x : ans) cout << x << " ";
        cout << "\n";
    }
}
