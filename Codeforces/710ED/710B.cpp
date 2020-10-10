#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
vector<long long int> vp;
long long int aux,n;

cin >> n;
for(int i=0;i<n;i++){
    cin >> aux;
    vp.push_back(aux);
}
sort(vp.begin(),vp.end());

if(n%2){
    cout << vp[n/2];
}else{
    cout << vp[n/2-1];
}
}
