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
        int r0 = 0, r1 = 0, t1 = 0, tm1 = 0;
        for(int i=0;i<n;i++){//9cases
            if(a[i] == b[i]){
                if(a[i] == 1) t1++;
                if(a[i] == -1) tm1++;
            }else{
                if(a[i] == 0 && b[i] == -1);//nothing
                if(a[i] == 0 && b[i] == 1) r1++;
                if(a[i] == 1 && b[i] == -1) r0++;
                if(a[i] == 1 && b[i] == 0) r0++;
                if(a[i] == -1 && b[i] == 0); //nothing
                if(a[i] == -1 && b[i] == 1) r1++;
            }
        }
        if(r0 > r1) swap(r0, r1);
        if(t1 <= r1 - r0){
            r0 += t1;
        }else{
            t1 -= r1 - r0;
            r0 = r1;
            r0 += t1/2;
            r1 += t1/2;
            r1 += t1%2;
        }
        if(r1 - r0 >= tm1){
            r1 -= tm1;
        }else{
            tm1 -= r1-r0;
            r1 = r0;
            r0 -= tm1/2;
            r1 -= tm1/2;
            r0 -= tm1%2;
        }
        cout << min(r0, r1) << "\n";
    }
}
