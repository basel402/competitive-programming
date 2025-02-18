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
// also to print binary rep of a number take mod 2 then divide by 2
// << left shift is mult by 2 (adding 0 to the end of the mask) and right shift >> is dividing by 2 (erasing the last bit of the mask)
// &,|,~ are bitwise operations work with the mask of the number but &&,||,! are logical operation work with normal numbers only
