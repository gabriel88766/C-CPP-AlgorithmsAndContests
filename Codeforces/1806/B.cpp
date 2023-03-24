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
        int n;
        cin >> n;
        int cnt = 0;
        bool n1 = false, h1 = false;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            if(!aux) cnt++;
            else if(aux != 1) n1 = true;
            else h1 = true;
        }
        if(cnt > (n+1)/2){
            if(n1 || !h1) cout << "1\n";
            else cout << "2\n";
        } 
        else cout << "0\n";
    }
}
