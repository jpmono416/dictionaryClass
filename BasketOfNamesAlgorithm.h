//
// Created by jpmon on 26/02/2020.
//

#ifndef DICTIONARYCLASS_BASKETOFNAMESALGORITHM_H
#define DICTIONARYCLASS_BASKETOFNAMESALGORITHM_H

#include <string>
#include <list>
#include <map>
#include "LinkedList.h"


class BasketOfNamesAlgorithm {

    private:
        std::map<int, std::pair<std::string, std::string>> mainMap;
        std::list<std::string> mainList;

        bool checkIfExists(std::string name);
        std::string findNameByNextName(std::string);
        std::string findNameByPreviousName(std::string);



    public:
        void executeAlgorithm();
        const std::list<std::string> &getMainList() const;
        void setMainList1(const std::list<std::string> &mainList);

        //Getters and setters
        std::map<int, std::pair<std::string, std::string>> getMainMap();
        void setMainMap(const std::map<int,std::pair<std::string, std::string>>&);

};


#endif //DICTIONARYCLASS_BASKETOFNAMESALGORITHM_H
