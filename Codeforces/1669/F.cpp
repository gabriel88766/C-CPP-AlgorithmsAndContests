#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int ans = 0, a=0, b=0, bp = 0, ep = n-1;
        for(int i=0;i<n;i++) cin >> v[i];
        while(ep >= bp){
            if(a == b){
                ans = n-1-ep + bp;
                a += v[bp++];
            }else if(a < b) a += v[bp++];
            else b += v[ep--];
        }
        if(a == b) ans = n;
        cout << ans << "\n";
    }
}
