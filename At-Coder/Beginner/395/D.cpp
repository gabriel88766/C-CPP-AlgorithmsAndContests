#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int  pd[N], np[N], nl[N];
void init(int n){
    for(int i=1;i<=n;i++) pd[i] = i, np[i] = i, nl[i] = i;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    init(n);
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        if(x == 1){
            int a, b;
            cin >> a >> b;
            pd[a] = np[b]; //place where nest b is
        }else if(x == 2){
            int a, b;
            cin >> a >> b;
            int xa = np[a];
            int xb = np[b];
            swap(np[a], np[b]);
            nl[xa] = b;
            nl[xb] = a;
            // swap(nl[a], nl[b]);
        }else{
            int a;
            cin >> a;
            cout << nl[pd[a]] << "\n";
        }
    }
}
