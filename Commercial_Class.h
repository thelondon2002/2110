#ifndef COMMERCIAL_CLASS_H
#define COMMERCIAL_CLASS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Commercial {
        private:
            int population;
            int workers;
            char symbol = 'C';
    
        public:
            int availableGoods;
            int availableWorkers;
            
        char GetSymbol()
        {
            return symbol;
        }

        void IncreasePopulation() {
        if (population == 0) {
            if ((availableWorkers >= 1 && availableGoods >= 1) ||
                (availableWorkers >= 1 && availableGoods >= 1)) {
                population += 1;
                availableWorkers -= 1;
                availableGoods -= 1;
            }
        } else if (population == 1 && availableWorkers >= 1 && availableGoods >= 1) {
            population += 1;
            availableWorkers -= 1;
            availableGoods -= 1;
        }
    }
};

#endif
