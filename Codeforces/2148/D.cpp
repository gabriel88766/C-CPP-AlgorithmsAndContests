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
        ll ans = 0;
        vector<int> odd;
        cin >> n;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x % 2) odd.push_back(x);
            else ans += x;
        }
        if(odd.size()){
            sort(odd.begin(), odd.end(), greater<int>());
            int hf = (odd.size() + 1) / 2;
            for(int i=0;i<hf;i++) ans += odd[i];
            cout << ans << "\n";
        }else cout << "0\n";
    }
}
