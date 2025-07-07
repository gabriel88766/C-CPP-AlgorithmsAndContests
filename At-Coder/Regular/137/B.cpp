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
    int cnt = 0, n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        s += c;
    }
    for(auto x : s){
        if(x == '1') cnt++;
    }
    int mn = 0, mx = 0;
    int mxans = cnt, mnans = cnt;
    int cur = 0;
    for(auto x : s){
        if(x == '1') cur++;
        else cur--;
        mn = min(cur, mn);
        mx = max(cur, mx);
        mxans = max(mxans, cnt + mx - cur);
        mnans = min(mnans, cnt + mn - cur);
    }
    cout << mxans - mnans + 1 << "\n";
}
