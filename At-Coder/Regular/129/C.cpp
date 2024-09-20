#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6;
int dp[N+1], p[N+1];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> s;
    map<int,int> mp;
    for(int j=1;j*j<=N;j++){
        s.push_back((j * (j+1))/2);
        mp[(j * (j+1))/2] = j;
    }
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    int gv = 0;
    for(int i=1;i<=N;i++){
        // if(!(i % 10000)) cout << i << endl;
        for(auto x : s){
            if(i >= x && dp[i] > dp[i-x] + 1){
                p[i] = i-x;
                dp[i] = dp[i-x] + 1;
            }
        }
    }
    vector<int> ans;
    int cur = n;
    while(cur){
        ans.push_back(cur - p[cur]);
        cur = p[cur];
    }
    for(int i=0;i<ans.size();i++){
        if(i != 0) cout << "1";
        for(int j=0;j<mp[ans[i]];j++) cout << "7";
    }
    cout << "\n";
}
