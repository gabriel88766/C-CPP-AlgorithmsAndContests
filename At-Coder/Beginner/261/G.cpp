#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cs[26][26];
ll dp1[52][52][26];
ll dp[52][52];
ll aux[52][52][52];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    int k;
    cin >> k;
    vector<pair<string, string>> rul(k);
    for(int i=0;i<k;i++) cin >> rul[i].first >> rul[i].second;

    memset(cs, 63, sizeof(cs));
    memset(dp1, 63, sizeof(dp1));
    for(int i=0;i<26;i++) cs[i][i] = 0;
    for(int i=0;i<k;i++){
        if(rul[i].second.size() == 1){
            int c1 = rul[i].first[0] - 'a';
            int c2 = rul[i].second[0] - 'a';
            cs[c2][c1] = 1;
        }
    }
    //floyd
    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                if(cs[i][k] < INF_LL && cs[k][j] < INF_LL)
                    cs[i][j] = min(cs[i][j], cs[i][k] + cs[k][j]);  

    for(int j=1;j<=m;j++){
        dp1[j][j][t[j]-'a'] = 0;
        for(int l2=0;l2<26;l2++){
            dp1[j][j][l2] = min(dp1[j][j][l2], dp1[j][j][t[j]-'a'] + cs[t[j]-'a'][l2]);
        }
    } 
    
    for(int i=m;i>=1;i--){
        for(int y=i-1;y<=m;y++){
            for(int x=0;x<k;x++){
                for(int z=0;z<=rul[x].second.size();z++){
                    aux[x][y][z] = INF_LL;
                }
            }
        }
        for(int x=0;x<k;x++) aux[x][i-1][0] = 0;
        for(int y=i;y<=m;y++){
            for(int x=0;x<k;x++){
                for(int sz=0;sz<rul[x].second.size();sz++){
                    for(int z=i-1;z<y;z++){
                        aux[x][y][sz+1] = min(aux[x][y][sz+1], aux[x][z][sz] + dp1[z+1][y][rul[x].second[sz]-'a']);
                    }
                }
            }
            for(int x=0;x<k;x++){
                dp1[i][y][rul[x].first[0]-'a'] = min(aux[x][y][rul[x].second.size()] + 1, dp1[i][y][rul[x].first[0]-'a']);
            }
            for(int l1=0;l1<26;l1++){
                for(int l2=0;l2<26;l2++){
                    dp1[i][y][l2] = min(dp1[i][y][l2], dp1[i][y][l1] + cs[l1][l2]);
                }
            }
            for(int x=0;x<k;x++){
                aux[x][y][1] = min(aux[x][y][1], dp1[i][y][rul[x].second[0]-'a']);
            }
        }
    }


    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j] = -1;
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j] == -1) continue;
            for(int k=j+1;k<=m;k++){
                //make t.substr(j+1, k-j); -> s.substr(i+1, 1) if possible
                ll cost;
                if(dp1[j+1][k][s[i+1]-'a'] != INF_LL) cost = dp1[j+1][k][s[i+1]-'a'];
                else continue;
                if(dp[i+1][k] == -1) dp[i+1][k] = dp[i][j] + cost;
                else dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost);
         
            }
        }
    }
    cout << dp[n][m] << "\n";
}
