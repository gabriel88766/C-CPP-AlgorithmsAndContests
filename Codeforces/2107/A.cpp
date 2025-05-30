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
        int mx = *max_element(v.begin(), v.end());
        int mn = *min_element(v.begin()+1, v.end());
        if(mn != mx){
            cout << "Yes\n";
            for(int i=1;i<=n;i++){
                if(v[i] == mx) cout << "1 ";
                else cout << "2 ";
            }
            cout << "\n";
        }else cout << "No\n";
    }
}
