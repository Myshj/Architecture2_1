#include <iostream>

#include "GenericSet.h"

#include <chrono>

using namespace std;

int main() {

    auto startTime = std::chrono::high_resolution_clock::now();

    GenericSet<int> genericSet1 = GenericSet<int>();
    GenericSet<int> genericSet2 = GenericSet<int>();

    for(int i = 0; i < 20000000; i++)
        genericSet1.add(i);

    for(int i = 10000000; i < 30000000; i++)
        genericSet2.add(i);

    genericSet1.combine(genericSet2);

    genericSet1.intersect(genericSet2);

    genericSet1.differentiate(genericSet2);

    auto endTime = std::chrono::high_resolution_clock::now();

    double workTime = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();

    workTime /= 1000000000.0;

    cout << "Work time: "<< workTime << "seconds" << endl;

    return 0;
}