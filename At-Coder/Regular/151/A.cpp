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
    int n;
    string s, t;
    cin >> n >> s >> t;
    int cnt = 0;
    for(int i=0;i<n;i++) if(s[i] != t[i]) cnt++;
    if(cnt % 2)cout << "-1\n";
    else{
        string ans;
        for(int i=0;i<n;i++) ans += '0';
        int h1 = 0, h2 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') h1++;
            if(t[i] == '1') h2++;
        }
        int ch = abs(h1 - h2)/2;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        if(h1 > h2){
            //change first
            for(int i=0;i<n;i++){
                if(s[i] == '1' && t[i] == '0' && ch){
                    ans[i] = '1';
                    ch--;
                }
            }
        }else if(h2 > h1){
            for(int i=0;i<n;i++){
                if(t[i] == '1' && s[i] == '0' && ch){
                    ans[i] = '1';
                    ch--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}
