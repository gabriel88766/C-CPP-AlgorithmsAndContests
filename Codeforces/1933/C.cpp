#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
vector<int> divs[N];
void fdiv(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divs[j].push_back(i);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    fdiv();
    int t;
    cin >> t;
    while(t--){
        int a, b, l;
        cin >> a >> b >> l;
        ll ans = 0;
        for(auto x : divs[l]){
            int cur = l / x;
            for(int i=0;;i++){
                int cp1 = 1;
                for(int j=0;j<i;j++) cp1 *= a;
                if(cur < cp1) break;
                if(cur % cp1) break;
                int aux = cur / cp1;
                while(!(aux % b)) aux /= b;
                if(aux == 1){
                     ans++;
                     break;
                }
            }
        }
        cout << ans << "\n";
    }
}
