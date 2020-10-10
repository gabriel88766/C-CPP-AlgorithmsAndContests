
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< long long int, long long int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
# define PI          3.141592653589793238462643383279502884L

using namespace std;

bool func(par a, par b){
   int prodvect = a.st*b.nd - a.nd*b.st;
   if(prodvect < 0) return false;
   else return true;
}


long double dif(par a,par b){
long double difS = atan2l(b.nd,b.st) - atan2l(a.nd,a.st);
if(difS<0) difS=difS+PI+PI;
return difS;

}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
vector<par> q1,q2,q3,q4,sorted,unf;
par v1,v2;
long long int n,x,y;
long double mindif=INF,curdif;
cin >> n;
for(int i=0;i<n;i++){
    cin >> x >> y;
    unf.push_back(mp(x,y));
    if(x>=0 && y>=0){
        q1.push_back(mp(x,y));
    }else if(x<0 && y>=0){
        q2.push_back(mp(x,y));
    } else if(x<0 && y<0){
        q3.push_back(mp(x,y));
    }else{
        q4.push_back(mp(x,y));
    }
}
sort(q1.begin(),q1.end(),func);
sort(q2.begin(),q2.end(),func);
sort(q3.begin(),q3.end(),func);
sort(q4.begin(),q4.end(),func);
for(int i = 0;i< q1.size();i++){
    sorted.push_back(q1[i]);
}
for(int i = 0;i< q2.size();i++){
    sorted.push_back(q2[i]);
}
for(int i = 0;i< q3.size();i++){
    sorted.push_back(q3[i]);
}
for(int i = 0;i< q4.size();i++){
    sorted.push_back(q4[i]);
}
sorted.push_back(sorted[0]);
for(int i = 0;i< sorted.size()-1;i++){
    curdif = dif(sorted[i],sorted[i+1]);
    if(curdif < mindif){
        mindif=curdif;
        v1=sorted[i];
        v2=sorted[i+1];
    }
}

for(int i = 0;i< unf.size();i++){
    if(unf[i]==v1){
        cout << i+1 << " ";
    }
    if(unf[i]==v2){
        cout << i+1 << " ";
    }
}

}
