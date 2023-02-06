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
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> d(10, 0);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            d[aux%10]++;
        }
        bool ok = false;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k++){
                    if((i+j+k) % 10 == 3){
                        vector<int> aux(10, 0);
                        aux[i]++;
                        aux[j]++;
                        aux[k]++;
                        if(d[i] >= aux[i] && d[j] >= aux[j] && d[k] >= aux[k]) ok = true;
                    }
                }
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
