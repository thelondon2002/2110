#ifndef COMMERCIAL_CLASS_H
#define COMMERCIAL_CLASS_H
#include "Cell.h"
#include "SimSystem.h"

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Commercial {
private:
    Cell cell;
    int population;
    int workers;

public:
    int availableGoods;
    int availableWorkers;

    // Default Constructor
    Commercial::Commercial(const Cell& cell, int population, int availableGoods, int availableWorkers) 
    : cell(cell), population(population), availableGoods(availableGoods), availableWorkers(availableWorkers) {}


    // Increase population based on rules
    void Commercial::IncreasePopulation(SimSystem& simSystem, int x, int y);


};

#endif

