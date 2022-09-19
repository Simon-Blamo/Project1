/*Name: Simon Blamo
*Date: September 20, 2022
*File: Project1.cpp
*Description: Project1 is where I 
*             
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int nrows;
int ncols;
char* input;
char* output;

bool initGame(string filename){
    
    ifstream ifile;
    ifile.open(filename); 

    if (!ifile.is_open()) {
        cout << filename << " was not found" << endl;
       return 1;
    }

    ifile >> nrows;
    ifile >> ncols;

    input = new char[nrows*ncols];
    output = new char[nrows*ncols];

    for(int i = 0; i < nrows * ncols; i++){
        ifile >> input[i] ;
        output[i] = '-';
    }


    ifile.close();

    return "";
}

void printGrid(char grid[]){
    int c = 0;
    for(int i = 0; i < nrows*ncols; i++){
        cout << grid[i] << " ";
        c++;
        if(c == ncols){
            cout << endl;
            c = 0;
       }
    }
}

bool checkN(int i, string word){
    int m = 0;
    for(int x = 1; x < word.length(); x++){
        if(input[i-(x*ncols)]=='\0'){
            return false; 
        }

        if(input[i-(x*ncols)]!=word.at(x)){
            m++;
        }
    }
    if(m != 0){
        return false;
    }
    return true;
}

bool checkNE(int i, string word){
    int m = 0;
    int y = 1;
    for(int x = 1; x < word.length(); x++){
        if(input[i-((x*ncols)+y)] == '\0'){
            return false; 
        }

        if(input[i-((x*ncols)+y)]!=word.at(x)){
            m++;
        }
        y++;
    }

    if(m > 0){
        return false;
    }
    return true;
}
bool checkE(int i, string word){
    int m = 0;
    int y = 0;
    int yy = 0;
    int z = 0;
    for(int r = 1; r < nrows+1; r++){
        if(r*ncols > i){
            yy=r-1;
        }
    }
    z -= yy*ncols;
    
    for(int x = 1; x < word.length(); x++){
        if(input[i+(x)]=='\0' || (z + y) > ncols){
            return false; 
        }

        if(input[i+(x)]!=word.at(x)){
            m++;
        }
        y++;
    }

    if(m != 0){
        return false;
    }
    return true;
}

bool checkSE(int i, string word){
    //Done, But Skeptical.
    int m = 0;
    int y = 1;
    for(int x = 1; x < word.length(); x++){
        if(input[i+((x*ncols)+y)]=='\0'){
            return false; 
        }

        if(input[i+((x*ncols)+y)]!=word.at(x)){
            m++;
        }
        y++;
    }

    if(m != 0){
        return false;
    }
    return true;
}

bool checkS(int i, string word){
    int m = 0;
    for(int x = 1; x < word.length(); x++){
        if(input[i+(x*ncols)]=='\0'){
            return false; 
        }

        if(input[i+(x*ncols)]!=word.at(x)){
            m++;
        }
    }

    if(m != 0){
        return false;
    }
    return true;
}

bool checkSW(int i, string word){
    //Done, But Skeptical.
    int m = 0;
    int y = 1;
    for(int x = 1; x < word.length(); x++){
        if(input[i+((x*ncols)-y)] == '\0'){
            return false; 
        }

        if(input[i+((x*ncols)-y)] != word.at(x)){
            m++;
        }
        y++;
    }

    if(m != 0){
        return false;
    }
    return true;
}

bool checkW(int i, string word){
 int m = 0;
    int y = 0;
    int yy = 0;
    int z = 0;
    for(int r = 1; r < nrows+1; r++){
        if(r*ncols > i){
            yy=r-1;
        }
    }
    z -= yy*ncols;
    
    for(int x = 0; x <word.length(); x++){
        if(input[i+(x)]== '\0' || (z - y) < 0){
            return false; 
        }

        if(input[i-(x)]!=word.at(x)){
            m++;
        }
        y++;
    }

    if(m != 0){
        return false;
    }
    return true;
}

bool checkNW(int i, string word){
    //Done, But Skeptical.
    int m = 0;
    int y = 1;
    for(int x = 1; x <= word.length(); x++){
        if(input[i-((x*ncols)-y)]=='\0'){
            return false; 
        }

        if(input[i-((x*ncols)-y)]!=word.at(x-1)){
            m++;
        }
        y++;
    }

    if(m != 0){
        return false;
    }
    return true;
}

int check(int i, string word){
    int fail = 0;
 
    if(checkN(i, word) == true){return 1;}
    if(checkNE(i, word) == true){return 2;}
    if(checkE(i, word) == true){return 3;}
    if(checkSE(i, word) == true){return 4;}
    if(checkS(i, word) == true){return 5;}
    if(checkSW(i, word) == true){return 6;}
    if(checkW(i, word) == true){return 7;}
    if(checkNW(i, word) == true){return 8;}

    return fail;
}

bool isWordAtInput(string word){
    for(int i = 0; i < nrows * ncols; i++){
        if(input[i] == word.at(0)){
            if(check(i, word) != 0){
                return true;
            }
        }
    }
    return false;
 } 

void setWordAtOutput(string word){
    int y = 0;
    for(int i = 0; i < nrows*ncols; i++){
        if(input[i]==word.at(0)){
            if(check(i, word) == 1){
                for(int x = 0; x < word.length(); x++){
                    output[i-(x*ncols)]=word.at(x);
                }
            } else if (check(i, word) == 2){
                for(int x = 0; x < word.length(); x++){
                    output[i-((x*ncols)+y)]=word.at(x);
                    y++;
                }
            } else if (check(i, word) == 3){
                for(int x = 0; x < word.length(); x++){
                    output[i+(x)]=word.at(x);
                }
            } else if (check(i, word) == 4){
                for(int x = 0; x < word.length(); x++){
                    output[i+((x*ncols)+y)]=word.at(x);
                    y++;
                }
            } else if (check(i, word) == 5){
                for(int x = 0; x < word.length(); x++){
                    output[i+(x*ncols)]=word.at(x);
                }
            } else if (check(i, word) == 6){
                for(int x = 0; x < word.length(); x++){
                    output[i+((x*ncols)-y)]=word.at(x);
                    y++;
                }
            } else if (check(i, word) == 7){
                for(int x = 0; x < word.length(); x++){
                    output[i-(x)]=word.at(x);
                }
            } else {
                for(int x = 0; x < word.length(); x++){
                    output[i-((x*ncols)-y)]=word.at(x);
                    y++;
                }
            }
        }
    }
}

void findWord(string word){
    if(isWordAtInput(word) == true){
        setWordAtOutput(word);
    }
}


int main(int argc, char* argv[]) { 
    string filename(argv[1]); 
 
    if (!initGame(filename)) { return -1; } 
    printGrid(input); 
 
    for (int i=2; i<argc; ++i) { 
        string word(argv[i]); 
        cout << "Searching for " << word << endl; 
        findWord(word);
    } 
 
    printGrid(output); 
    delete[] input; 
    delete[] output;

    return 0; 
}