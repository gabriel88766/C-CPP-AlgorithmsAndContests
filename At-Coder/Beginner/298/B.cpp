#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
void rotate(vector<vector<int>> &a){
    auto aux = a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = aux[n-j-1][i];
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n)), b(n, vector<int> (n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> b[i][j];

    bool ok = false;
    for(int i=0;i<4;i++){
        bool ok2 = true;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[j][k] && !b[j][k]) ok2 = false;
            }
        }
        if(ok2) ok = true;
        rotate(a);
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
 