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
        string s;
        cin >> n >> s;
        string revs = s;
        reverse(revs.begin(), revs.end());
        bool h1 = false;
        for(auto c : s) if(c == '1') h1 = true;
        if(h1){
            //cost n, n+1, n+2, n+3;
            int c1 = 0, c0 = 0;
            for(auto c : s){
                if(c == '1') c1++;
                else c0++;
            }
            if(c1 >= c0) cout << n << "\n";
            else{
                //cost n+1, n+2, n+3; (example n+3 00000001000000000)
                //n+1 => there is some [l, r] = 0 such that [1, l-1] + [r+1, n] is positive (either [1, l-1] or [r+1, n] must be)
                bool ok1 = false;
                int cur = 0;
                for(auto c : s){
                    if(c == '1') cur++;
                    else cur--;
                    if(cur >= 1) ok1 = true;
                }
                cur = 0;
                for(auto c : revs){
                    if(c == '1') cur++;
                    else cur--;
                    if(cur >= 1) ok1 = true;
                }
                if(ok1) cout << n+1 << "\n";
                else{
                    bool ok2 = false;
                    for(int i=1;i<n;i++){
                        if(s[i] == '1' && s[i-1] == '1') ok2 = true;
                    }
                    if(ok2) cout << n+2 << "\n";
                    else cout << n+3 << "\n";
                }
            }
        }else cout << "-1\n";
    }
}   
