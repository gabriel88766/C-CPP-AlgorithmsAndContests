#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e3+5;
bool used[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n), c(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<k;i++){
        c[i] = i+1;
        used[v[i]][i+1] = true;
    }
    bool ok = true;
    for(int i=k;i<n;i++){
        if(!ok) break;
        ok = false;
        for(int j=1;j<=k;j++){
            if(!used[v[i]][j]){
                used[v[i]][j] = true;
                c[i] = j;
                ok = true;
                break;
            }
        }
    }

    if(ok){
        cout << "YES\n";
        for(int i=0;i<n;i++) cout << c[i] << " ";
    }else{
        cout << "NO\n";
    }
}
