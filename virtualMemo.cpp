#include "virtualMemo.h"

virtualMemo::virtualMemo(string file){
    this->File = file;

}


int virtualMemo::fullPages(){
    
    
    int posi = 0;
    int pagei = 0;
    ifstream file(this->File, ios::binary);
	file.seekg (0, ios::end);
	int end = file.tellg();
	file.seekg ( 0, ios::beg );
	int res;
    this->currenPage = listPage[pagei];
    
    
    this->pagePostBeg[pagei] = posi*255;
    while(file.tellg()!=end){
		file.read((char *)&res, sizeof(res));
		this->currenPage[posi] = res;
        posi++;
        if(posi>255){
            this->pagePostEnd[pagei] = this->pagePostBeg[pagei]+posi-1;
            pagei++;
            if(pagei>5){ pagei--; break;}
            this->pagePostBeg[pagei] = this->pagePostEnd[pagei-1]+1;
            this->currenPage = listPage[pagei];
            posi = 0; 
        }	
	}this->pagePostEnd[pagei] = (posi==0)?0:this->pagePostBeg[pagei]+posi-1;
    this->lastUpdatePage = 0;
    this->currentPageInt = 0;
    this->currenPage = this->listPage[0];
    file.close();
    return end/4;
}
int virtualMemo::selecPage(int pos){

    for(int i = 0; i < 6 ; i++){
        if(this->pagePostBeg[i]<=pos && this->pagePostEnd[i]>=pos && this->pagePostEnd[i]!=0){
            this->currentPageInt = i;
            this->currenPage = this->listPage[i];
            return pos-(this->pagePostBeg[i]);
        }

    }

    int response = loadNewPage(pos);
    return response;
}

int virtualMemo::loadNewPage(int pos){
    actlastUpdatePage();
    this->currenPage = this->listPage[this->currentPageInt];
    saveCurrentPage();
    ifstream file(this->File, ios::in | ios::binary);
    
    int posi = 0;
    bool finalR = false;
    int currentP = 0;
    file.seekg (0, ios::end);
	int end = file.tellg();
	file.seekg( 0, ios::beg );
	int res;

    while(file.tellg()!=end){
        file.read((char *)&res, sizeof(res));
		this->currenPage[currentP] = res;
        finalR = (posi+currentP==pos)?true:(finalR);
        currentP++;
        if(currentP>255){
            if(finalR){
                this->pagePostBeg[this->lastUpdatePage] = posi;
                int final = posi+currentP-1;
                this->pagePostEnd[this->lastUpdatePage] = final;
                return pos-posi;
            }

            posi = posi+currentP;
            currentP = 0;
        }	
	}
    file.close();
    return -1;

}



void virtualMemo::actlastUpdatePage(){
    this->lastUpdatePage = (this->lastUpdatePage==5)?0:this->lastUpdatePage+1;
    this->currentPageInt = this->lastUpdatePage;
}





void virtualMemo::saveCurrentPage(){

    fstream file ("out.bin", ios::in | ios::out  | ios::binary);
    int res;

    file.seekp( this->pagePostBeg[this->currentPageInt]*4, ios::beg );
    for(int i = 0; i<this->pagePostEnd[this->currentPageInt]-this->pagePostBeg[this->currentPageInt]+1;i++){ 
        res = this->currenPage[i];
        file.write((char *)&res, sizeof(res));
    }
    file.close();



}


void virtualMemo::saveAllPages(){
    for(int i = 0; i<6 ; i++){
        if(this->pagePostEnd[i]!=0){
            this->currentPageInt = i;
            this->currenPage= this->listPage[i];
            saveCurrentPage();
        }     
    }
}

int virtualMemo::get(int pos){
    int itr = selecPage(pos);
    if(itr == -1){
        cout<<"position doesnt exist"<<endl;
        return -1;
    }

    return this->currenPage[itr];

}


void virtualMemo::set(int pos, int data){
    int itr = selecPage(pos);

    if(itr == -1){
        cout<<"position doesnt exist"<<endl;
        return;
    }
    this->currenPage[itr] = data;

}



void virtualMemo::swap(int pos1, int pos2){
    int temp = this->get(pos2);
    this->set(pos2, this->get(pos1));
    this->set(pos1, temp);


}