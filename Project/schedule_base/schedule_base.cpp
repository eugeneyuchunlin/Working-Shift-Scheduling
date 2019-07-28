//
// Created by Yu-Chun on 2019-02-25.
//

#ifndef __SCHEDULE_BASE__
#define __SCHEDULE_BASE__

#include "../schedule_base/schedule_base.hpp"

deque<deque<String> >__Schedule_base__::load(string file_name) {
    ifstream file;
    String sline;
    deque<String> lines;

    file.open(file_name , std::fstream::in);
    if(file.is_open()){
        while(!file.eof()){
            file>>sline;
            lines.push_back(sline);
        }
    }else{
        // Here throw exception, use try-catch to handle and generate the new calender for the correct month
//        string f = ("calender" + to_String(month) + ".csv");
        fstream::failure e(file_name + " open failure, Please check the file name");
        throw e;
    }
    return lineSplit(lines);
//    return lines;

}

deque<deque<String> > __Schedule_base__::lineSplit(deque<String> lines) {
    deque<deque<String> > content;
    for(int i = 0; i < lines.size(); i++){
        content.push_back(lines[i].split(","));
    }
    return  content;
}


#endif