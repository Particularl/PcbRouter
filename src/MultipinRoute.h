#ifndef PCBROUTER_MULTI_PIN_ROUTE_H
#define PCBROUTER_MULTI_PIN_ROUTE_H

#include <vector>
#include "GridPath.h"
#include "GridPin.h"
#include "globalParam.h"
#include "point.h"

class MultipinRoute {
   public:
    int netId = -1;
    int gridNetclassId = -1;
    float currentRouteCost = 0.0;
    std::vector<Location> features;  // Make this obsolete, please
    std::vector<GridPin> mGridPins;

    //derived from features, doesn't guarantee updated
    // Please replace features with mGridPaths
    std::vector<GridPath> mGridPaths;
    //TODO
    // std::vector<Location> vias;

    void featuresToGridPaths();
    int getGridNetclassId() const { return gridNetclassId; }
    int getNetId() const { return netId; }
    const std::vector<GridPath> &getGridPaths() const { return mGridPaths; }

    GridPath &getNewGridPath() {
        mGridPaths.push_back(GridPath{});
        return mGridPaths.back();
    }
    GridPin &getNewGridPin() {
        mGridPins.push_back(GridPin{});
        return mGridPins.back();
    }

    double getRoutedWirelength();
    int getRoutedNumVias();

    MultipinRoute() {
    }
    MultipinRoute(const int netId) {
        this->netId = netId;
    }
    MultipinRoute(const int netId, const int gridNetclassId) {
        this->netId = netId;
        this->gridNetclassId = gridNetclassId;
    }
};

#endif