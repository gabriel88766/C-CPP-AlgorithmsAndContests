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
        int mb = 0;
        for(int i=0;i<=22;i++) if(k & (1 << i)) mb = i;
        vector<int> ans;
        for(int i=0;i<20;i++){
            if(i != mb) ans.push_back(1 << i);
        }
        int num = k - (1 << mb);
        if(num) ans.push_back(num);
        ans.push_back(k + 1);
        ans.push_back((1 << (mb+1)) + k);
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto x: ans) cout << x << " ";
        cout << "\n";
    }
}
