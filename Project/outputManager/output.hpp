//
// Created by Yu-Chun on 2019-02-11.
//

#ifndef SCHEDULE_OUTPUT_HPP
#define SCHEDULE_OUTPUT_HPP

#include "../DS/DS.cpp"

using namespace DS;

class outputManager{
private:
//    String top;
    String plus;
    String stash;
    String nwline;
    String space;
    String abso;

    template <class T>
    String createLine(T aline);

    template <class T>
    String createTop(T firstline);

public:

    outputManager();


    /**
     *
     * @tparam T1 a type like Array<String> object
     * @tparam T2 2-D array like Array<Array<String> > object;
     * @param firstline first line;
     * @param content second line;
     * @return String
     */
    template<class T1, class T2>
    String createform(T1 firstline, T2 content);

    template<class T1, class T2>
    String createform(T1 firstline, T1 secondline, T2 content);


};

#endif //SCHEDULE_OUTPUT_HPP
