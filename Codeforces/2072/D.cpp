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
        pair<int, int> ans = {1, 1};
        int ls = 0;
        for(int l=1;l<=n;l++){
            int cur = 0;
            for(int r=l+1;r<=n;r++){
                if(v[r] > v[l]) cur++;
                if(v[r] < v[l]) cur--;
                if(cur < ls){
                    ls = cur;
                    ans = {l, r};
                }
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}
