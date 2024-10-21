#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int pi[5005]; //Lenght of greatest prefix also suffix of substr (0, i) 

//Knuth-Morris-Pratt
void kmp_pre(string s){
    pi[0] = 0;
    for(int i=1;i<s.size();i++){
        int j = pi[i-1];
        while(j && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s, t;
    cin >> s >> t;
    if(s.size() < t.size()) cout << "0\n";
    else{
        //t.size() is at most 3000;
        vector<vector<int>> tr(t.size()+1, vector<int>(26));
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -INF_INT));
        kmp_pre(t);
         //need to preprocess all transitions.
        for(int i=0;i<=t.size();i++){
            for(int u=0;u<26;u++){
                char let = 'a' + u;
                int cur = i;
                while(cur && (cur == t.size() || t[cur] != let)) cur = pi[cur-1];
                if(t[cur] == let) tr[i][u] = cur+1;
                else tr[i][u] = 0; 
            }
        }
        dp[0][0] = 0;
        int n = s.size();
        int m = t.size();
        s = " " + s;
        t = " " + t;
       
        //solved;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(dp[i-1][j] != -INF_INT){ //possible
                    if(s[i] == '?'){
                        for(int u=0;u<26;u++){
                            if(tr[j][u] == m){
                                dp[i][tr[j][u]] = max(dp[i][tr[j][u]], dp[i-1][j] + 1);
                            }else{
                                dp[i][tr[j][u]] = max(dp[i][tr[j][u]], dp[i-1][j]);
                            }
                        }
                    }else{
                        if(tr[j][s[i]-'a'] == m) dp[i][tr[j][s[i]-'a']] = max(dp[i][tr[j][s[i]-'a']], dp[i-1][j] + 1);
                        else dp[i][tr[j][s[i]-'a']] = max(dp[i][tr[j][s[i]-'a']], dp[i-1][j]);
                    }
                }
            }
        }
        int ans = 0;
        for(int j=0;j<=m;j++) ans = max(ans, dp[n][j]);
        cout << ans << "\n";
    }
}
