#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

char ans[20];
int n;
void changeandprint(int pos, int parity){
    if((n-1) == pos){
        ans[pos] = ans[pos] = '0' ? '1' : '0';
   }else{
        if(parity == 0){
            if(ans[pos] == '0' && ans[pos+1] == '0'){
                ans[pos+1] = '1';
            }else if(ans[pos] == '0' && ans[pos+1] == '1'){
                ans[pos] = '1';
            }else {
                ans[pos+1]='0';
            }
        }else{
            if(ans[pos] == '1' && ans[pos+1] == '0'){
                ans[pos+1] = '1';
            }else if(ans[pos] == '1' && ans[pos+1] == '1'){
                ans[pos] = '0';
            }else {
                ans[pos+1]='0';
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int pos, aux, parity;
    cin >> n;
    for(int i=0;i<n; i++){
        ans[i] = '0';
    }
    cout << ans << "\n";
    for(int i=1;i < (1 << n); i++){
        pos = 0;
        aux = i;
        while( !(aux % 2)) {
            aux /= 2;
            pos++;
        }
        if(pos & 1){
            pos--; 
            aux <<= 1;
        }
        changeandprint(pos, (aux % 8) > 4 ? 1 : 0);
    }
}
