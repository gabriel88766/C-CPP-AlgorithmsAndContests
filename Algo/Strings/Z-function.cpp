int z[200005]; //Lenght of greatest prefix(sz) equals substr (i, i+sz-1) 
//Z-function
void zfunc(string s){
    int lm = 0, rm = 0;
    for(int i=0;i<s.size();i++) z[i] = 0;
    for(int i=1;i<s.size();i++){
        if(i < rm){
            z[i] = min(z[i-lm], rm-i);
        }
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) z[i]++;
        if(i + z[i] > rm){
            rm = i + z[i];
            lm = i;
        }
    }
}