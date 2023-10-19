#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[105];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int t, x;
        cin >> t >> x;
        if(t == 1) cnt[x]++;
        else if(t == 2) cnt[x] += 2;
        else if(cnt[x] >= 2) cout << "Yes\n";
        else cout << "No\n";
    }
}
