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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    vector<int> odd, even;
    for(int i=0;i<n;i++){
        if(v[i]%2) odd.push_back(v[i]);
        else even.push_back(v[i]);
    }
    int sz1 = odd.size();
    int sz2 = even.size();
    if(abs(sz1 - sz2) <= 1) cout << "0\n";
    else{
        int tt = min(odd.size(), even.size()) + 1;
        int ans = 0;
        if(odd.size() > even.size()){
            for(int i=tt;i<odd.size();i++) ans += odd[i];
        }else{
            for(int i=tt;i<even.size();i++) ans += even[i];
        }
        cout << ans << "\n";
    }
}
