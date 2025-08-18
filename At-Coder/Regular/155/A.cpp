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
    //freopen("in", "r", stdin) ; //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        string s;
        cin >> n >> k >> s;
        if(k <= n){
            string x;
            for(int j=k-1;j>=0;j--) x += s[j];
            x += s;
            string rev = x;
            reverse(rev.begin(), rev.end());
            if(rev == x) cout << "Yes\n";
            else cout << "No\n";
        }else{
            ll g = gcd(k + n, n);
            ll dv = (n + k) / g;

            if(dv % 2){
                string x = s.substr(0, g);
                string rev = x;
                reverse(rev.begin(), rev.end());
                bool ok = true;
                for(int i=0;i<n;i+=g){
                    if((i/g) % 2){
                        if(s.substr(i, g) != rev) ok = false;
                    }else{
                        if(s.substr(i, g) != x) ok = false;
                    }
                }
                if(rev == x && ok) cout << "Yes\n";
                else cout << "No\n";
            }else{
                string x = s.substr(0, g);
                string rev = x;
                reverse(rev.begin(), rev.end());
                bool ok = true;
                for(int i=0;i<n;i+=g){
                    if((i/g) % 2){
                        if(s.substr(i, g) != rev) ok = false;
                    }else{
                        if(s.substr(i, g) != x) ok = false;
                    }
                }
                if(ok) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
}
