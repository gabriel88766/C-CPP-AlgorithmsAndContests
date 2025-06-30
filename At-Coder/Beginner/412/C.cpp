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
        int d1, dn;
        cin >> d1;
        vector<int> v;
        for(int i=2;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        cin >> dn;
        int ans = 2;
        sort(v.begin(), v.end());
        while(d1 * 2 < dn){
            int nd1 = d1;
            for(auto x : v){
                if(x >= d1 && x <= 2*d1) nd1 = max(nd1, x);
            }
            if(nd1 == d1){
                ans = -1;
                break;
            }else{
                ans++;
                d1 = nd1;
            }
        }
        cout << ans << "\n";
    }
}
