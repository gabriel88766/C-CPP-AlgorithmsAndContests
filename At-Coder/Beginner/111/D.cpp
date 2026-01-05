//THIS SOLUTION IS USING BALANCED TERNARY
//ITS NOT REQUIRED, BUT ITS COOL!!
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
    vector<pair<ll, ll>> vx(n);
    bool sodd = false, seven = false;
    for(int i=0;i<n;i++){
        cin >> vx[i].first >> vx[i].second;
        if((vx[i].first + vx[i].second) % 2) sodd = true;
        else seven = true;
    }
    if(sodd && seven) cout << "-1\n";
    else{
        vector<ll> vals;
        vals.push_back(1);
        vals.push_back(1);
        for(ll i=1;i<1e9;){
            i *= 3;
            vals.push_back(i);
            vals.push_back(i);
        }
        if(sodd) vals.pop_back();
        cout << vals.size() << "\n";
        for(auto x : vals) cout << x << " ";
        cout << "\n";
        for(auto [a, b] : vx){
            for(int j=0;j<=19;j++){ //ca from -2 to 2, a % 3 from -2 to 2, then sum is from -2 to 4
                ll ba = (a % 3);
                ll bb = (b % 3);
                if(abs(ba) == 2){
                    if(ba == 2) ba = -1;
                    else ba = 1;
                }
                if(abs(bb) == 2){
                    if(bb == 2) bb = -1;
                    else bb = 1;
                }

                if(j == 19 && sodd){
                    
                    assert(abs(ba) == 0 || abs(bb) == 0);
                    assert(abs(ba) == 1 || abs(bb) == 1);
                    if(abs(ba) == 1){
                        if(ba == -1) cout << "L";
                        else cout << "R";
                    }else{
                        if(bb == -1) cout << "D";
                        else cout << "U";
                    }
                }else{
                    if(ba == 0 && bb == 0) cout << "LR";
                    else if(abs(ba) == 1 && abs(bb) == 1){
                        if(ba == -1) cout << "L";
                        else cout << "R";
                        if(bb == -1) cout << "D";
                        else cout << "U";
                    }else{
                        if(abs(ba) == 1){
                            if(ba == -1){
                                ba = 2;
                                cout << "RR";
                            }else{
                                ba = -2;
                                cout << "LL";
                            }
                        }else{
                            if(bb == -1){
                                bb = 2;
                                cout << "UU";
                            }else{
                                bb = -2;
                                cout << "DD";
                            }
                        }
                    }
                }
                a -= ba;
                b -= bb;
                assert(a % 3 == 0);
                assert(b % 3 == 0);
                a /= 3;
                b /= 3;                                                               
            }                       
            cout << "\n";
            assert(a == 0 && b == 0);
        }
    }
}
