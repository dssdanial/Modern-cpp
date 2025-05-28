
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __THECOLLECTOR_H_
#define __THECOLLECTOR_H_

#include <string>
#include <memory>
#include <cstring>

#include "Item.h"
#include "Picker.h"

namespace moderncpp::y2023 {

    class theCollector
    {
    public:
        static theCollector& getInstance();   

        enum class PrintMode { orderedBYid };
        bool clear();
        bool receive(const Item& item, Picker* from);
        bool print(PrintMode pm = PrintMode::orderedBYid);

        theCollector(const theCollector&) = delete;               // non copyable
        theCollector& operator=(const theCollector&) = delete;    // non copyable
        theCollector(theCollector&&) = delete;                    // non moveable
        theCollector& operator=(theCollector&&) = delete;         // non moveable                
        
    private:
        theCollector();
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;  
    }; 

}

    
#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


