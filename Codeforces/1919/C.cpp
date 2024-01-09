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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<int> v1, v2;
        v1 = v2 = {INF_INT};
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(v[i] > min(v1.back(), v2.back()) && v[i] <= max(v1.back(), v2.back())){
                if(v1.back() >= v[i]) v1.push_back(v[i]);
                else v2.push_back(v[i]);
            }else if(v[i] <= min(v1.back(), v2.back())){
                if(v1.back() < v2.back()) v1.push_back(v[i]);
                else v2.push_back(v[i]);
            }else{
                ans++;
                if(v1.back() < v2.back()) v1.push_back(v[i]);
                else v2.push_back(v[i]);
            }
        }
        cout << ans << "\n";
    }
}
