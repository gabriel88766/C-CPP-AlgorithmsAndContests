#include<bits/stdc++.h>

#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))
typedef long long ll;
using namespace std;

const int N = 2e5+3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int a[N], b[N];
int dp[N][2];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, c;
    cin >> n >> c;
    for(int i=2;i<=n;i++) cin >> a[i];
    for(int i=2;i<=n;i++) cin >> b[i];
    dp[1][0] = 0;
    dp[1][1] = INF;
    for(int i=2;i<=n;i++){
        dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + a[i];
        dp[i][1] = min(dp[i-1][0] + c + b[i], dp[i-1][1] + b[i]);
    }
    for(int i=1;i<=n;i++){
        cout << min(dp[i][0],dp[i][1]) << " ";
    }
}


 