#include <iostream>
#include <string.h>
#include <string>

#include <gtest/gtest.h>


//#include "virtualMemo.h"
#include "Verification.cpp"
using namespace std;



int main(int argc, char** argv) {
   if(!verification(argc,argv)){return -1;}

   /* Muestra el resultado en consola first push with Bash*/

   showBinFile(argv[6]);








   
   return 0;
}