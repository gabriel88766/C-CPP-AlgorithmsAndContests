#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
int gr[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    vector<int> a(n+1), b(n+1);
    a[0] = b[0] = INF_INT;
    for(int j=1;j<=n;j++){
        b[j] = gr[1][j];
    }
    for(int i=1;i<=n;i++){
        a[i] = gr[i][1] - b[1];
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=n;j++){
            if(gr[i][j] != a[i] + b[j]) ok = false;
        }
    }
    if(*min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end()) < 0) ok = false;
    if(ok){
        cout << "Yes\n";
        int ma = *min_element(a.begin(), a.end());
        int mb = *min_element(b.begin(), b.end());
        if(ma < 0){
            for(int i=1;i<=n;i++){
                a[i] -= ma;
                b[i] += ma;
            }
        }
        if(mb < 0){
            for(int i=1;i<=n;i++){
                a[i] += mb;
                b[i] -= mb;
            }
        }
        for(int i=1;i<=n;i++) cout << a[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) cout << b[i] << " ";
        cout << "\n";
    }else cout << "No\n";
}
