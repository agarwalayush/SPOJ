	#include <stdio.h>

	using namespace std;

	int evaluate(int a, int b, int c)
	{
		
		// read in the three digits (two container sizes & wanted size)
		if(c == a || c == b) // fill a/b, get c
		{
			return 1;
		}
		// fails if
		// 1) requested size (c) is larger than containers can provide (a/b)
		// 2) a is a multiple of b and c is not a multiple of b (ex: a = 3, b = 12, c needs to be a multiple of 3 (3, 6, 9 , 12) or it can't be produced)
		{
			return -1;
		}
		if(c == 0)
		{
			return 0;
		}
		if(a % b == 0) // ex: a=21, b=3. if c is mult of b, determine which is faster
		// a) filling up b, pouring into a...
		// b) filling up a, pouring into b, dumping b, repeat
		{
			int fromBottom = 2 * b;
			int fromTop = 2 * (a/b - c/b);
			return (fromBottom<fromTop)?fromBottom:fromTop;
		}
		if(((c - (a % b)) % b) == 0) // (fill a, pour into b, dump b, repeat until a has c)
		{
			return 2*(a/b) - 2*((c - (a%b))/b); // not verified
		}
		if(c % b == 0) // c multiple of b (fill b, pour into a, repeat)
		{
			return 2*(c/b);
		}
		return -1;
	}

	int main()
	{
		int tests = -1;
		int a = 0;
		int b = 0;
		int c = 0;
		scanf("%d", &tests);
		while(tests > 0)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &c);
			if(a < b) // code written as if a > b
			{
				b ^= a;
				a ^= b;
				b ^= a;
			}
			printf("%d\n", evaluate(a, b, c));
			// wanted size is a container size; fill up container and ret
			
			tests = tests - 1;
		}
		return 0;
	}