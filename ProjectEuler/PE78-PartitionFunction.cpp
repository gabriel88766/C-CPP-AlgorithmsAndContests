#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll N = 5e5+1;
ll P[N];
//O(N sqrt(N))
//in this problem need to find, but we don't know the bounds
//so guess.
void calc(){
    P[0] = 1;
    for(int i=1; i < N;i++){
        for(int k=1;k<=i;k++){
            int v1 = i - (k*(3*k-1))/2;
            int v2 = i - (k*(3*k+1))/2;
            int s = (k+1) % 2 ? -1 : 1;
            if(v1 < 0 && v2 < 0) break;
            if(v1 >= 0) P[i] += s*P[v1];
            if(v2 >= 0) P[i] += s*P[v2];
        }
        P[i] %= 1000000;
        if(P[i] % 1000000 == 0){
            cout << i << "\n";
            break;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    calc();
}
