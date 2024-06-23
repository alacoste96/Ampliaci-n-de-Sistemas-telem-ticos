#include <iostream>

enum{
    ROWS = 9
};

bool isAsteriscSegment(int j, int nspaces, int nasterisc){
    return j >= nspaces / 2 && j < nspaces / 2 + nasterisc;
}

int main(){
    int i, j, numspaces = 8, numasterisc = 1;
    bool pastmiddle = false;

    for(i = 0; i < ROWS; i++){
        for(j = 0; j < ROWS; j++){
            if (isAsteriscSegment(j, numspaces, numasterisc))
                std::cout << "*";
            else
                std::cout << " ";
        }
        if (numspaces == 0){
            pastmiddle = true;
        }
        if (!pastmiddle){
            numspaces -= 2;
            numasterisc += 2;
        }else{
            numspaces += 2;
            numasterisc -= 2;
        }
        std::cout << std::endl;
    }
    return 0;
}