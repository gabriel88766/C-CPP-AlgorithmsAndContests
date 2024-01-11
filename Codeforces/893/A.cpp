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
    bool ok = true;
    int a = 1, b = 2;
    for(int i=0;i<n;i++){
        if(a > b) swap(a, b);
        int x;
        cin >> x;
        if(x != a && x != b){
            ok = false;
            break;
        }
        if(x == a){
            if(a != 1 && b != 1) b = 1;
            else if(a != 2 && b != 2) b = 2;
            else b = 3;
        }else{
            if(a != 1 && b != 1) a = 1;
            else if(a != 2 && b != 2) a = 2;
            else a = 3;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
