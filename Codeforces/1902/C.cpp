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
        map<int,int> mp;
        for(int i=0;i<n;i++){
             cin >> v[i];
             mp[v[i]] = 1;
        }
        if(n == 1){
            cout << "1\n";
            continue;
        }
        int maxi = *max_element(v.begin(), v.end());
        int gc = 0;
        for(int i=0;i<n;i++){
            if(maxi - v[i] != 0){
                gc = gcd(gc, maxi - v[i]);
            }
        }
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum += (maxi-v[i])/gc;
        }
        ll ans = sum;
        int val = maxi;
        while(mp.count(val)){
            val -= gc;
            ans++;
        }
        cout << ans << "\n";
    }
}
