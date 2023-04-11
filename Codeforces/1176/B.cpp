#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            if(aux%3 == 0) cnt0++;
            else if(aux%3 == 1) cnt1++;
            else cnt2++;
        }
        int dif = max(cnt1, cnt2) - min(cnt1, cnt2);
        cout << cnt0 + min(cnt1,cnt2) + dif/3 << "\n";
    }
}
