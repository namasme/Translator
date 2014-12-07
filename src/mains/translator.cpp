#include <fstream>
#include <iostream>
#include <set>

#include <Translator.h>
#include <Word.h>

using namespace std;


int main(int argc, char *argv[]){

    if (argc != 2){

        cout << "Usage: ./translator /path/to/dictionary" << endl;
        return 0;

    }

    ifstream input_dict(argv[1]);

    if(not input_dict){

        cout << argv[1] << ": No such file" << endl;
        return 0;

    }

    Translator T;

    input_dict >> T;

    string origin;
    cout << "Type a word in the origin language: ";
    getline(cin, origin);

    set <string> translations = T.translate(origin);

    if(not translations.empty()){

        cout << origin << " -> ";

        set <string>::iterator it;

        for(it = translations.begin(); it != translations.end(); ++it){

            cout << *it << " ; ";

        }

        cout << endl;

    }

}