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
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int lo = 0, hi = n/2;
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        bool ok = true;
        int st = n - mid + 1;
        for(int i=1;i<=mid;i++){
            if(2*v[i] > v[st]) ok = false;
            st++;
        }
        if(ok) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
