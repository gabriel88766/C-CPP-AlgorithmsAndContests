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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> v(n);
        int ind = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] == 1) ind = i;
        } 
        bool ok1 = true, ok2 = true;
        for(int i=ind+1;i<n+ind;i++){
            if(v[(i-1)%n] > v[i%n]) ok1 = false;
        }
        for(int i=n+ind-1;i>ind;i--){
            if(v[(i+1)%n] > v[i%n]) ok2 = false;
        }
        if(ok1 || ok2) cout << "YES\n";
        else cout << "NO\n";
    }
}
