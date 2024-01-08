#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int atoi(string num){
    int ans = 0;
    for(int i=0;i<num.size();i++){
        ans *= 10;
        ans += num[i] - '0';
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        string l, r;
        cin >> l >> r;
        while(l.size() != r.size()) l = "0" + l;

        ll ans = 0;
        for(int i = 1;i<=l.size();i++){
            int rl = atoi(l.substr(0, i));
            int rr = atoi(r.substr(0, i));
            ans += rr-rl;
        }
        cout << ans << "\n";
    }
}
