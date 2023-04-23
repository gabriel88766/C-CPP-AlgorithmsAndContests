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
    int n;
    cin >> n;
    int lo = 1, hi = n, mid;
    while(lo != (hi-1)){
        mid = (lo+hi)/2;
        cout << "? " << mid << "\n";
        cout.flush();
        int ans;
        cin >> ans;
        if(ans == 1) hi = mid;
        else lo = mid;
    }
    cout << "! " << lo << "\n";
    cout.flush();   
}
