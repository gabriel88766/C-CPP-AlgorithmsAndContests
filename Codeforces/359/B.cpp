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
    int n, k;
    cin >> n >> k;
    //2k <= n
    set<int> s;
    for(int i=1;i<=2*n;i++) s.insert(i);
    for(int i=1;i<=n;i++){
        int n1 = *s.begin();
        int n2 = *prev(s.end());
        if(k){
            if(k >= n2 - n1){
                cout << n2 << " " << n1 << " ";
                s.erase(n2);
                s.erase(n1);
                k -= (n2 - n1);
            }else{
                n2 = n1 + k;
                cout << n2 << " " << n1 << " ";
                k = 0;
                s.erase(n1);
                s.erase(n2);
            }
        }else{
            cout << n1 << " " << n2 << " ";
            s.erase(n1);
            s.erase(n2);
        }
    }
}
