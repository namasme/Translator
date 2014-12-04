#include <iostream>

#include <Translator.h>
#include <Word.h>

using namespace std;


int main(){
    
    Translator direct;

    cin >> direct;

    Translator reverse = Translator::reverse(direct);

    cout << reverse;

}