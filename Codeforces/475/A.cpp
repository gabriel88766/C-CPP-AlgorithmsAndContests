#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string ans[] ={
    "+------------------------+",
    "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|",
    "|#.......................|",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
    "+------------------------+"
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k;
    cin >> k;
    if(k <= 4){
        for(int i=1;i<=k;i++){
            ans[i][1] = 'O';
        }
    }else{
        for(int i=1;i<=4;i++){
            ans[i][1] = 'O';
        }
        k -= 4;
        for(int i=0;i<k;i++){
            int ps = i % 3;
            int r = i / 3;
            ps++;
            if(ps == 3) ps++;
            ans[ps][2*r+3] = 'O';
        }
        
    }
    for(int i=0;i<=5;i++){
        cout << ans[i] << "\n";
    }
}
