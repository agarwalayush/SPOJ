#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h> // strlen

using namespace std;

void incrByOne(char incr[1000000])
{
	// incomplete
	int right = strlen(incr) - 1;
	if(incr[right] < '9')
	{
		incr[right] = incr[right] + 1;
	}
	else // 9s at end
	{
		while(incr[right] == '9' && right > 0)
		{
			incr[right] = '0';
			right = right - 1;
		}
		if(right == 0 && incr[right] < '9')
		  {
		    incr[right] = incr[right] + 1;
		  }
		else if(right > 0)
		{
			incr[right] = incr[right] + 1;
			right = right - 1;
		}
		else // all 9s; shift over
		{
		  incr[0] = '0';
       			int shiftRight = strlen(incr);
			incr[shiftRight+1] = 0;
			while(shiftRight > 0)
			{
				incr[shiftRight] = incr[shiftRight-1];
				shiftRight = shiftRight - 1;
			}
			incr[shiftRight] = '1'; // 999->1000
			
		}
	}
}

bool isPalindrome(char numberCheck[1000000])
{
	int start = 0;
	int end = strlen(numberCheck) - 1;
	while(start <= end)
	{
		if(numberCheck[start] != numberCheck[end])
		{
			return false;
		}
		start = start + 1;
		end = end - 1;
	}
	return true;
}

bool nextNumber()
{
	char charRep[1000000];
	int numberSize = 0;
	scanf("%s", &charRep);
	incrByOne(charRep);
	int left = 0;
	int right = strlen(charRep) - 1;
	int lastMatch = 0;
	while(!isPalindrome(charRep))
	{
		//printf("\t%s is not a palindrome.\n", charRep);
		if(charRep[left] >= charRep[right]) // ex: 550, 5 > 0, incr 0 to be 5
		{
			charRep[right] = charRep[left];
		}
		else if(charRep[left] < charRep[right])
		{
			
			charRep[right] = '0';
			if(charRep[right-1] != '9') // ex: 516->520
			{
		     		charRep[right-1] = charRep[right-1] + 1;
				lastMatch = right;
				charRep[right] = charRep[left];
			}
			else // ex: 51992->52000
			{
				right = right - 1;
				while(charRep[right] == '9')
				{
					charRep[right] = '0';
					right = right - 1;
				}
				charRep[right] = charRep[right] + 1;
				// start at beginning
				left = strlen(charRep) - lastMatch;
				right = lastMatch;
			}
		}
		left = left + 1;
		right = right - 1;
		if(left > right)
		{
			left = 0;
			right = strlen(charRep) - 1;
		}
	}
	printf("%s\n", charRep);
	return true;
}

int main()
{
	int testCases = 0;
	cin >> testCases;
	while(testCases > 0)
	{
		nextNumber();
		testCases--;
	}
	return 0;
}
