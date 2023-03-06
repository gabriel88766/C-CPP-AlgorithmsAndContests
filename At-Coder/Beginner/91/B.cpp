#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i=0;i<30;i++){
        int cur = 1 << i;
        ll cs = 0;
        for(int j=0;j<n;j++){
            cs += n-(lower_bound(a.begin(), a.end(), cur - b[i]) - a.begin());
        }
        cout << i << " " << cs << "\n";
        if(cs % 2) ans |= cur;
    }
    cout << ans;

}   
