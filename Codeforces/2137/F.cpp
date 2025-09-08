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
        vector<int> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        vector<pair<int, int>> mq;
        set<pair<int, int>> st;
        ll ans = 0, cur = 0;
        for(int i=n;i>=1;i--){
            while(mq.size() && mq.back().first <= a[i]){
                int j = mq.back().second;
                if(a[j] != b[j]) st.insert({b[j], j});
                mq.pop_back();
            }
            mq.push_back({a[i], i});
            while(st.size() && st.begin()->first <= a[i]){
                cur += n - st.begin()->second + 1;
                st.erase(st.begin());
            }
            if(a[i] == b[i]) cur += n - i + 1;
            ans += cur;
        }
        cout << ans << "\n";
    }
}   
