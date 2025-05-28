
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "theCollector.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <memory>
#include <iostream>
#include <algorithm>    // std::sort


// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------



struct moderncpp::y2023::theCollector::Impl
{

    //Impl() = default;
    std::vector<Item> items;

    bool clear()
    {
        //bool r {false};
        //return r;
        items.clear();
        return true;
    }   

    bool receive(const Item& item, Picker* from)
    {
        //bool r {false};
        //return r;

        items.push_back(item);
        return true;

    }


    bool print(PrintMode pm)
    {
        //bool r {false};
        //std::cout << "TODO: fill Picker::Impl and theCollector::Impl ... " << std::endl;
        //return r;

        if(pm == PrintMode::orderedBYid){
            std::sort(items.begin(), items.end(), [](const Item &a, const Item &b) { return a.id<b.id;});
        
            for(const auto &item: items){

                std::cout<<item.word<<" ";
            }
            std::cout << std::endl;
        
        
        }

        return true;

    }
    
};

// --------------------------------------------------------------------------------------------------------------------
// - the class
// --------------------------------------------------------------------------------------------------------------------


namespace moderncpp::y2023 {

    theCollector& theCollector::getInstance()
    {
        static theCollector instance;
        return instance;
    }

    theCollector::theCollector()
    {
        pImpl = std::make_unique<Impl>();
    }  
                    
    bool theCollector::clear()
    {
        return pImpl->clear();
    }

    bool theCollector::receive(const Item& item, Picker* from)
    {
        return pImpl->receive(item, from);
    }

    bool theCollector::print(PrintMode pm)
    {
        return pImpl->print(pm);
    }
}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


