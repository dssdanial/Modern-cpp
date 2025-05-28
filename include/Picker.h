
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __PICKER_H_
#define __PICKER_H_

#include <string>
#include <memory>
#include <cstring>
#include <unordered_set>
#include <vector>

#include "Item.h"

namespace moderncpp::y2023 {

    class Picker
    {
    public:
           
        struct Config
        {            
            std::string name {"Picker"};    
            Config() = default;
            Config(const std::string n) : name(n) {}
        };   

        Picker(const Config &config);                        
        ~Picker(); 
                 
        bool filter(const std::vector<Item> &vset, const std::initializer_list<LABEL>& labels);

        std::string name() const;

        Picker(const Picker&) = delete;               // non copyable
        Picker& operator=(const Picker&) = delete;    // non copyable
        Picker(Picker&&) = delete;                    // non moveable
        Picker& operator=(Picker&&) = delete;         // non moveable                
        
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;  
    }; 

}

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


