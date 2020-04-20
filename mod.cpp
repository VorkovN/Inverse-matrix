int mod(int a, int b){
    int i = -1;
    if (a<0 || b<0){
        while(true){
            if (b*i<=a){
                return a-b*i;
            }
            i--;
        }
    }else{
        return a % b;
    }
}