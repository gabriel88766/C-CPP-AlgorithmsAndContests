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
        vector<int> s(n), e(n);
        for(int i=0;i<n;i++) cin >> s[i] >> e[i];
        int minw = 1;
        for(int i=1;i<n;i++){
            if(e[i] >= e[0]) minw = max(minw, s[i]+1);
        }
        if(s[0] >= minw) cout << minw << "\n";
        else cout << "-1\n";
    }
}
 