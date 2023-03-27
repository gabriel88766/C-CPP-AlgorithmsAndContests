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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int lo = 0, hi = n-1, mid;
    while(lo != hi){
        mid = lo + (hi - lo)/2;
        bool ok = true;
        int cb = 0, cntb = 1;
        for(int i=mid;i<n;i++){
            if(k-cb >= v[i]) cb += v[i];
            else{
                cntb++;
                cb = v[i];
                if(cntb > m){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) hi = mid;
        else lo = mid+1;
    }
    cout << n - lo << "\n";
}
