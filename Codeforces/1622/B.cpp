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
        vector<int> p(n), ans(n);
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        string s;
        cin >> s;
        vector<pair<int,int>> v1, v0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                v1.push_back({p[i], i});
            }else{
                v0.push_back({p[i], i});
            }
        }
        sort(v0.begin(), v0.end());
        sort(v1.begin(), v1.end(), greater<pair<int,int>>());
        int cur = 1;
        for(auto [x, j] : v0){
            ans[j] = cur++;
        }
        cur = n;
        for(auto [x, j] : v1){
            ans[j] = cur--;
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
