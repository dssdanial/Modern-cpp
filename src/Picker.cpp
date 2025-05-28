
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "Picker.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

#include "theCollector.h"

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------

    
      
struct moderncpp::y2023::Picker::Impl
{     
    std::string m_name;
    Picker *m_owner;

    Impl(const Config &config, Picker *o) : m_name(config.name), m_owner(o){}

    std::string name() const
    {
        //std::string n {""};
        //return n;

        return m_name;
    }
      
    void add(const Item &item)
    {

        theCollector::getInstance().receive(item, m_owner);
    }

    bool filter(const std::vector<Item> &set, const std::initializer_list<LABEL>& labels)
    {
        bool r {false};


        for (const auto &item :set){

            if(std::find(labels.begin(), labels.end(), item.label) !=labels.end()){
                add(item);
                r=true;
            }
        }

        return r;
    }

    
};


// --------------------------------------------------------------------------------------------------------------------
// - the class
// --------------------------------------------------------------------------------------------------------------------


namespace moderncpp::y2023 {

    Picker::Picker(const Config &config) : pImpl(std::make_unique<Impl>(config, this)) {}
    Picker::~Picker() = default;

    std::string Picker::name() const
    {
        return pImpl->name();
    }
    bool Picker::filter(const std::vector<Item> &vset, const std::initializer_list<LABEL>& labels)
    {
        return pImpl->filter(vset, labels);
    }       

}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


