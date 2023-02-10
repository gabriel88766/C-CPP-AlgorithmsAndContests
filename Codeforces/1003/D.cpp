#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int qt[31];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int aux, cnt = 0;
        cin >> aux;
        while(!(aux%2)){
            aux /= 2;
            cnt++;
        }
        qt[cnt]++;
    }
    //idk if its greedy// AC, thus greedy
    for(int i=0;i<q;i++){
        int x, ans = 0;
        cin >> x;
        for(int j=30;j>=0;j--){
            int aux = 1 << j, cur;
            if(x >= aux && qt[j]){
                cur = min(qt[j], x/aux);
                x -=  cur * aux;
                ans += cur;
            }
        }
        if(x == 0) cout << ans << "\n";
        else cout << "-1\n";
    }
}
