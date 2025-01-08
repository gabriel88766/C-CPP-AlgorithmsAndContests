#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void solve1(int l, int r){ // k <= n/2, and [l, r] are all 0
    int lo = l, hi = r;
    while(lo != hi){
        int mid = lo + (hi - lo - 1)/2;
        int ax = ask(l, mid);
        if(ax == 1) hi = mid;
        else lo = mid + 1;
    }
    cout << "! " << lo - l + 1 << "\n";
    cout.flush();
}

void solve2(int x, int n){
    int lo = n/2 + 1, hi = n;
    while(lo != hi){
        int mid = lo + (hi - lo - 1)/2;
        int a1;
        if(x == 1) a1 = ask(x, x + mid - 1);
        else a1 = ask(n-mid+1, n);
        if(a1 == 0) hi = mid;
        else lo = mid + 1;
    }
    cout << "! " << lo << "\n";
    cout.flush();
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
        int a1 = ask(1, n/2);
        //if k > n/2, then wlog a1 = 1, ask 1,n/4 and n/4+1, n/2, only one should be equal 1
        //if k <= n/2, then both will be equal either 1 or 0, and [1, n/2] are all 0
        if(a1 == 1){
            int a2 = ask(1, n/4);
            int a3 = ask(n/4+1, n/2);
            if(a2 == a3){
                solve1(1, n/2);
            }else{
                //k > n/2, and 1 is really in [1, n/2]
                solve2(1, n);
            }
        }else{
            int a2 = ask(n/2+1, n/2 + n/4);
            int a3 = ask(n/2 + n/4 + 1, n);
            if(a2 == a3){
                solve1(n/2 + 1, n);
            }else{
                solve2(n, n);
            }
        }
    }
}
