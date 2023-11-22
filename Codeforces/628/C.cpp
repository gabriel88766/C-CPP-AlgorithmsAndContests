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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans;
    for(int i=0;i<n;i++){
        if(k){
            int d1 = s[i] - 'a';
            int d2 = 'z' - s[i];
            if(k >= max(d1, d2)){
                if(d1 > d2){
                    k -= d1;
                    ans += 'a';
                }else{
                    k -= d2;
                    ans += 'z';
                }
            }else{
                for(int j=0;j<26;j++){
                    char c = j + 'a';
                    if(abs(c - s[i]) == k){
                        ans += c;
                        k = 0;
                        break;
                    }
                }
            }
        }else{
            ans += s[i];
        }
    }
    if(!k) cout << ans << "\n";
    else cout << "-1\n";
}
