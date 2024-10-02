#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 20;
map<int, vector<int>> mp[N];
int mv[N], val[N];
int dp[2][1 << N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<string> str(n);
    for(int i=0;i<n;i++) cin >> str[i];
    for(int i=0;i<n;i++){
        int cur = 0;
        int j = 0;
        for(auto c : str[i]){
            if(c == '(') cur++;
            else cur--;
            mv[i] = min(mv[i], cur);
            mp[i][cur].push_back(j++);
        }
        val[i] = cur;
    }
    for(int i=0;i<(1 << n);i++){
        dp[0][i] = dp[1][i] = -INF_INT;
    }
    int ans = 0;
    dp[1][0] = 0;
    for(int i=0;i<(1 << n);i++){
        ans = max(ans, dp[0][i]);
        ans = max(ans, dp[1][i]);
        if(dp[1][i] < 0) continue; //can't keep goin
        int vm = 0;
        for(int j=0;j<n;j++){
            if(i & (1 << j)) vm += val[j];
        }
        for(int j=0;j<n;j++){
            if(!(i & (1 << j))){
                int m = i | (1 << j);
                int val = dp[1][i];
                int r = str[j].size();
                if(vm + mv[j] < 0){
                    int aux = -vm - 1;
                    r = mp[j][aux][0];
                }
                if(vm + mv[j] <= 0){
                    auto &av = mp[j][-vm];
                    val += lower_bound(av.begin(), av.end(), r) - lower_bound(av.begin(), av.end(), 0);
                }


                if(vm + mv[j] >= 0){
                    dp[1][m] = max(dp[1][m], val);
                }else{
                    dp[0][m] = max(dp[0][m], val);
                }
            }
        }
    }
    cout << ans << "\n";
    

}
