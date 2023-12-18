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
    int x = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        x ^= a[i];
    }
    if(x != 0){
        cout << "-1\n";
        return 0;
    }
    //try values between 1 and max a[i]
    int ans = 0;
    auto aux = a;
    sort(a.begin(), a.end());
    sort(aux.begin(), aux.end());
    aux.resize(unique(aux.begin(), aux.end()) - aux.begin());
    int p = 0;
    x = 0;
    for(int i=0;i<aux.size();i++){
        while(p < n && a[p] <= aux[i]){
            x ^= a[p];
            p++;
        }
        if(x) ans = aux[i+1] - 1;
    }
    if(ans != 0){
        x = 0;
        for(int i=0;i<n;i++) x^= (a[i] % (ans+1));
        assert(x != 0);
    }
    cout << ans << "\n";
}
