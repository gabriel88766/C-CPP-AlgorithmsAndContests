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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<int>());
        deque<int> dq;
        int ans = 0;
        for(auto x : v){
            dq.push_front(x);
            while(dq.size() > 2){
                int sum = dq[0] + dq[1];
                if(sum <= dq.back()) dq.pop_back();
                else break;
            }
            ans = max(ans, (int)dq.size());
        }
        ans = n - ans;
        cout << ans << "\n";
    }
}
