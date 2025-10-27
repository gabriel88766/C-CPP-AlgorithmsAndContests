#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int tp, int l, int r){
    cout << tp << " " << l << " " << r << "\n";
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = query(2, 1, n) - query(1, 1, n);
        int lo = 1, hi = n;
        //F F F ... T T 
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            int xx = query(2, 1, mid) - query(1, 1, mid);
            if(xx) hi = mid;
            else lo = mid + 1;
        }
        cout << "! " << lo << " " << lo + x - 1 << "\n";
        cout.flush();
    }
}
