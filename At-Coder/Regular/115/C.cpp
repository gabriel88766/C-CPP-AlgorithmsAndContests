#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
bool cant[N][30];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    int mx = 0;
    for(int i=1;i<N;i++){
        ans[i] = 1;
        while(cant[i][ans[i]]){
            ans[i]++;
        }
        for(int j=i;j<N;j+=i){
            cant[j][ans[i]] = true;
        }
        if(ans[i] > mx){ //proving my answer is correct
            mx = ans[i];
            int aux = i;
            while(aux % 2 == 0) aux /= 2;
            assert(aux == 1);
        }
    }
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
