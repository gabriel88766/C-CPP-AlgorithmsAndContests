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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int lo = 1, hi = 1e9;
    while(lo != hi){
        int mid = lo + (hi - lo) / 2;
        ll tt = 0;
        for(auto x : v){
            tt += (x + mid - 1)/ mid - 1;
        }
        // cout << mid << " " << tt << "\n";
        if(tt <= k) hi = mid;
        else lo = mid + 1;
    } 
    cout << lo << "\n";
}
