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
        char c = '.';
        int cnt = 0;
        vector<bool> okc(26, false);
        for(auto cc : s){
            if(cc != c){
                if(c != '.'){
                    if(cnt % 2){
                        okc[c-'a'] = true;
                    }
                }
                cnt = 1;
                c = cc;
            }else cnt++;
        }
        if(cnt % 2) okc[c-'a'] = true;
        for(int i=0;i<26;i++) if(okc[i]) cout << (char)('a' + i);
        cout << "\n";
    }
}
