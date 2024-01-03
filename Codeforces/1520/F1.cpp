#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int lo = 1, hi = n;
    while(lo != hi){
        int m = lo + (hi - lo)/2;
        auto ans = m - query(1, m);
        if(ans < k) lo = m + 1;
        else hi = m;
    }
    cout << "! " << lo << "\n";
    cout.flush();
}
