#include <iostream>
#include "cyclebreaker.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cerr << "[ERROR] Invalid parameters!\n";
        cerr << "Usage ./cb <inputfilename> <outputfilename>\n";
        exit(EXIT_FAILURE);
    }

    CycleBreaker cb;
    cb.readFile(argv[1]);
    cb.BreakCycle();
    cb.writeFile(argv[2]);
}