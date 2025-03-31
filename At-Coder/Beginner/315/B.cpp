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
    int m;
    cin >> m;
    vector<int> a(m);
    int sd = 0;
    for(int i=0;i<m;i++){
        cin >> a[i];
        sd += a[i];
    }
    int os = 0;
    for(int i = 0; i < m; i++){
        if(a[i] + os > sd/2){
            cout << i+1 << " ";
            int d = sd/2 + 1 - os;
            cout << d << "\n";
            break;
        }
        os += a[i];
    }
}
