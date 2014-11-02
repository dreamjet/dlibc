int Combinatorics_factorial(int n){
	int r = 1;
	for(;n>0;n--){
		r = r*n;
	}
	return r;
}
int Combinatorics_factorial2(int n,int m){
	int r = 1;
	for(;n>m-1;n--){
		r = r*n;
	}
	return r;
}
int Combinatorics_A(int n,int m){
	return Combinatorics_factorial2(n,m);
}
int Combinatorics_C(int n,int m){
	return Combinatorics_A(n,m)/Combinatorics_factorial(m);
}
