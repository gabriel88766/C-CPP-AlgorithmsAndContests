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
        vector<int> a(n+1), b(n+1);
        vector<int> idx;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++){
            cin >> b[i];
        }
        bool ok = false;
        int p1 = 1, p2 = n;
        for(int i=1;i<=n;i++){
            if(b[p1] == a[i] || b[p2] == a[i]){
                if(b[p1] == a[i]) p1++;
                else p2--;
            }else ok = true;
        }
        p1 = 1, p2 = n;
        for(int i=n;i>=1;i--){
            if(b[p1] == a[i] || b[p2] == a[i]){
                if(b[p1] == a[i]) p1++;
                else p2--;
            }else ok = true;
        }
        if(ok) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
