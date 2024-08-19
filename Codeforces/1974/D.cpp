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
        int cn = 0, cs = 0, ce = 0, cw = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'W') cw++;
            else if(s[i] == 'E') ce++;
            else if(s[i] == 'S') cs++;
            else cn++;
        }
        if(abs(cn-cs) % 2 || abs(ce - cw) % 2) cout << "NO\n";
        else{
            if(n == 2){
                if(abs(cn - cs) == 0 && abs(ce - cw) == 0) cout << "NO\n";
                else cout << "RH\n";
            }else{
                vector<char> ans(n);
                int ccs = 0, ccn = 0, ccw = 0, cce = 0;
                for(int i=0;i<n;i++){
                    if(s[i] == 'S'){
                        ans[i] = ccs % 2 ? 'R' : 'H';
                        ccs++;
                    }
                    if(s[i] == 'N'){
                        ans[i] = ccn % 2 ? 'R' : 'H';
                        ccn++;
                    }
                    if(s[i] == 'W'){
                        ans[i] = ccw % 2 ? 'H' : 'R';
                        ccw++;
                    }
                    if(s[i] == 'E'){
                        ans[i] = cce % 2 ? 'H' : 'R';
                        cce++;
                    }
                }
                for(int i=0;i<n;i++){
                    cout << ans[i];
                }
                cout << "\n";
            }
        }
    }
}
