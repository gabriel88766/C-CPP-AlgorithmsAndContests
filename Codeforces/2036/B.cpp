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
        int n, k;
        cin >> n >> k;
        vector<int> cnt(k+1);
        for(int i=1;i<=k;i++){
            int a, b;
            cin >> a >> b;
            cnt[a] += b;
        }
        vector<int> cs;
        for(int i=1;i<=k;i++){
            cs.push_back(cnt[i]);
        }
        sort(cs.begin(), cs.end(), greater<int>());
        int sum = 0;
        for(int i=0;i<min(n, k);i++) sum += cs[i];
        cout << sum << "\n";
    }
}
