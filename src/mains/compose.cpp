#include <fstream>

#include <Translator.h>
#include <Word.h>

using namespace std;


int main(int argc, char* argv[]){
    
    ifstream fst_input(argv[1]), snd_input(argv[2]);
    ofstream output(argv[3]);

    Translator fst, snd, composition;

    fst_input >> fst;
    snd_input >> snd;

    composition = Translator::compose(fst, snd);

    output << composition;

}