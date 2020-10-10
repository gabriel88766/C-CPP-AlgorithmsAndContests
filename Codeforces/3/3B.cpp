#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second


typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int main(){
    int n,v,w,t,S=0,aux,nc,nk,cp,kp;
    pair<int,int> lk1,lk2,lc1;
    vector <int> index;
    vector <pii> k,c; // 1 kayak 2 catamaran
    cin >> n >> v;
    for(int i=0;i<n;i++){
        cin >> t >> w;
        if(t==1){
            k.push_back(make_pair(w,i+1));
        }else{
            c.push_back(make_pair(w,i+1));
        }
    }
    sort(c.begin(),c.end());
    sort(k.begin(),k.end());
    aux = c.size();
    nc = min(aux,v/2);
    aux = k.size();
    nk = min(aux,(v-nc*2));
    for(int i=(c.size()-1);i>=(c.size()-nc)&&i>=0;i--){
        S+=c[i].st;
    }
    cp=c.size()-nc;
    for(int i=(k.size()-1);i>=(k.size()-nk)&&i>=0;i--){
        S+=k[i].st;
    }
    kp=k.size()-nk-1;
    int newS;
    while((kp-1)>=0){
        if(cp<=(c.size()-1)){
            newS = S + k[kp].st + k[kp-1].st - c[cp].st;
            if(newS>S){
                S=newS;
                nc-=1;
                nk+=2;
                kp-=2;
                cp+=1;
            }else{
                break;
            }
        }else break;
    }

    if(kp>=0){
        if(newS>S){
                S=newS;
                nc-=1;
                nk+=1;
            }
    }
    cout << S << endl;
    for(int i=(k.size()-1);i>=(k.size()-nk)&&i>=0;i--){
        cout << k[i].nd << " ";
    }
    for(int i=(c.size()-1);i>=(c.size()-nc)&&i>=0;i--){
       cout << c[i].nd << " ";
    }



    return 0;
}
