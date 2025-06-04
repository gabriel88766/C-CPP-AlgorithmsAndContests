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
        deque<int> v(m);
        for(int i=0;i<m;i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<pair<int, int>> ans(n);
        for(int i=0;i<n;i++){
            if(v.size() == 1){
                int a = v.front();
                v.pop_front();
                ans[i] = {a, a};
                assert(i+1 == n);
            }else{
                int a = v.front();
                int b = v.back();
                v.pop_front();
                v.pop_back();
                ans[i] = {a, b};
                if(i+1 < ans.size()) ans[i+1] = {b, a};
                i++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++) cout << ans[i].first << " " << ans[i].second << " ";
            cout << "\n";
        }
    }
}
