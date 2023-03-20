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
        vector<ll> ps(n+1, 0);
        for(int i=1;i<=n;i++){
             cin >> ps[i];
             ps[i] += ps[i-1];
        }
        int lo = 1, hi = n, mid;
        while(lo != hi){
            mid = (lo+hi)/2;
            ll exp = (ps[mid]-ps[lo-1]+1);
            cout << "? " << mid-lo+1 << " ";
            for(int i=lo;i<=mid;i++) cout << i << " ";
            cout << "\n";
            cout.flush();
            ll ans;
            cin >> ans;
            if(ans == exp) hi = mid;
            else lo = mid + 1;
        }
        cout << "! " << lo << "\n";
        cout.flush();
    }
}
