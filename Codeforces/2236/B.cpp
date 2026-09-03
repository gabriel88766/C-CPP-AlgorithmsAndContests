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
        string s;
        bool ok = true;
        cin >> n >> k >> s;
        for(int i=0;i<k;i++){
            int cnt = 0;
            for(int j=i;j<n;j+=k){
                if(s[j] == '1') cnt++;
            }
            if(cnt % 2 == 1) ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
