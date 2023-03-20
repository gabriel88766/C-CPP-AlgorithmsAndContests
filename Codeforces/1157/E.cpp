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
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        m.insert(aux);
    }
    for(int i=0;i<n;i++){
        auto it = m.lower_bound(0);
        auto it2 = m.lower_bound(n-a[i]);
        if(it2 == m.end()){
            cout << (a[i] + *it) % n << " ";
            m.erase(it);
        }else{
            cout << (a[i] + *it2) % n << " ";
            m.erase(it2);
        }
    }
}
