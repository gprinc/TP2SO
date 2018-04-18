int power(int base, int pow){
	int result = base;
	for (int i = 1; i < pow; i++){
		result *= base;
	}
	return result;
}