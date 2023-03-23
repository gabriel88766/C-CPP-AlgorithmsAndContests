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
        int n, k;
        cin >> n >> k;
        vector<int> ans;
        int bp = 0, cnt = 0, sum = 0;
        while(cnt < k){
            if(cnt + bp + 1 <= k){
                ans.push_back(2);
                sum += 2;
                cnt += bp + 1;
                bp++;
            }else{
                int nint = -sum-1;
                while(cnt != k) nint+=2, cnt++;
                ans.push_back(nint);
            }
        }
        while(ans.size() != n) ans.push_back(-1000);
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
