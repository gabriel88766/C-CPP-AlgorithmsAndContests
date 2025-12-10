#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cd[11][11];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, d;
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            cin >> cd[i][j];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum = 0;
            for(int k = 1; k <= d; k++){
                sum += (cd[i][k] - cd[j][k]) * (cd[i][k] - cd[j][k]);
            }
            int sqt = sqrt(sum);
            while(sqt*sqt > sum) sqt--;
            while((sqt+1)*(sqt+1) <= sum) sqt++;
            if(sqt*sqt == sum) ans++;
        }
    }
    cout << ans << "\n";
}
