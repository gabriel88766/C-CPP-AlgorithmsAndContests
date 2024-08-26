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
        ll x = 0, y = 0;
        string s;
        cin >> s;
        ll mnx = 0, mxx = 0, mny = 0, mxy = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'W') y++;
            else if(s[i] == 'S') y--;
            else if(s[i] == 'A') x--;
            else if(s[i] == 'D') x++;
            mnx = min(mnx, x);
            mxx = max(mxx, x);
            mny = min(mny, y);
            mxy = max(mxy, y);
        }
        x = 0, y = 0;
        vector<int> vmnx, vmxx, vmny, vmxy;
        if(x == mnx) vmnx.push_back(-1);
        if(x == mxx) vmxx.push_back(-1);
        if(y == mny) vmny.push_back(-1);
        if(y == mxy) vmxy.push_back(-1);
        for(int i=0;i<s.size();i++){
            if(s[i] == 'W') y++;
            else if(s[i] == 'S') y--;
            else if(s[i] == 'A') x--;
            else if(s[i] == 'D') x++;
            if(x == mnx) vmnx.push_back(i);
            if(x == mxx) vmxx.push_back(i);
            if(y == mny) vmny.push_back(i);
            if(y == mxy) vmxy.push_back(i);
        }
        ll S = (mxx - mnx + 1) * (mxy - mny + 1);
        if(abs(mxx - mnx) > 1 && (vmnx.back() < vmxx[0] || vmnx[0] > vmxx.back())) S = min(S, (mxx - mnx) * (mxy - mny + 1));
        if(abs(mxy - mny) > 1 && (vmny.back() < vmxy[0] || vmny[0] > vmxy.back())) S = min(S, (mxx - mnx + 1) * (mxy - mny));
        cout << S << "\n";
    }
}
