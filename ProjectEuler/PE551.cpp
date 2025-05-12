#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//Not a really good way to solve this...
//~170*170*10^7 * 10^10
int sdig(ll num){
    int ans = 0;
    while(num){
        ans += num % 10;
        num /= 10;
    }
    return ans;
}
pair<int, int> jmp[340][170];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    const int M = 1e7;
    for(int i=0;i<340;i++){
        for(int j=0;j<170;j++){
            if(i == 0 && j == 0) continue; //impossible
            int cnt = 0, num = i;
            while(num < M){
                cnt++;
                num += j + sdig(num);
            }
            jmp[i][j] = {num - M, cnt};
            assert(jmp[i][j].first < 340);
        }
    }
    ll PL = 999'999'999'999'999LL;
    ll numi = 1, pr = 0;
    while(PL){
        int sd = sdig(pr);
        if(PL >= jmp[numi][sd].second){
            PL -= jmp[numi][sd].second;
            pr++;
            numi = jmp[numi][sd].first;
        }else{
            for(int i=0;i<PL;i++){
                numi += sd + sdig(numi);
            }
            PL = 0;
        }
    }
    cout << pr*M + numi << "\n";
}
