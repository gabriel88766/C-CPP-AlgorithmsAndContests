
#include <bits/stdc++.h>

using namespace std;



int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
vector<int> v;
map<int,int> mp;
int n,k,bp=0,ep=1,aux,bbp,bep,maxseq=-1,cont;
queue<int> dif;
cin >> n >> k;
for(int i=0;i<n;i++){
    cin >> aux;
    v.push_back(aux);
}
cont=1;
mp[v[0]]++;
if(n!=1){
    while(ep<=(v.size()-1)){
        if(mp[v[ep]]){
            mp[v[ep]]++;
            ep++;
        }else{
            if(cont==k){
                if((ep-bp)>maxseq){
                    maxseq = ep-bp;
                    bbp = bp+1;
                    bep = ep;
                }
                mp[v[bp]]--;
                if(!mp[v[bp]]) cont--;
                bp++;
            }else{
                cont++;
                mp[v[ep]]++;
                ep++;
            }
        }
    }
    if((ep-bp)>maxseq){
        bbp = bp+1;
        bep = ep;
    }
    cout << bbp << " "<< bep;
}else{
    cout << 1 << " " << 1;
}
}

