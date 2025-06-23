bool knowbit(ll n, int i){
    ll res = (n>>i) & 1;
    return res;
}

ll tone(ll n, int i){
    n = (1<<i)|n;
    return n;
}

ll tozero(ll n, int i){
    n = ~(1<<i)&n;
    return n;
}

ll onezero(ll n,int i){
    return ((1<<i)^n);
}

void submasks_of_anumber(ll n){
    // submask بيبقي فيه الوحايد فقط الموجودة فال ماسك الاصلي
    ll tmp=n;
    while(n!=0){
        cout << n << end1;
        n=tmp&(n-1);
    }
    cout << n << end1;
}

// mask == binary rep of a number
// complete search on string s of size n to get all subsets of the string
for(int i = 0 ; i<(1<<n) ;i++){
  for(int j = 0 ; j<n ; j++){
    if(knowbit(i,j)){
      v.push_back(s[j]);
    }   
  }
}

// any number is of base 10 -> (124 == 4*10^0 + 2*10^1 + 1*10^2)
// to print all digits of a number take mod 10 and then divide by 10


// we will make prefix sum for appearence of every bit in the whole array , if we calculate pref[l][i]-pref[r-1][i] and it is = l-r+1 then the ith bit in the array is on in all nums in the array
const int bits=30;
int pref[N][bits];
int a[N];
void Buildprefix(int n){   
    for(int i=0; i< n; i++){
        for(int j=0; j<30; j++){
            if(a[i]&(1<<j)){
                pref[i+1][j]=pref[i][j]+1;
            }
            else{
                pref[i+1][j]=pref[i][j];
            }
        }
    }
}
// also to print binary rep of a number take mod 2 then divide by 2
// << left shift is mult by 2 (adding 0 to the end of the mask) and right shift >> is dividing by 2 (erasing the last bit of the mask)
// &,|,~ are bitwise operations work with the mask of the number but &&,||,! are logical operation work with normal numbers only
