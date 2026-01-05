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
        string s;
        cin >> n >> s;
        bool ok1 = false, ok2 = true;
        for(int i=0;i<=n-4;i++){
            if(s.substr(i, 4) == "2026") ok2 = false;
            if(s.substr(i, 4) == "2025") ok1 = true;
        }
        if(ok1 && ok2) cout << "1\n";
        else cout << "0\n";
    }
}
