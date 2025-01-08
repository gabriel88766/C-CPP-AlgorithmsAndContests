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
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

    for(int i=0;i<nums.size();i++) dp[i][i] = nums[i];
    for(int sz=2;sz<=nums.size();sz++){
        for(int j=0;j<nums.size();j++){
            int z = j + sz - 1;
            if(z >= nums.size()) break;
            dp[j][z] = dp[j][z-1] ^ dp[j+1][z];
        }
    }
    for(int sz=2;sz<=nums.size();sz++){
        for(int j=0;j<nums.size();j++){
            int z = j + sz - 1;
            if(z >= nums.size()) break;
            dp[j][z] = max(dp[j][z], max(dp[j][z-1], dp[j+1][z]));
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << dp[l][r] << "\n";
    }
}
