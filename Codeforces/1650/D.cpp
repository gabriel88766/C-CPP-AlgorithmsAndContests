#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void shift(vector<int> &v, int k, int n){
    if(k == 0) return;
    vector<int> ans = v;
    for(int i=1;i<=n;i++){
        int pos = i + k;
        if(pos > n) pos -= n;
        ans[i] = v[pos];
    }
    v = ans;
}
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
        vector<int> ans;
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=n;i>=1;i--){
            int ind = -1;
            for(int j=1;j<=i;j++){
                if(v[j] == i) ind = j;
            }
            ans.push_back(ind % i);
            shift(v, ind % i, i);
        }
        reverse(ans.begin(), ans.end());
        for(auto x : ans ) cout << x << " ";
        cout << "\n";
    }
}
