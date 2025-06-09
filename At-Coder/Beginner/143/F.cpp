#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+1;
int cnt[N];
int aux[N], aux2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt[x]++;   
    }
    for(int i=1;i<=n;i++){
        aux[1] += 1;
        aux[cnt[i]+1] -= 1;
    }
    for(int i=1;i<=n;i++){
        aux[i] += aux[i-1];
        aux2[i] = aux2[i-1] + aux[i];
    }
    for(int i=1;i<=n;i++){
        int lo = 0, hi = n/i;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            if(i * mid <= aux2[mid]) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
