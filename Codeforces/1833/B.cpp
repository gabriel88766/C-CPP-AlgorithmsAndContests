#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<int> a, b;

bool func(int i, int j){
    return a[i] < a[j];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> ord;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            a.push_back(aux);
        }
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            b.push_back(aux);
        }
        for(int i=0;i<n;i++){
            ord.push_back(i);
        }
        sort(b.begin(), b.end());
        sort(ord.begin(), ord.end(), func);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[ord[i]] = b[i];
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
        a.clear();
        b.clear();
    }
}
