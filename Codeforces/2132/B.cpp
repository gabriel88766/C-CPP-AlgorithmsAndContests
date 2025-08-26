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
    vector<ll> nums;
    ll cur = 1;
    for(int i=1;i<18;i++){
        cur *= 10;
        nums.push_back(cur + 1);
    }
    reverse(nums.begin(), nums.end());
    int t;
    cin >> t;
    while(t--){
        vector<ll> ans;
        ll n;
        cin >> n;
        for(auto x : nums){
            if(n % x == 0) ans.push_back(n / x);
        }
        cout << ans.size() << "\n";
        if(ans.size()){
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }

    }
}
