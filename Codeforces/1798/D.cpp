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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll dif = v[n-1] - v[0];
        vector<ll> ans;
        ll sum = 0, bp = 0, ep = n-1, maxsum = 0;
        while(ep >= bp){
            if(sum <= 0) ans.push_back(v[ep--]);
            else ans.push_back(v[bp++]);
            sum += ans.back();
            maxsum = max(maxsum, abs(sum));
        }
        if(maxsum < dif){
            cout << "Yes\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else{
            cout << "No\n";
        }
    }
}
