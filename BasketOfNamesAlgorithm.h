//
// Created by jpmon on 26/02/2020.
//

#ifndef DICTIONARYCLASS_BASKETOFNAMESALGORITHM_H
#define DICTIONARYCLASS_BASKETOFNAMESALGORITHM_H

#import <string>
#include <list>
#include <map>
#include "LinkedList.h"


class BasketOfNamesAlgorithm {

    private:
        std::map<int, std::string> mainMap;
        LinkedList<std::string> mainList;

    public:
        void executeAlgorithm();

        //Getters and setters
        std::map<int, std::string> getMainMap();
        void setMainMap(const std::map<int,std::string>&);
        LinkedList<std::string> getMainList();
        void setMainList(LinkedList<std::string>);

};


#endif //DICTIONARYCLASS_BASKETOFNAMESALGORITHM_H
