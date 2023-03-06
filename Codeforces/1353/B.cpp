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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        for(int i=0;i<k;i++){
            int ind1, ind2;
            int mina = 31, maxb = 0;
            for(int j=0;j<n;j++){
                if(a[j] < mina){
                    ind1 = j;
                    mina = a[j];
                }
            }
            for(int j=0;j<n;j++){
                if(b[j] > maxb){
                    ind2 = j;
                    maxb = b[j];
                }
            }
            if(mina < maxb){
                swap(a[ind1], b[ind2]);
            }else break;
        }
        int sum = 0;
        for(int i=0;i<n;i++) sum += a[i];
        cout << sum << "\n";
    }
}
