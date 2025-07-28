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
    ll a, n, ans = 0;
    cin >> a >> n;
    for(int i=1;i<=12;i++){
        int sh = (i + 1) / 2;
        string bgs = string(sh, '0');
        bgs[0] = '1';
        int bg = stoi(bgs); 
        for(int j=bg;j < 10*bg; j++){
            string cn = to_string(j);
            string rev = cn;
            if(i % 2) rev.pop_back();
            reverse(rev.begin(), rev.end());
            cn += rev;
            ll rn = stol(cn);
            if(rn > n) continue;
            //check if it is palin base a
            string ba;
            while(rn){
                ba += '0' + (rn % a);
                rn /= a;
            }
            string bar = ba;
            reverse(bar.begin(), bar.end());
            if(ba == bar) ans += stol(cn);
        }
    }
    cout << ans << "\n";
}
