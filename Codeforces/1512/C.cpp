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
        int a, b;
        string s;
        cin >> a >> b >> s;
        int n = s.size();
        bool ok = true;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                if(s[n-i-1] == '0') ok = false;
                else s[n-i-1] = '1';
            }else if(s[i] == '0'){
                if(s[n-i-1] == '1') ok = false;
                else s[n-i-1] = '0';
            }
        }
        for(int i=0;i<n;i++){
            if(s[i] == '0') a--;
            else if(s[i] == '1') b--;
        }
        if(a < 0 || b < 0 || !ok){
            cout << "-1\n";
            continue;
        }
        if(n % 2){
            if(s[n/2] == '?'){
                if(a % 2){
                    s[n/2] = '0';
                    a--;
                }else{
                    s[n/2] = '1';
                    b--;
                }
            }
        }
        if(a % 2 || b % 2) cout << "-1\n";
        else{
            for(int i=0;i<n/2;i++){
                if(s[i] == '?'){
                    if(a){
                        s[i] = s[n-i-1] = '0';
                        a -= 2;
                    }else{
                        s[i] = s[n-i-1] = '1';
                    }
                }
            }
            cout << s << "\n";
        }
        
    }
}
