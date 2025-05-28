
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



void test();

int main(int argc, char *argv[]) 
{
    test();
    return 0;
}


#include "Item.h"
#include "Picker.h"
#include "theCollector.h"

using namespace moderncpp::y2023;

std::vector<Item> thewords =
{
    {1, LABEL::one, "the"}, {3, LABEL::one, "to"}, {11,LABEL::one, "and"}, {10, LABEL::four, "universe"}, {9, LABEL::six, "new"},
    {6, LABEL::five, "hello"}, {4, LABEL::one, "the"}, {9, LABEL::one, "the"}, {42, LABEL::six, "language"}, {42, LABEL::five, "c++"},
    {2, LABEL::two, "answer"}, {8, LABEL::two, "life"}, {9, LABEL::five, "world"}, {7, LABEL::two, "of"}, 
    {13, LABEL::two, "is"}, {6, LABEL::two, "question"}, {20, LABEL::five, "modern"}, {10, LABEL::five, "of"},
    {12, LABEL::four, "everything"}, {14, LABEL::three, "42"}, {5, LABEL::three, "ultimate"}, {3, LABEL::six, "strange"} 
};


void test00(const std::vector<Item> &ww)
{
    Picker p01 {{"one"}};
    Picker p02 {{"two"}};

    theCollector::getInstance().clear();

    p01.filter(ww, std::initializer_list<LABEL>({LABEL::one}));
    p01.filter(ww, std::initializer_list<LABEL>({LABEL::two}));
    p02.filter(ww, std::initializer_list<LABEL>({LABEL::three, LABEL::four}));

    theCollector::getInstance().print();

}

void test()
{
    test00(thewords);
}

#if 0


#include <thread>

void test01(const std::vector<Item> &tw)
{
    Picker p01 {{"one"}};
    Picker p02 {{"two"}};
    Picker p03 {{"three"}};
    Picker p04 {{"four"}};

    theCollector::getInstance().clear();

    auto fn = [](Picker *picker, const std::vector<Item> &set, const std::initializer_list<LABEL> &labels)
    {
       picker->filter(set, labels);
    };

#if 0
    theCollector::getInstance().clear();
    fn(&p01, tw, std::initializer_list<LABEL>({LABEL::one}));
    fn(&p02, tw, std::initializer_list<LABEL>({LABEL::two}));
    fn(&p03, tw, std::initializer_list<LABEL>({LABEL::three}));
    fn(&p04, tw, std::initializer_list<LABEL>({LABEL::four}));

    theCollector::getInstance().print();
#endif

#if 1
    theCollector::getInstance().clear();
    std::thread thr01(fn, &p01, tw, std::initializer_list<LABEL>({LABEL::one})); 
    std::thread thr02(fn, &p02, tw, std::initializer_list<LABEL>({LABEL::two}));
    std::thread thr03(fn, &p03, tw, std::initializer_list<LABEL>({LABEL::three}));
    std::thread thr04(fn, &p04, tw, std::initializer_list<LABEL>({LABEL::four}));
    thr01.join();
    thr02.join();
    thr03.join();
    thr04.join();

    theCollector::getInstance().print();
#endif

}

void test()
{
    test01(thewords);
}

#endif


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


