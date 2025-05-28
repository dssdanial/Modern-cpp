
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __ITEM_H_
#define __ITEM_H_

#include <string>

namespace moderncpp::y2023 {

    enum class LABEL { one = 1, two, three, four, five, six, seven, none};

    struct Item
    {
        size_t id {0};
        LABEL label {LABEL::none};
        std::string word {"dummy"};   
    };
 
}

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


