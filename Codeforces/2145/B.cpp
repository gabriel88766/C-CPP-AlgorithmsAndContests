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
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ch = 0, ct = 0, cx = 0;
        if(k == n){
            for(int i=0;i<n;i++) cout << "-";
            cout << "\n";
        }else{
            for(auto c : s){
                if(c == '0') ch++;
                if(c == '1') ct++;
                if(c == '2') cx++;
            }
            string ans(n, '+');
            for(int i=0;i<ct+cx;i++){
                if(i < ct) ans[i] = '-';
                else ans[i] = '?';
            }
            reverse(ans.begin(), ans.end());
            for(int i=0;i<ch+cx;i++){
                if(i < ch) ans[i] = '-';
                else ans[i] = '?';
            }
            cout << ans << "\n";
        }
    }
}
