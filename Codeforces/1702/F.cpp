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
        multiset<int> a, b;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            while(!(x % 2)) x /= 2;
            a.insert(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            while(!(x % 2)) x /= 2;
            b.insert(x);
        }
        for(int i=0;i<30;i++){
            multiset<int> rml;
            for(auto x : b){
                auto it = a.find(x);
                if(it != a.end() && *it == x){
                    a.erase(it);
                    rml.insert(x);
                }
            }
            for(auto x : rml) b.erase(b.find(x));
            multiset<int> newb;
            bool nok = false;
            for(auto x : b){
                x /= 2;
                if(x == 0){
                    nok = true;
                    break;
                }
                newb.insert(x);
            }
            if(nok) break;
            b = newb;
        }
        if(a.size()) cout << "NO\n";
        else cout << "YES\n";
    }
}
