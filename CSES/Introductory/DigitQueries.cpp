#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll q, cur, digits, t, begin, index;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> cur;
        digits = 1;
        t = 9;
        begin = 1;
        while(true){
            if(cur > t*digits){
                cur -= t*digits;
                t *= 10;
                begin *=10;
                digits++;
            }else{
                begin += cur/digits;
                cur -= (cur/digits) * digits;
                if(!cur){
                    begin--;
                    cur = digits-1;
                }else{
                    cur--;
                }
                index = digits - cur -1;
                for(int i=0;i<index;i++){
                    begin /= 10;
                }
                cout << begin % 10<< endl;
                break;
            }
        }
    }
}
