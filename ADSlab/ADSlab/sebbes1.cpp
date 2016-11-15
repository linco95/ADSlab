#include "sebbes1.h"

void Sebbes1::BucketSort(vector<int> v)
{
	vector<int> w;
	int k = 0;
	printf(" ");

	for (int i = 0; i < v.size(); i++)
	{
		//printf("#%i and size %i\n ", i, v[i], v[i]);
		if ((int)k < (int)v[i]) 
		{
			k = v[i];
		}
	}
	//printf("largest has size %i\n\n", k,(int)k);


	w.resize((int)k+1);

	for (int i = 0; i < w.size(); i++)
	{
		w[i] = 0;
		//printf("%i\n", w[i]);
	}

	for (int i = 0; i < v.size(); i++)
	{
		w[v[i]] = w[v[i]] + 1;
		//printf("%i", w[v[i]]);
	}
	//printf("\n");
	printf("\n Unsorted list: ");

	for (int i = 0; i < v.size(); i++)
	{
		printf("%i ", v[i]);
	}
	printf("\n Sorted list:   ");
	for (size_t i = 0; i < w.size(); i++)
	{
		for (size_t j = 0; j < w[i]; j++)
		{
			printf("%i ", i);
		}
	}
	printf("\n");
	printf("\n");

}
