#include <iostream>
#include <map>
#include <string>
#include <set>

#include <Translator.h>
#include <Word.h>

using namespace std;


Translator::Translator(){

    multimap <string, string> dictionary;

    this->dictionary = dictionary;

}


Translator::Translator(const multimap <string, string> &dictionary){

    this->dictionary = dictionary;

}


Translator Translator::reverse(const Translator &direct){

    multimap <string, string>::iterator it;
    multimap <string, string> dict = direct.dictionary;
    string origin, trans;
    pair <string, string> curr_entry;

    multimap <string, string> reverse_trans;

    for(it = dict.begin(); it != dict.end(); ++it){

        origin = it->first;
        trans = it->second;

        curr_entry = pair <string, string> (trans, origin);

        reverse_trans.insert(curr_entry);

    }

    return Translator(reverse_trans);

};


Translator Translator::compose(const Translator &first, const Translator &second){

    multimap <string, string> fst_dict = first.dictionary, snd_dict = second.dictionary;
    multimap <string, string>::iterator fst_it = fst_dict.begin(),
        fst_end = fst_dict.end(), snd_it;
    pair <multimap <string, string>::iterator, multimap<string, string>::iterator> key_range;
    string origin, mid, trans;
    pair <string, string> curr_entry;

    multimap <string, string> compose_trans;

    for(; fst_it != fst_end; ++fst_it){

        origin = fst_it->first;
        mid = fst_it->second;
        curr_entry = pair <string, string> (origin, "");

        key_range = snd_dict.equal_range(mid);

        for(snd_it = key_range.first; snd_it != key_range.second; ++snd_it){

            curr_entry.second = snd_it->second;

            compose_trans.insert(curr_entry);

        }

    }

    return Translator(compose_trans);

}


void Translator::addEntry(const Word &word){

    string origin = word.getOrigin();
    pair <string, string> curr_entry(origin, "");
    Word::iterator it = word.begin(), end = word.end();

    for(; it != end; ++it){

        curr_entry.second = *it;

        this->dictionary.insert(curr_entry);

    }

}


set <string> Translator::translate(string word) const {

    multimap <string, string>::const_iterator start = this->dictionary.lower_bound(word),
        end = this->dictionary.upper_bound(word), it;

    set <string> translations;

    for(it = start; it != end; ++it){

        translations.insert(it->second);

    }

    return translations;

}


istream& operator>>(istream &is, Translator &translator){

    string entry;

    while(getline(is, entry)){

        Word new_word = Translator::buildWord(entry);

        translator.addEntry(new_word);

    }

    return is;

}


ostream& operator<<(ostream &os, const Translator &translator){

    const multimap <string, string> &dict = translator.dictionary;

    multimap <string, string>::const_iterator it = dict.begin(), curr_stop, end = dict.end();

    pair <string, string> curr_entry;

    while(it != end){

        string key = (*it).first;
        curr_stop = dict.upper_bound(key);

        cout << key << ";";

        for(; it != curr_stop; ++it){

            cout << (*it).second << ";";

        }

        cout << endl;

    }

    return os;

}


Word Translator::buildWord(string entry){

    string origin, trans;
    set <string> translations;

    string sep = ";";

    int last_sep = entry.find(sep), length = entry.length(), prev_sep;

    origin = entry.substr(0, last_sep);

    do {

        prev_sep = last_sep;
        last_sep = entry.find(sep, last_sep + 1);
        trans = entry.substr(prev_sep + 1, last_sep - prev_sep - 1);

        translations.insert(trans);


    } while(last_sep < length - 1);

    Word word(origin, translations);

    return word;

}