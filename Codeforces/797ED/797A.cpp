#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,k;
vector<int> factors;
cin >> n >> k;
int aux = n;
for(int i=2;i<=n;i++){
    if(aux%i){
        continue;
    }else{
        while(!(aux%i)){
            factors.push_back(i);
            aux/=i;
        }
        if(aux==1) break;
    }
}
if(factors.size()<k) cout << -1;
else{
    while(factors.size()>k){
        int fac = factors[factors.size()-1];
        factors.pop_back();
        factors[factors.size()-1]*=fac;
    }
    for(int i=0;i<factors.size();i++){
        cout << factors[i] << " ";
    }
}

}
