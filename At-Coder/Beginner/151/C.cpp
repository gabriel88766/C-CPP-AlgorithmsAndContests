#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int cnt[N];
bool ac[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int a1 = 0, a2 = 0;
    for(int i=1;i<=m;i++){
        int p;
        string verd;
        cin >> p >> verd;
        if(verd == "WA") cnt[p]++;
        else{
            if(!ac[p]){
                ac[p] = true;
                a1++;
                a2 += cnt[p];
            }
        }
    }
    cout << a1 << " " << a2 << "\n";
}   
