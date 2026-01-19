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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> sc(n+1, k-q);
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        sc[x]++;
    }
    for(int i=1;i<=n;i++){
        if(sc[i] >= 1) cout << "Yes\n";
        else cout << "No\n";
    }
}
