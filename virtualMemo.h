
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

#ifndef VIRTUAL_MEMO_H
#define VIRTUAL_MEMO_H

class virtualMemo{

    public:
        virtualMemo(string);
        int fullPages();
        int get(int);
        void set(int,int);
        void swap(int, int);
        void saveAllPages();
    private:
        string File;
        int currentPageInt;
        int lastUpdatePage;
        int pagePostBeg[6];
        int pagePostEnd[6] = {0,0,0,0,0,0};
        int listPage[6][256];
        int *currenPage;
        int selecPage(int);
        int loadNewPage(int);
        void saveCurrentPage();
        void actlastUpdatePage();




        
};





#endif