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
        int mn, mx;
        bool ok = true;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(i == 0){
                mn = x;
                mx = x;
            }else{
                mn = max(x, mn - k + 1);
                mx = min(x + k - 1, mx + k - 1);
                if(mn > mx) ok = false; 
            }
            if(i == n-1 && mn != x) ok = false;
        }   
        
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
