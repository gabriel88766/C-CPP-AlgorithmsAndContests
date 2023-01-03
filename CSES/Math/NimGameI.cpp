#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t, n, ans, aux;
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        for(int i=0;i<n;i++){
            cin >> aux;
            ans ^= aux;
        }
        if(ans) cout << "first\n";
        else cout << "second\n";
    }
}
