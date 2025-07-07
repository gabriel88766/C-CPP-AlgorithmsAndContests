#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void sort_lex(vector<int> &v, int l, int r){
    if(l == r) return;
    int m = (l + r)/2;
    sort_lex(v, l, m);
    sort_lex(v, m+1, r);
    if(v[l] > v[m+1]){
        for(int i=l;i<=m;i++){
            swap(v[i], v[i-l+m+1]);
        }
    }
}

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
        int m = 1 << n;
        vector<int> v(m);
        for(int i=0;i<m;i++) cin >> v[i];
        sort_lex(v, 0, m-1);
        for(auto x : v) cout << x << " ";
        cout << "\n";
    }
}
