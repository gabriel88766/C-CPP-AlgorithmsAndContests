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
        int c0 = 0, c1 = 0;
        string s;
        cin >> s;
        for(auto &c : s){
            if(c == '1') c1++;
            else c0++;
        }
        int mx = max(c1, c0);
        int mn = min(c1, c0);
        int mnk = (mx - mn)/2;
        int mxk = mn/2 + mx/2;
        if(mnk <= k){
            if(mnk % 2 == k % 2 && mxk >= k) cout << "YES\n";
            else cout << "NO\n";
        }else cout << "NO\n";
    }
}   
