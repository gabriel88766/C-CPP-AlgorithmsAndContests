#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    if(s == "first"){
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            int p1 = -1, pn = -1;
            for(int i=1;i<=n;i++){
                int x;
                cin >> x;
                if(x == 1) p1 = i;
                if(x == n) pn = i;
            }
            if(pn > p1) cout << "0\n"; //the right side is pn
            else cout << "1\n"; //the left side is pn
        }
    }else{
        int t;
        cin >> t;
        while(t--){
            int n, x;
            cin >> n >> x;
            int l = 1, r = n;
            int p2 = 1;
            while(p2 * 2 < n) p2 *= 2;
            for(int j=p2;j>=1;j>>=1){
                if(l + j < r && query(l + j, r) == n-1) l += j;
                if(r - j > l && query(l, r - j) == n-1) r -= j;
            }
            if(x == 0) cout << "! " << r << "\n";
            else cout << "! " << l << "\n";
            cout.flush();
        }
    }
}
