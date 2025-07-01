#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int gr[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=2;i<N;i++){
        if(!gr[i]){
            for(int j=i;j<N;j+=i) gr[j] = i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> nums(n+1);
        nums[1].push_back(1);
        for(int i=2;i<=n;i++){
            nums[gr[i]].push_back(i);
        }
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            if(nums[i].size()){
                for(int j=0;j<nums[i].size();j++){
                    ans[nums[i][j]] = nums[i][(j+1) % nums[i].size()];
                }
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
