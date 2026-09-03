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
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        vector<int> c1(30), c2(30);
        for(int i=0;i<n;i++){
            for(int j=0;j<30;j++){
                if(a[i] & (1 << j)) c1[j]++;
                if(b[i] & (1 << j)) c2[j]++;
            }
        }
        int tn = 0;
        for(int j=0;j<30;j++){
            if(c1[j] != c2[j]) tn |= (1 << j);
        }
        bool ok = true;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(a[i] == tn){
                idx = i;
                break;
            }
        }
        if(idx == -1 && tn != 0) ok = false;
        else{
            for(int j=0;j<n;j++){
                if(j != idx) a[j] ^= tn ? a[idx] : 0;
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if(a != b) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
