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
        string x, y;
        cin >> n >> x >> y;
        //make x == y
        bool ok = true;
        vector<int> chk = {-1};
        for(int i=0;i<n;i++){
            if(y[i] == 'C' && x[i] != 'C') ok = false;
            if(y[i] == 'C'){
                chk.push_back(i);
            }
        }
        chk.push_back(n);
        for(int i=0;i<chk.size()-1;i++){
            //chk[i], chk[i+1]
            int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
            for(int j=chk[i]+1;j<chk[i+1];j++){
                if(x[j] == 'A') a0++;
                else if(x[j] == 'B') b0++;
                if(y[j] == 'A') a1++;
                else b1++;
            }
            if(a0 > a1 || b0 > b1){
                 ok = false;
                 break;
            }
            for(int j=chk[i]+1;j<chk[i+1];j++){
                if(x[j] == 'C'){
                    if(a0 < a1){
                        x[j] = 'A';
                        a0++;
                    }else{
                        x[j] = 'B';
                        b0++;
                    }
                }
            }
            a0 = a1 = b0 = b1 = 0;
            for(int j=chk[i]+1;j<chk[i+1];j++){
                if(x[j] == 'A') a0++;
                else if(x[j] == 'B') b0++;
                if(y[j] == 'A') a1++;
                else b1++;
                if(b0 > b1) ok = false;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
 