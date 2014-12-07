#include <iostream>
#include <fstream>

#include <Translator.h>
#include <Word.h>

using namespace std;


int main(int argc, char* argv[]){
    
    ifstream input(argv[1]);

    Translator direct, reverse;

    input >> direct;

    reverse = Translator::reverse(direct);

    if(argc == 3){

        ofstream output(argv[2]);

        output << reverse;
        
    } else {

        cout << reverse;

    }

}