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
        ll S = 0;
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            S += v[i];
        }
        if((2*S) % n){
            cout << "0\n";
            continue;
        }
        ll goal = (2*S) / n;
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i=0;i<n-1;i++){
            //binsearch because two pointers will gimme WA
            ll curn = goal - v[i];
            if(curn < v[i]) break;
            ans += lower_bound(v.begin()+i+1, v.end(), curn + 1) - lower_bound(v.begin()+i+1, v.end(), curn);
        }
        cout << ans << "\n";
    }
}
