#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll calc(int a, int b){
    if(a == b) return 1;
    else if(a == 0 || b == 0){
        if(a == 0) return 2;
        else return 3;
    }else if(a > b){
        int dif = a-b;
        int rd = 2*dif;
        int x = b/rd;
        if(x >= 1) return calc(a-x*rd, b-x*rd);
        else return calc(b, a-b) + 1;
    }else{
        return calc(b, b-a) + 1;
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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];

        bool ok = true;
        bool ok1 = false, ok2 = false, ok0 = false;;
        for(int i=0;i<n;i++){
            if(a[i] == 0 && b[i] == 0) continue;
            ll v = calc(a[i], b[i]);
            //cout << a[i] << " " << b[i] << " " << v << "\n";
            if(v % 3 == 0) ok0 = true;
            else if(v % 3 == 1) ok1 = true;
            else ok2 = true;
        }
        int cnt = 0;
        if(ok0) cnt++;
        if(ok1) cnt++;
        if(ok2) cnt++;
        if(cnt > 1) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";

    }
}
