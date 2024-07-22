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
        sort(v.begin(), v.end());
        bool ok = false;
        int cnt = 0;
        int ls = -1;
        for(int i=0;i<n;i++){
            if(ls != v[i]){
                ls = v[i];
                if(cnt % 2) ok = true;
                cnt = 1;
            }else cnt++;
        }
        if(cnt % 2) ok = true;
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
