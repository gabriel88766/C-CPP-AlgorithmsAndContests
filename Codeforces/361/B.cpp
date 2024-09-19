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
    int n, k;
    cin >> n >> k;
    if(n == k) cout << "-1\n";
    else{
        vector<int> v(n+1);
        for(int i=n;i>=n-k+1;i--) v[i] = i;
        for(int i=n-k;i>=2;i--) v[i] = i-1;
        v[1] = n-k;
        for(int i=1;i<=n;i++) cout << v[i] << " ";
        cout << "\n";
    }
}
