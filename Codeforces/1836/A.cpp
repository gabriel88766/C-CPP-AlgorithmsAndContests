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
        vector<int> cnt(100, 0);
        cin >> n;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            cnt[aux]++;
        }
        bool ok = true;
        for(int i=1;i<100;i++){
            if(cnt[i] > cnt[i-1]) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
