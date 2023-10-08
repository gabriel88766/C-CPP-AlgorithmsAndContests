#include <bits/stdc++.h>
 
using namespace std;
 
int tt[5];
 
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        tt[aux]++;
    }
    int ans = 0;
    int x = min(tt[3], tt[1]);
    ans += x, tt[3] -= x, tt[1] -= x;
    ans += tt[4];
    if(tt[1]){
        ans += tt[1] / 4;
        if(tt[1] % 4 == 2 || tt[1] % 4 == 1){
            if(tt[2]) tt[2]--;
            ans++;
        }else if(tt[1] % 4 == 3) ans++;
    }else{
        ans += tt[3];
    }
    ans += tt[2] / 2;
    if(tt[2] % 2){
        ans++;
    }
    cout << ans;
}