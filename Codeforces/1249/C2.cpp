#include<bits/stdc++.h>

#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))
typedef long long ll;
using namespace std;

const int N = 1e5+3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

long long int pot3[40], pot2[40];

void init(){
    pot3[0] = 1;
    pot2[0] = 1;
    for(int i=1;i<40;i++){
        pot3[i] = 3*pot3[i-1];
        pot2[i] = 2*pot2[i-1];
    }
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
init();
int q;
cin >> q;
while(q--){
    long long int n, masklo = 0, cur = 0,ans = 0;
    cin >> n;
    for(int i=39;i>=0;i--){
        if((cur + pot3[i]) < n){
            cur += pot3[i];
            masklo += pot2[i];
        }
    }
    masklo++;
    for(int i=0;i<40;i++){
        if(masklo & pot2[i]){
            ans += pot3[i];
        }
    }
    cout << ans << "\n";

}
}

 