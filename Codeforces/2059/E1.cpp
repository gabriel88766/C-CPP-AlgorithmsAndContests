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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        auto b = a;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> b[i][j];
            }
        }
        int ans = 0;
        deque<int> nums;
        for(int i=0;i<n;i++){
            int x = -1;
            for(int j=0;j<m;j++){
                if(a[i][0] == b[i][j]){
                    x = j;
                }
            }
            bool okp = true;
            for(int j=0;x+j<m;j++){
                if(a[i][j] != b[i][x+j]) okp = false;
            }
            if(nums.size() && okp){
                if(nums.size() <= x){
                    int p = 0;
                    for(int j=0;j<m;j++){
                        if(p < nums.size() && nums[p] == b[i][j]) p++;
                    }
                    if(p == nums.size()){
                        ans += x - p;
                        nums.clear();
                        for(int j=m-x;j<m;j++) nums.push_back(a[i][j]);
                        continue;
                    }
                }
            }else if(okp){
                ans += x;
                for(int j=m-x;j<=m-1;j++) nums.push_back(a[i][j]);
                continue;
            }
            //so take from nums
            int p = 0;
            for(int j=0;j<m;j++){
                if(p < nums.size() && nums[p] == b[i][j]) p++;
            }
            ans += m - p;
            while(p--) nums.pop_front();
            for(int j=0;j<m;j++) nums.push_back(a[i][j]);
        }
        cout << ans << "\n";
    }
}
