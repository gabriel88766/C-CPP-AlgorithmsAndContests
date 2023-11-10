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
        int n, m, k;
        cin >> n >> m;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        cin >> k;
        vector<int> b(k);
        for(int i=0;i<k;i++) cin >> b[i];
        int p1 = 0, p2 = 0;
        bool ok = true;
        int reduc = 0, curv = 0;
        while(p1 < n && p2 < k){

        }
        if(ok && p1 == n && p2 == k) cout << "Yes\n";
        else cout << "No\n";
    }
}
