#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

void hanoi(int n, int cur, int nw){
    if(n > 1){
        if(nw == 3){
            hanoi(n-1, cur, cur == 2 ? 1 : 2);
            cout << cur << " " << nw << endl;
            hanoi(n-1, cur == 2 ? 1 : 2, 3);
        }else if(nw == 2){
            hanoi(n-1, cur, cur == 3? 1 : 3);
            cout << cur << " " << nw << endl;
            hanoi(n-1, cur == 3? 1 : 3, 2);
        }else{
            hanoi(n-1, cur, cur == 2? 3 : 2);
            cout << cur << " " << nw << endl;
            hanoi(n-1, cur == 2? 3 : 2, 1);
        }
    }else{
        cout << cur << " " << nw << endl;
    }

}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    cout << ((1 << n) - 1) << endl;
    hanoi(n,1,3);
}
