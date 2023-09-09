#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include "insertionsort.cpp"
#include "bubblesort.cpp"
#include "selectionsort.cpp"
#include "quicksort.cpp"
using namespace std;
void split(string line, vector<string>* vector){
    string temp;
    for(int i=0 ; i< line.length(); i++){
        if(line[i]==','){
            vector->push_back(temp);
            temp = "";
        }else{temp.append(string(1,line[i]));}  
    }

}


void conversionArchivo(string input, string output){
    string line;
    int num;
    vector<string> vector;
    ifstream infile(input);
    ofstream outfile(output, ios::out  | ios::binary);//| ios::app


    while ( getline (infile,line) )
    {
        split(line,&vector);
        
        for(int i=0 ; i< vector.size(); i++){
            num = stoi(vector[i]);
            outfile.write((char *)&num, sizeof(num));

        }
        vector.clear();


    }

    infile.close();
    outfile.close();

}

bool verification(int argc, char** argv ){

    if (argc < 7) {
        cout <<  "arguments missing"<< endl;
        return false;
    } else if (argc > 7) {
        cout << "too many arguments"<< endl;
        return false;
    }
    if (strcmp(argv[1], "-i")!=0) {
        cout << argv[1] << ": command not found" << endl;
        return false;
    }
    cout << "opening " << argv[2] << endl;
    if (strcmp(argv[5], "-o")!=0) {
        cout << argv[5] << ": command not found" << endl;
        return false;
    } 
    conversionArchivo(argv[2],argv[6]);
    virtualMemo arr = virtualMemo(argv[6]);

    if(strcmp(argv[3], "-a")!=0) {
        cout << argv[3] << ": command not found" << endl;
        return false;
    } 
    int n = arr.fullPages();
    if (strcmp(argv[4], "QS")==0) {
        cout << "using quicksort" << endl;
        quickSort(&arr,0,n);
    } else if (strcmp(argv[4], "IS")==0) {
        cout << "using insertion sort" << endl;
        insertionSort(&arr,n);
    } else if (strcmp(argv[4], "SS")==0) {
        cout << "using selection sort" << endl;
        selectionSort(&arr,n);
    } else if (strcmp(argv[4], "PS")==0) {
        cout << "using proposed sort" << endl;
        bubbleSort(&arr,n);
    } else {
        cout << argv[4] << ": sort not found" << endl;
        return false;
    }arr.saveAllPages();


    cout << "saving result in " << argv[6] << endl; 

    return true;


}


void showBinFile(string fileName){
    ifstream file(fileName, ios::in | ios::binary);
    file.seekg (0, ios::end);
	int end = file.tellg();
	file.seekg ( 0, ios::beg );
	int res;
	while(file.tellg()!=end){
		file.read((char *)&res, sizeof(res));
		cout<<res<<",";
		
	}
    cout<<endl;

}