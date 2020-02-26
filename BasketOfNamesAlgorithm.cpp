//
// Created by jpmon on 26/02/2020.
//

#include "BasketOfNamesAlgorithm.h"
#include "LinkedList.h"

void BasketOfNamesAlgorithm::executeAlgorithm() {

    // Choose starting point to be middle point
    unsigned const int startingPoint = getMainList().size() / 2;


    getMainList().insert(getMainMap()[startingPoint]);

}

void BasketOfNamesAlgorithm::setMainMap(const std::map<int, std::string> &map) {
    this->mainMap = map;
}

std::map<int, std::string> BasketOfNamesAlgorithm::getMainMap() {
    return this->mainMap;
}

void BasketOfNamesAlgorithm::setMainList(LinkedList<std::string> list) {
    this->mainList = list;
}

LinkedList<std::string> BasketOfNamesAlgorithm::getMainList() {
    return this->mainList;
}