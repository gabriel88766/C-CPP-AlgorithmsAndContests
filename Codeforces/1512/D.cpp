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
        vector<int> v(n+2);
        ll sum = 0;
        for(int i=0;i<n+2;i++){
             cin >> v[i];
             sum += v[i];
        }
        sort(v.begin(), v.end());
        int ind = -1;
        for(int i=0;i<n+2;i++){
            //what if v[i] = x
            ll cur = sum - v[i];
            if(cur % 2) continue;
            auto it = lower_bound(v.begin(), v.end(), cur/2);
            if(it-v.begin() == i) ++it;
            if(it != v.end() && *it == (cur/2)){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            cout << "-1\n";
            continue;
        }
        vector<int> ans;
        for(int i=0;i<n+2;i++){
            if(i != ind) ans.push_back(v[i]);
        }
        ans.pop_back();
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
