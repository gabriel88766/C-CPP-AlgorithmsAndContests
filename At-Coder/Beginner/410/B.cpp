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
    int n, q;
    cin >> n >> q;
    vector<int> bx(n);
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(x == 0) x = min_element(bx.begin(), bx.end()) - bx.begin();
        else x--;
        cout << x+1 << " ";
        bx[x]++;
    }
}
