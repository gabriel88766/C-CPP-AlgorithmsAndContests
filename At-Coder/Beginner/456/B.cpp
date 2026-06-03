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
    double p = 1.0/216, ans = 0;
    vector<int> a(6), b(6), c(6);
    for(int i=0;i<6;i++) cin >> a[i];
    for(int i=0;i<6;i++) cin >> b[i];
    for(int i=0;i<6;i++) cin >> c[i];
    vector<int> perm = {4, 5, 6};
    do{
        double cp = p;
        int cnt = 0;
        for(int i=0;i<6;i++) if(a[i] == perm[0]) cnt++;
        cp *= cnt;
        cnt = 0;
        for(int i=0;i<6;i++) if(b[i] == perm[1]) cnt++;
        cp *= cnt;
        cnt = 0;
        for(int i=0;i<6;i++) if(c[i] == perm[2]) cnt++;
        cp *= cnt;
        ans += cp;
    }while(next_permutation(perm.begin(), perm.end()));
    cout << setprecision(10) << ans << "\n";
}
