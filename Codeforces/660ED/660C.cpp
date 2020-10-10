#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;




int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,k,aux,maxt=-1,index;
vector<int> v,zeroes;
cin >> n >> k;
zeroes.push_back(-1);
for(int i=0;i<n;i++){
    cin >> aux;
    v.push_back(aux);
    if(!aux) zeroes.push_back(i);
}
zeroes.push_back(n);
int limit = (zeroes.size()-k-1);
if(limit>1){
    for(int i=0;i<limit;i++){
        if((zeroes[i+k+1] - zeroes[i])>maxt){
            maxt = zeroes[i+k+1] - zeroes[i];
            index=i;
        }
    }
    for(int i=(zeroes[index]+1);i<zeroes[index+k+1];i++){
        if(!v[i]) v[i]=1;
    }
    cout << maxt-1 << endl;
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}else{
    cout << n << endl;
    for(int i=0;i<n;i++) cout << "1 ";
}
}
