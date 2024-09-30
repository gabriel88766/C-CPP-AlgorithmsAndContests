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
        int n, k;
        cin >> n >> k;
        vector<int> pk = {1};
        if(k != 1){
            while(n/k >= pk.back()){
                pk.push_back(k*pk.back());
            }
        }
        int ans = 0;
        while(n){
            int q = n / pk.back();
            ans += q;
            n -= pk.back()*q;
            pk.pop_back();
        }
        cout << ans << "\n";
    }
}
