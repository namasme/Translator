#include <iostream>
#include <fstream>

#include <Translator.h>
#include <Word.h>

using namespace std;


int main(int argc, char* argv[]){
    
    ifstream first_input(argv[1]), second_input(argv[2]);

    Translator fst, snd;

    first_input >> fst;
    second_input >> snd;

    Translator compose = Translator::compose(fst, snd);

    cout << compose;

}