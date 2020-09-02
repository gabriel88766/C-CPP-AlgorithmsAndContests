//greedy
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int d,st;
cin >> d >> st;
vector <int> minv;
vector <int> maxv;
int mint=0,maxt=0,curmin,curmax;
for(int i=0;i<d;i++){
    cin >> curmin >> curmax;
    mint +=curmin;
    maxt +=curmax;
    minv.push_back(curmin);
    maxv.push_back(curmax);
}
if((maxt < st) || (mint > st)){
    cout << "NO";
}else{
    int cont = st-mint;
    int j=0;
    while(cont!=0){
        int cur = maxv[j]-minv[j];
        if(cur<=cont){
            cont-=cur;
            minv[j]=maxv[j];
            j++;
        }
        else{
            minv[j]+=cont;
            cont=0;
        }
    }
    cout << "YES" <<endl;
    for(int i=0;i<d;i++){
        cout << minv[i] << " ";
    }

}

}

