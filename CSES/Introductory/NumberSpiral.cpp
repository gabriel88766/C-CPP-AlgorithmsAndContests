#include <bits/stdc++.h>
using namespace std;

int main(){
long long int a,b,maxi;
long long int ans;
int t;
cin >> t;
while(t--){
    cin >> a >> b;
    maxi = max(a,b);
    ans=(maxi-1)*(maxi-1);
    if(maxi%2){
        if(maxi==a && maxi!=b){
            ans+=b;
        }else if(maxi==b && maxi!=a){
            ans+=(maxi+(maxi-a));
        }else{
            ans+=(maxi);
        }
    }else{
        if(maxi==a && maxi!=b){
            ans+=(maxi+(maxi-b));
        }else if(maxi==b && maxi!=a){
            ans+=a;
        }else{
            ans+=(maxi);
        }
    }
    cout << ans << endl;
}
}
