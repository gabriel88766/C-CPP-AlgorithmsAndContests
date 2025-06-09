#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int inv[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int p;
    cin >> p;
    vector<int> poly(p+1);
    poly[0] = 1;
    for(int i=0;i<p;i++){
        for(int j=p;j>=0;j--){
            poly[j] = poly[j-1] - i*poly[j];
            poly[j] = poly[j] % p;
            if(poly[j] < 0) poly[j] += p;
        }
    }
    for(int i=1;i<p;i++){
        for(int j=1;j<p;j++){
            if(i*j % p == 1) inv[i] = j;
        }
    }
    vector<int> ans(p);
    for(int i=0;i<p;i++){
        int x;
        cin >> x;
        if(x == 1){
            vector<int> cp(p);
            auto aux = poly;
            for(int j=p;j>=1;j--){
                cp[j-1] = aux[j];
                aux[j-1] += i * cp[j-1];
                aux[j-1] %= p;
            }
            int val1 = 0, val2 = 1;
            for(int j=0;j<p;j++){
                val1 += cp[j] * val2;
                val2 = (val2 * i) % p;
                val1 %= p;
            }
            int mt = inv[val1];
            for(int j=0;j<p;j++){
                cp[j] = (cp[j] * mt) % p;
            }

            for(int j=0;j<p;j++){
                ans[j] += cp[j];
                ans[j] %= p;
                if(ans[j] < 0) ans[j] += p;
            }
        }
    }
    for(int j=0;j<p;j++) cout << ans[j] << " ";
    cout << "\n";
}
