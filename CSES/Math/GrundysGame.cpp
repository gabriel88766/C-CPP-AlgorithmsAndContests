#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> num(2001, 0);

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=3;i<=2000;i++){
        vector<bool> used(i, false);
        for(int j=1;2*j < i; j++){
            used[num[j] ^ num[i-j]] = true;
        }
        for(int j=0;j<i;j++){
            if(!used[j]){
                num[i] = j;
                break;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 2000) cout << (num[n] ? "first" : "second") << "\n";
        else cout << "first\n";
    }
}
