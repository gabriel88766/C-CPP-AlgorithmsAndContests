#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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
        int n;
        vector<bool> pos(10, true);
        cin >> n;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            pos[aux] = false;
        }
        int cnt = 0;
        for(int i=0;i<=9999;i++){
            int cntd = 0;
            int aux = i;
            vector<bool> used(10, false);
            vector<int> qt(10, 0);
            bool ok = true;
            for(int j=0;j<4;j++){
                int curd = aux % 10;
                if(!used[curd]) cntd++;
                used[curd] = true;
                qt[curd]++;
                if(qt[curd] == 3) ok = false;
                if(!pos[curd]) ok = false;
                aux /= 10;
            }
            if(ok && cntd == 2) cnt++;
        }
        cout << cnt << "\n";
    }
}
