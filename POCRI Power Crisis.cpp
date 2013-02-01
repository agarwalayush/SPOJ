#include <stdio.h>
#include <iostream>

using namespace std;

int findSwitch(int regions)
{
	int regionSkip = 4;
	int regionSkipTemp = regionSkip + 1;
	int checkedRegion[regions];
	while(true) // would be impossible if answer was greater than input
	{
		regionSkip = regionSkip + 1;
		//cout << "\nCurrent regionSkip: " << regionSkip << " with regions: " << regions << endl;
		//cout << "     ";
		int missing = regions;
		int currentRegion = 0;
		for(int needWater = 0; needWater < regions; needWater++)
		{
			checkedRegion[needWater] = 0;
		} // for(int i = 0; i < regions; i++)
		// set first region (start) to true, decrement missing counter
		//cout << "0, ";
		checkedRegion[0] = 1;
		missing = missing - 1;
		// turn regions off until
		// 1) current region is last region and is not last
		// 2) all checked, last region was last
		while(missing > 0)
		{
			regionSkipTemp = regionSkip;
			while(regionSkipTemp != 0) // don't count regions with power already off
			{
				currentRegion = (currentRegion + 1) % regions;
				if(checkedRegion[currentRegion] == 0)
				{
					regionSkipTemp = regionSkipTemp - 1;
				}
			}
			if(checkedRegion[currentRegion] == 0)
			{
				//printf("%d, ", currentRegion);
				checkedRegion[currentRegion] = 1;
				missing = missing - 1;
			}
			else
			{
				//printf("%d (skip), ", currentRegion);
			}
			if(currentRegion == 12) // last region
			{
				if(missing == 0)
				{
					return regionSkip;
				}
				else
				{				
					break;
				}
			} // if(currentRegion == (regions - 1)) // last reigon
		} // while(missing > 0)
		//cout << endl;
	}
}

int main()
{
	int regions = -1;
	scanf("%d", &regions);
	while(regions != 0)
	{
		printf("%d\n", findSwitch(regions));
		scanf("%d", &regions);
		//break;
	}
	return 0;
}