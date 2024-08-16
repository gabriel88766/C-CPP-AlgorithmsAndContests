#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+1;
int nim[N];
int p[N];
int cnt = -1;
void sieve(){
    for(int i=1;i<N;i++) nim[i] = -1;
    nim[1] = 1;
    for(int i=2;i<N;i++){
        if(!p[i]){
            ++cnt;
            for(int j=i;j<N;j+=i){
                p[j] = 1;
                if(nim[j] == -1) nim[j] = cnt;
            }
            if(i == 2) cnt++;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //init nim;
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            ans ^= nim[x];
            cout << nim[x] << " ";
        }
        if(ans) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
