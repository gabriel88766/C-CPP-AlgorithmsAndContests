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
        vector<int> lv(n), rv(n);
        for(int i=0;i<n;i++) cin >> lv[i] >> rv[i];
        int lo = 0, hi = 1e9+1;
        while(lo != hi){
            int mid = lo + (hi - lo) / 2;
            int l = 0, r = 0;
            bool ok = true;
            for(int i=0;i<n;i++){
                //from l to [l-mid, l+mid]
                //from r to [r-mid, r+mid]
                int nl = l - mid, nr = r + mid;
                if(nl > rv[i] || nr < lv[i]){
                    ok = false;
                    break;
                }else{
                    l = max(lv[i], nl);
                    r = min(rv[i], nr);
                }
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
