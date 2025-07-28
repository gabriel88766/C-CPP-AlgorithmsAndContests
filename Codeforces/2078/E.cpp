#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int x){
    cout << x << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    int num1 = 0, num2 = 0;
    for(int i=0;i<30;i++){
        if(i % 2) num1 |= (1 << i);
        else num2 |= (1 << i);
    }
    while(t--){
        int a1 = ask(num1);
        int a2 = ask(num2);
        int x1 = 0, x2 = 0;

        auto func = [&](int num, int ax){
            int br = 0;
            for(int i=30;i>=0;i--){
                if(i == 30){
                    if(ax & (1 << i)) br = 1;
                }else{
                    if(num & (1 << i)){
                        if(ax & (1 << i)) br = 1;
                        else br = 0;
                    }else{
                        if(i == 0){
                            if(br == 1){
                                x1 |= 1 << i;
                                x2 |= 1 << i;
                            }else{
                                if(ax & (1 << i)){
                                    x1 |= 1 << i;
                                }
                            }
                        }else{
                            if(br == 1){
                                x1 |= 1 << i;
                                if(ax & (1 << i)){
                                    x2 |= 1 << i;
                                }
                            }
                        }
                    }
                }
            }
        };
        func(num1, a1);
        func(num2, a2);
        cout << "! " << "\n";
        cout.flush();
        int m;
        cin >> m;
        cout << ((x1 | m) + (x2 | m)) << "\n";
        cout.flush();
    }
}
