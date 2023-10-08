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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dodd(n, 0), deven(n, 0);
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            int p1 = i - j;
            int p2 = i + j;
            if(p1 >= 0 && p2 < n && s[p1] == s[p2]) dodd[i]++;
            else break;
        }
        for(int j=0;j<n;j++){
            int p1 = i - j - 1;
            int p2 = i + j;
            if(p1 >= 0 && p2 < n && s[p1] == s[p2]) deven[i]++;
            else break;
        }
    }
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int j=1;j<=n;j++){ //sz
        for(int i=0;i<=n-j;i++){ //begin
            if(j == 1){
                dp[i][j] = 1; 
            }else{
                dp[i][j] = dp[i+1][j-1] + dp[i][j-1] - dp[i+1][j-2];
                int sz = j/2;
                int mid = i + sz;
                if(j % 2 == 1 && dodd[mid] >= sz) dp[i][j]++;
                else if(j % 2 == 0 && deven[mid] >= sz) dp[i][j]++;
            }
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        cout << dp[a-1][b-a+1] << "\n";
    }
}
