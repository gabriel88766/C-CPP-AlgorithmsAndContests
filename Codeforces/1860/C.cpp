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
        set<int> s0, s1;
        int ans = 0;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            if(!size(s0)) s0.insert(aux);
            else{
                if(*s0.begin() > aux) s0.insert(aux);
                else{
                    if(!size(s1)) s1.insert(aux);
                    else{
                        if(*s1.begin() > aux) s1.insert(aux);
                    }
                }
            }
        }
        cout << s1.size() << "\n";
    }
}