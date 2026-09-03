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
        vector<ll> v(n);
        ll s = 0;
        multiset<ll> ms;
        for(int i=0;i<n;i++){
            cin >> v[i];
            ms.insert(v[i]);
            s += v[i];
        }
        
        if(s >= 1){
            s = 0;
            while(ms.size()){
                auto it = ms.upper_bound(-s);
                assert(it != ms.end());
                s += *it;
                ms.erase(it);
                cout << s << " ";
            }
            cout << "\n";
        }else cout << "-1\n";
    }
}
