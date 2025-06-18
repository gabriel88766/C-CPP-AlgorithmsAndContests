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
    int n, q, of = 0;
    cin >> n >> q;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for(int i=1;i<=q;i++){
        int tq, p, x, k;
        cin >> tq;
        if(tq == 1){
            cin >> p >> x;
            p--;
            a[(p+of) % n] = x;
        }else if(tq == 2){
            cin >> p;
            p--;
            cout << a[(p+of) % n] << "\n";
        }else{
            cin >> k;
            of += k;
            of %= n;
        }
    }
}
