#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


char mirror[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
bool ism[26];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int j = 0; j < 11; j++ ){
        ism[mirror[j] - 'A'] = true;
    }
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<bool>> dp1(n, vector<bool>(n));
        vector<vector<bool>> dp2(n, vector<bool>(n));
        for(int i=0;i<n;i++){
            dp1[i][i] = true;
            if(i){
                if(s[i-1] == s[i]) dp1[i-1][i] = true;
            }
            if(ism[s[i]-'A']) dp2[i][i] = true;
        }
        for(int l = 3; l <= n; l++){
            for(int j=0;j<n-l+1;j++){
                if(dp1[j+1][j+l-2]){
                    if(s[j] == s[j+l-1]){
                        dp1[j][j+l-1] = true;
                    }else{
                        dp1[j][j+l-1] = false;
                    }
                }else dp1[j][j+l-1] = false;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dp2[i][j-1]){
                    if(ism[s[j]-'A']) dp2[i][j] = true;
                    else dp2[i][j] = false;
                }else dp2[i][j] = false;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp1[i][j] && dp2[i][j]){
                    ans = max(ans, j-i+1);
                }
            }
        }
        if(ans == n) cout << "yes\n";
        else cout << "no\n";
        
    }
}
