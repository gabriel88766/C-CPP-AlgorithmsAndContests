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
        string s, x, y;
        cin >> s >> x >> y;
        //s = kt or t = ks; or x == y;
        if(x == y) cout << "Yes\n";
        else{
            int n = s.size();
            vector<ll> p;
            bool cann = false;
            for(int i=1;i<=n;i++){
                if(!(n % i)){
                    bool ok = true;
                    int d = n/i;
                    string x = s.substr(0, d);
                    for(int k=d;k<n;k+=d){
                        if(x != s.substr(k, d)) ok = false;
                    }
                    if(ok) p.push_back(i);
                    if(ok && i == n) cann = true;
                }
            }
            ll t1 = 0, s1 = 0, t2 = 0, s2 = 0;
            for(int i=0;i<x.size();i++){
                if(x[i] == '1') t1++;
                else s1++;
            }
            for(int i=0;i<y.size();i++){
                if(y[i] == '1') t2++;
                else s2++;
            }
            bool ok = false;
            if(s1 == s2) ok = true; // T empty
            
            ll den = s1-s2;
            ll num = t2-t1;
            if(den < 0 && num < 0){
                den = abs(den);
                num = abs(num);
            }
            if(den < 0 || num < 0);
            else if(den > 0 && num > 0){
                ll g = gcd(den, num);
                den /= g;
                num /= g;
                for(auto x : p){
                    if(!(x % num)) ok = true;
                }
            }
            
            if(ok) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
