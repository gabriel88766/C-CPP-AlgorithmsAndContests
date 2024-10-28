#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
ll x;
vector<ll> nums[30];
int solve(int cur, ll prod){
    if(cur == n){
        int ans = 0;
        for(int i=0;i<nums[cur].size();i++){
            if((x / nums[cur][i] >= prod) && prod * nums[cur][i] == x) ans++;
        }
        return ans;
    }else{
        int ans = 0;
        for(int i=0;i<nums[cur].size();i++){
            if((x / nums[cur][i] >= prod)){
                ans += solve(cur+1, prod * nums[cur][i]);
            }
        }
        return ans;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        int len;
        cin >> len;
        for(int j=0;j<len;j++){
            int x;
            cin >> x;
            nums[i].push_back(x);
        }
    }
    cout << solve(1, 1) << "\n";
}
