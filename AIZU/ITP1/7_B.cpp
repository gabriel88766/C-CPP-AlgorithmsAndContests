#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    int ans;
    cin >> n >> x;
    while(n){
        ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=(i+1);j<=n;j++){
                for(int k=(j+1);k<=n;k++){
                    if(i+j+k == x) ans++;
                }
            }
        }
        cout << ans << "\n";
        cin >> n >> x;
    }
}

