// TODO: Default constructor (string origin) + addTranslation
// TODO: begin, end -> Word.cpp

/**
  * @file Word.h
  * @brief Archivo header para el TDA Word
  */

#ifndef WORD_H
#define WORD_H

#include <vector>
#include <string>
#include <set>

using namespace std;


/**
  * @brief TDA Word
  * Una instancia del TDA Word es un objeto que representa una palabra en un
  * idioma origen y sus posibles traducciones en un idioma destino.
  */

class Word {

    private:

        /**
          *
          * @section faConjunto Función de abstracción
          * Un objeto de la clase Word representa una palabra en un idioma
          * origen y sus posibles traducciones en un idioma destino
          * rep.origin -> rep.translations
          *
          */

        string origin;
        set <string> translations;

    public:

        /**
          *
          * @brief Clases para iterar sobre las traducciones de la palabra
          *
          */

        class iterator {

            private:

                set <string>::iterator it;

            public:

                iterator& operator++(){
                    ++(this->it);

                    return *this;
                }

                iterator operator++(int){
                    
                    iterator tmp = *this;

                    ++(this->it);

                    return tmp;
                }

                iterator& operator--(){
                    --(this->it);

                    return *this;
                }

                iterator operator--(int){
                    
                    iterator tmp = *this;

                    --(this->it);

                    return tmp;
                }

                const string& operator*() const {
                    return *(this->it);
                }

                bool operator==(const iterator &it) const {

                    return this->it == it.it;

                }

                bool operator!=(const iterator &it) const {

                    return this->it != it.it;

                }

                friend class Word;

        };

        class const_iterator {

            private:

                set <string>::const_iterator it;

            public:

                const_iterator(const iterator &it){

                    this->it = it.it;

                }

                const const_iterator& operator++(){
                    ++(this->it);

                    return *this;
                }

                const_iterator operator++(int){
                    
                    const_iterator tmp = *this;

                    ++(this->it);

                    return tmp;
                }

                const const_iterator& operator--(){
                    --(this->it);

                    return *this;
                }

                const_iterator operator--(int){
                    
                    const_iterator tmp = *this;

                    --(this->it);

                    return tmp;
                }

                const string& operator*() const {
                    return *(this->it);
                }

                bool operator==(const iterator &it) const {

                    return this->it == it.it;

                }

                bool operator!=(const iterator &it) const {

                    return this->it != it.it;

                }

                friend class Word;

        };

        /**
          *
          * @brief Constructor vacío de la clase
          * @return Instancia vacía de la clase
          * 
          */

        Word();

        /**
          *
          * @brief Constructor de la clase
          * @param origin palabra en el idioma origen
          * @param translations vector de strings con las traducciones
          * @return La palabra en el idioma origen asociada a sus traducciones
          * 
          */

        Word(string origin, set <string> translations);

        /**
          *
          * @brief Getter de origin
          * @return La palabra en el idioma origen
          *
          */

        string getOrigin() const ;

        /**
          *
          * @brief Getter de translations
          * @return Las traducciones en el idioma destino
          *
          */

        set <string> getTranslations() const;

        /**
          *
          * @brief Devuelve un iterador no constante
          *         a la primera traducción de la palabra
          *
          */

        iterator begin() const {

            iterator it;

            it.it = this->translations.begin();

            return it;

        }

        /**
          *
          * @brief Devuelve un iterador no constante
          *         a la última traducción de la palabra
          *
          */

        iterator end() const {

            iterator it;

            it.it = this->translations.end();

            return it;

        }

        /**
          *
          * @brief Sobrecarga del operador <= (orden lexicográfico)
          * @param word instancia de la clase a comparar con this
          * @return  Devuelve true si este objeto es menor o igual que word
          *             (lex) y false en caso contrario
          *
          */

        bool operator<=(const Word &word) const;
        bool operator<(const Word &word) const;
        bool operator>=(const Word &word) const;
        bool operator>(const Word &word) const;

};

#endif