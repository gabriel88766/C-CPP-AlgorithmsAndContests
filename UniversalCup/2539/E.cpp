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
    vector<int> a(n+1), b(n+1);
    int x = 2*n;
    for(int i=1;i<=n;i+=2){
        a[i] = x--;
    }
    if(n % 2 == 0) a[n] = x--;
    for(int i=2;i<=n;i+=2) b[i] = x--;
    for(int i=1;i<=n;i++){
        if(a[i] == 0) a[i] = x--;
        if(b[i] == 0) b[i] = x--;
    }
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";
    for(int i=1;i<=n;i++) cout << b[i] << " ";
    cout << "\n";
}
