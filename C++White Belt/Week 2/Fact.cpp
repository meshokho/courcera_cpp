int Factorial(int x) {
	if (x < 0)
		return 1;
	if (x == 0)
		return 1;
	if (x == 1)
		return 1;
	return x * Factorial(x - 1);
}