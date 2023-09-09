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
        int ans1 = 0, ans0 = 0;
        string s;
        cin >> n;
        vector<int> ps(n+1, 0), v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            ps[i] = v[i] ^ ps[i-1];
        }
        cin >> s;
        s = " " + s;
        for(int i=1;i<=n;i++){
            if(s[i] == '0') ans0 ^= v[i];
            else ans1 ^= v[i];
        }
        int q;
        cin >> q;
        for(int i=0;i<q;i++){
            int tq;
            cin >> tq;
            if(tq == 1){
                int l, r;
                cin >> l >> r;
                int val = ps[r] ^ ps[l-1];
                ans0 ^= val;
                ans1 ^= val;
            }else{
                int a;
                cin >> a;
                if(a == 0) cout << ans0 << " ";
                else cout << ans1 << " ";
            }
        }
        cout << "\n";
    }
}
