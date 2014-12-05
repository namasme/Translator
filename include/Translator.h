/**
  * @file Translator.h
  * @brief Archivo header para el TDA Translator
  */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include <set>
#include <map>

#include <Word.h>

using namespace std;


/**
  * @brief TDA Translator
  * Una instancia del TDA Translator es un objeto que recibe palabras en un
  * idioma origen y las traduce a un idioma destino.
  */

class Translator {

    private:

        /**
          *
          * @section faConjunto Función de abstracción
          * Un objeto de la clase Translator es un objeto que recibe palabras
          * en un idioma origen y las traduce a un idioma destino.
          *
          */

        multimap <string, string> dictionary;

        /**
          *
          * @brief Comprueba si el traductor está vacío
          * @return true si está vacío, falso si no
          *
          */

        bool empty();

    public:

      /**
          *
          * @brief Clases para iterar sobre las traducciones de la palabra
          *
          */

        class iterator {

            private:

                multimap <string, string>::iterator it;

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

                const pair <string, string> operator*() const {
                    return *(this->it);
                }

                bool operator==(const iterator &it) const {

                    return this->it == it.it;

                }

                bool operator!=(const iterator &it) const {

                    return this->it != it.it;

                }

                friend class Translator;
                friend class const_iterator;

        };

        class const_iterator {

            private:

                multimap <string, string>::const_iterator it;

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

                const pair <string, string> operator*() const {
                    return *(this->it);
                }

                bool operator==(const iterator &it) const {

                    return this->it == it.it;

                }

                bool operator!=(const iterator &it) const {

                    return this->it != it.it;

                }

                friend class Translator;

        };

        /**
          *
          * @brief Constructor por defecto de la clase
          *
          */

        Translator();

        /**
          *
          * @brief Constructor de la clase
          * @param dictionary instancia de una lista ordenada que contiene 
                            el diccionario
          * @return Un traductor del idioma origen al idioma destino
          * 
          */

        Translator(const multimap <string, string> &dictionary);

        /**
          *
          * @brief Construye, dado un traductor A -> B, el traductor inverso B -> A
          * @param direct instacia de Translator que representa al traductor A -> B
          * @return Un traductor inverso B -> A
          *
          */

        static Translator reverse(const Translator &direct);

        /**
          *
          * @brief Construye, dado un traductor A -> B y otro B -> C, la 
          *         composición de ambos, i.e., un traductor A -> C.
          * @param first instacia de Translator que representa al traductor A -> B
          * @param second instacia de Translator que representa al traductor B -> C
          * @return Un traductor A -> C
          *
          */

        static Translator compose(const Translator &first, const Translator &second);

        /**
          *
          * @brief Añade una palabra al traductor
          * @param word instancia de la clase Word a añadir
          *
          */

        void addEntry(const Word &word);

        /**
          *
          * @brief Traduce una palabra o lanza una excepción si la palabra
          *         no se encontró
          * @param word string que representa a la palabra en el idioma origen
          * @return Un vector de strings con las posibles traducciones si se 
          *          encontró word en el diccionario
          * 
          */

        set <string> translate(string word) const;

        /**
          *
          * @brief Sobrecarga del operador de entrada
          * @param is stream de entrada
          * @param translator instancia de la clase a rellenar
          * @return El mismo stream de entrada, leídos ya los datos
          *
          */

        friend istream& operator>>(istream &is, Translator &translator);

        /**
          *
          * @brief Sobrecarga del operador de salida
          * @param os stream de salida
          * @param translator instancia de la clase a imprimir
          * @return El mismo stream de salida, imprimidos ya los datos
          *
          */

        friend ostream& operator<<(ostream &os, const Translator &translator);

        /**
          *
          * @brief Crea una palabra a partir de un string de la forma
          *         origin;trans1;trans2;...;transN;
          * @param entry el string que codifica la palabra
          * @return Una instancia de la clase Word con esa información
          *
          */

        static Word buildWord(string entry);

};

#endif