//
// Created by jpmon on 26/02/2020.
//

#include "BasketOfNamesAlgorithm.h"
#include "LinkedList.h"

void BasketOfNamesAlgorithm::executeAlgorithm() {

    // Choose starting point to be middle point
    unsigned int first = getMainList().size() / 2;
    unsigned int current = first;
    bool done = false;
    auto it = mainList.begin();
    auto lowerBound = mainList.begin()--;
    bool goingEast = false;
    bool madeChanges;
    std::string currentName = getMainMap()[current].first;

    do {
        madeChanges = false;
        if(currentName.empty())
        {
            goingEast = !goingEast;
            current = first;
            it = mainList.begin();
        } else if(!checkIfExists(currentName))
        {
            mainList.emplace(it,currentName);
            madeChanges = true;
        }

        if(goingEast)
        {
            currentName = findNameByNextName(currentName);
            advance(it, -1);
        } else
        {
            currentName = findNameByPreviousName(currentName);
            advance(it, 1);
        }

        if(!madeChanges)
            done = true;
    } while(!done && it!=mainList.end() && it!=lowerBound);
}



std::string BasketOfNamesAlgorithm::findNameByNextName(std::string name) {

    for(auto &&elem : mainMap)
    {

        // elem.first is the key, second is the value but since the value is a pair we need its individual vars
        if(elem.second.second == name)
            return elem.second.first;
    }
};

std::string BasketOfNamesAlgorithm::findNameByPreviousName(std::string name) {
    for(auto &&elem : mainMap)
    {
        if(elem.second.first == name)
            return elem.second.second;
    }
}



bool BasketOfNamesAlgorithm::checkIfExists(std::string name) {
    bool exists = false;

    for(std::string temp : mainList)
    {
        if(name == temp)
        {
            exists = true;
        }
    }
    return exists;
}

void BasketOfNamesAlgorithm::setMainMap(const std::map<int, std::pair<std::string, std::string>> &map) {
    this->mainMap = map;
}

std::map<int, std::pair<std::string, std::string>> BasketOfNamesAlgorithm::getMainMap() {
    return this->mainMap;
}

void BasketOfNamesAlgorithm::setMainList1(const std::list<std::string> &mainList) {
    BasketOfNamesAlgorithm::mainList = mainList;
}

const std::list<std::string> &BasketOfNamesAlgorithm::getMainList() const {
    return mainList;
}

