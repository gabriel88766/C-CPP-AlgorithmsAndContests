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
        string s;
        cin >> s;
        int p = 0, n = 0, q = 0;
        for(auto c : s){
            if(c == '(') p++;
            else if(c == ')') n++;
            else q++;
        }
        int np, nq;
        for(int i=0;i<=q;i++){
            if(p + i == q-i+n){
                np = i;
                nq = q-i;
                break;
            }
        }
        if(np == 0 || nq == 0) cout << "YES\n";
        else{
            //try the first np-1 as ( and the last as )
            string tst = s;
            bool fq = false;
            bool ok = true;
            int cnt = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] == '?'){
                    if(np > 1){
                        np--;
                        s[i] = '(';
                    }else if(np == 1){
                        if(fq){
                            np--;
                            s[i] = '(';
                        }else{
                            fq = true;
                            nq--;
                            s[i] = ')';
                        }
                    }else{
                        nq--;
                        s[i] = ')';
                    }
                }
                if(s[i] == '(') cnt++;
                else cnt--;
                if(cnt < 0) ok = false;
            }
            if(ok) cout << "NO\n";
            else cout << "YES\n";
            
        }
    }
}
