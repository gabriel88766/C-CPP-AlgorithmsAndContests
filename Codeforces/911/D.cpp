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
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int inv = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(v[i] > v[j]) inv++;
        }
    }
    int cur = inv % 2;
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        int  len = r - l + 1;
        int sum = (len * (len - 1))/2;
        cur ^= (sum % 2);
        if(cur == 1) cout << "odd\n";
        else cout << "even\n";
    }
}
