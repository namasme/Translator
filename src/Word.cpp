#include <string>
#include <set>

#include <Word.h>


Word::Word(){

    set <string> trans;

    this->origin = "";
    this->translations = trans; 

}


Word::Word(string origin, set <string> translations){

    this->origin = origin;

    this->translations = translations;

}


string Word::getOrigin() const {

    return this->origin;

}


set <string> Word::getTranslations() const {

    return this->translations;

}


bool Word::operator<(const Word &other) const {

    return this->origin < other.origin;

}


bool Word::operator<=(const Word &other) const {

    return not (other < *this);

}


bool Word::operator>(const Word &other) const {

    return other < *this;

}


bool Word::operator>=(const Word &other) const {

    return not (*this < other);

}