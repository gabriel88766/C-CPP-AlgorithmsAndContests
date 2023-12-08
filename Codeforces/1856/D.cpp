#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cg = 0;
int n;

int query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    cg += (r - l) * (r - l);
    assert(cg <= 5*n*n);
    return ans;
}


int solve(int l, int r){
    if(l == r) return l;
    else{
        int m = (l+r)/2;
        int x1 = solve(l, m);
        int x2 = solve(m+1, r);
        if(x2 == x1+1){
            int ans = query(x1, x2);
            if(ans == 1) return x1;
            else return x2;
        }else{
            int ans1 = query(x1, x2-1);
            int ans2  = query(x1, x2);
            if(ans1 != ans2) return x1;
            else return x2;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cg = 0;
        cin >> n;
        int x = solve(1, n);
        cout << "! " << x << "\n";
        cout.flush();
    }
}
