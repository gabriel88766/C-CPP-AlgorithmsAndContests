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
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int sa = 0, sb = 0;
        for(int i=0;i<n;i++) sa += a[i];
        for(int i=0;i<n;i++) sb += b[i];
        if(sa != sb) cout << "No\n";
        else{
            if(sa == 0 || sa == n) cout << "Yes\n";
            else if(sa != 1) cout << "Yes\n";
            else if(sa == 1 && (a[0] != 1 && a[n-1] != 1 && b[0] != 1 && b[n-1] != 1)) cout << "Yes\n";
            else if(a == b) cout << "Yes\n";
            else cout << "No\n";  
        }
    }
}
