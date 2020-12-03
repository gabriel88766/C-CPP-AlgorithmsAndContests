#include <bits/stdc++.h>
using namespace std;

int main(){
long long int n,S=0,aux;
vector<int> v;
cin >> n;
for(int i=0;i<n;i++){
    cin >> aux;
    v.push_back(aux);
}
for(int i=1;i<n;i++){
    if(v[i]<v[i-1]){
        S+=(v[i-1]-v[i]);
        v[i]=v[i-1];
    }
}
cout << S;
}
