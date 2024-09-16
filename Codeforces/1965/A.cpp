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
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        vector<int> d;
        for(int i=1;i<v.size();i++){
            d.push_back(v[i] - v[i-1]);
        }
        reverse(d.begin(), d.end());
        int ans = 0;
        for(int i=0;i<d.size();i++){
            if(d[i] != 1) ans = 1;
            else ans ^= 1;
        }
        if(ans) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
