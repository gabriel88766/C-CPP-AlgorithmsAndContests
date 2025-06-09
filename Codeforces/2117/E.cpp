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
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        set<int> st[2];
        bool ok = false;
        for(int i=n;i>=1;i--){
            int bt = i & 1; 
            if(st[bt^1].count(a[i])){
                cout << i << "\n";
                ok = true;
                break;
            }
            if(st[bt].count(b[i])){
                cout << i << "\n";
                ok = true;
                break;
            }
            if(a[i] == b[i]){
                cout << i << "\n";
                ok = true;
                break;
            }
            if(i > 1){
                if(st[bt^1].count(a[i-1])){
                    cout << i-1 << "\n";
                    ok = true;
                    break;
                }
                if(st[bt].count(b[i-1])){
                    cout << i-1 << "\n";
                    ok = true;
                    break;
                }
            }
            
            st[bt].insert(a[i]);
            st[bt^1].insert(b[i]);
        }
        if(!ok) cout << "0\n";
    }
}
