int pow(int base, int pow){
	int result = base;
	if (pow == 0)
		return 1;
	for (int i = 1; i < pow; i++){
		result *= base;
	}
	if (pow < 0) result = (int)1/result;
	return result;
}

int mod(int n){
	if (n < 0)
		return -n;
	return n;
}