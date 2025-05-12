#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, d;
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        v[x]++;
    }
    int ans = 0;
    if(d != 0){
        for(int r=0;r<d;r++){
            int a0 = 0, a1 = 0;
            for(int x = r; x < N; x += d){
                int na0 = a1 + v[x];
                int na1 = max(a0, a1);
                a0 = na0;
                a1 = na1;
            }
            ans += max(a0, a1);
        }
    }else{
        for(int i=0;i<N;i++){
            if(v[i]) ans += 1;
        }
    }
    cout << n-ans << "\n";
}
