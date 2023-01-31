#include <cstring>
#include <iostream>
#include <fstream>
#include "maxPlanarSubset.h"
#include <stdint.h>
#include <time.h>

using namespace std;
#define valueLocation 524287u 
MaxPlanarSubset MaxPlanarSubset;
int main(int argc, char* argv[])
{
    time_t t1, t2;
	t1 = time(NULL);
	printf("reading input...\n");
	FILE* input_file = fopen(argv[1], "r");
	MaxPlanarSubset.fout.open(argv[2], ios::out);
	int inputSize;
	fscanf(input_file, "%d", &inputSize);
	const int size =inputSize >> 1;
	for(int i = 0; i < MaxInput; i++)
	{
		MaxPlanarSubset.plan[i] = new uint[MaxInput];
	}

	MaxPlanarSubset.line = new uint[inputSize];
	for(int i = 0; i < size; i++)
	{
		uint a;
		uint b;
		fscanf(input_file, "%d %d", &a, &b);
		MaxPlanarSubset.line[a] = b;
		MaxPlanarSubset.line[b] = a;
	}
	fclose(input_file);

    // printf("solving...\n");
	const int ans = MaxPlanarSubset.Maxplan(0, inputSize - 1) & valueLocation;
	MaxPlanarSubset.fout << ans << endl;

	// printf("Tracing anwser..\n");
	MaxPlanarSubset.Printans(0, inputSize - 1);

	t2 = time(NULL);
	printf("total time cost: %ld secs\n", t2 - t1);

	MaxPlanarSubset.fout.close();

	return 0;
}