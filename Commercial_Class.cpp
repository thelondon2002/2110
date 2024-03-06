#include "Commercial_Class.h"
#include "SimSystem.h"
#include <iostream>
using namespace std;

// Default Constructor
Commercial::Commercial(const Cell& cell, int population, int availableGoods, int availableWorkers) 
    : cell(cell), population(population), availableGoods(availableGoods), availableWorkers(availableWorkers) {}

// Increase population based on  given set of rules
void Commercial::IncreasePopulation(SimSystem& simSystem, int x, int y) {
    //Checks initial condition if population == 0
    char currentCell = cell.GetSymbol();

    if (cell.GetPopulation() == 0)
    {
        // Check if the cell is adjacent to a powerline or a cell with population > 0
        bool adjacentToPowerline = false;
        bool adjacentToPopulation = false;

        // Check neighbor cells
        for (int j = -1; j <= 1; ++j) {
            for (int k = -1; k <= 1; ++k) { 
                int xj = x + j;
                int yj = y + k;  


                // Checks if neighbor is within the simSystem bounds
                if (xj >= 0 && xj < simSystem.GetRegion().size() && yj >= 0 && yj < simSystem.GetRegion()[0].size()) {
                    // Check if neighbor is a powerline
                    if (simSystem.GetRegion()[xj][yj].GetType() == Cell::powerline) {
                        adjacentToPowerline = true;
                    }

                    // Check if neighbor has population >= 1
                    if (simSystem.GetRegion()[xj][yj].GetPopulation() >= 1) {
                        adjacentToPopulation = true;
                    }
                }
            }
        }

        // If statement to check if cell is adjacent to a powerline or population, then increases population
        if (adjacentToPowerline || adjacentToPopulation) {
            cell.SetPopulation(cell.GetPopulation() + 1);
            availableWorkers += 1;
            availableGoods += 1;
        }
    }
    else if (cell.GetPopulation() == 1)
    {
        // Checks if cell is adjacent to at least two cells with population >= 1
        int adjacentPopulationCount = 0;

        // Check all neighbor cells
        for (int j = -1; j <= 1; ++j) {
            for (int j = -1; j <= 1; ++j) {
                int xj = x + j;
                int yj = y + j;

                //skips current cell
                if (xj == x && yj == y) continue;

                //If statement to check if the neighbor is within the simSystem bounds
                if (xj >= 0 && xj < simSystem.GetRegion().size() && yj >= 0 && yj < simSystem.GetRegion()[0].size()) {
                    // Check if the neighbor has population >= 1
                    if (simSystem.GetRegion()[xj][yj].GetPopulation() >= 1) {
                        adjacentPopulationCount++;
                    }
                }
            }
        }

        // If the cell is adjacent to at least two cells with population >= 1, increase population
        if (adjacentPopulationCount >= 2) {
            cell.SetPopulation(cell.GetPopulation() + 1);
            availableWorkers += 1;
            availableGoods += 1;
        }
    }
}
