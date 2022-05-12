#pragma once
#include "AB.h"
#include "NodoB.h"
#include <iostream>
#include <fstream>


template<class Key>
class ABB : public AB<Key> {
    public:
        bool insertar (const Key& k);
        bool buscar (const Key& k);
        void insertarEquilRama(const Key& k, NodoB<Key> *nodo);
        bool busqueda (const Key& k, NodoB<Key> *nodo);
        bool eliminar (Key& k);
        bool eliminacion (NodoB<Key> *nodo, Key& k);
        void sustituir (NodoB<Key> *eliminado, NodoB<Key> *sustituto);
};

template<class Key>
bool ABB<Key>::eliminar (Key& k) {
    if (AB<Key>::getRaiz() == NULL){
        return false;
    } 
    eliminacion(AB<Key>::getRaiz(), k);
}


template<class Key>
bool ABB<Key>::eliminacion (NodoB<Key> *nodo, Key& k) {
    if (nodo == NULL){
        return false;
    } 

    if (k < nodo->getClave()) {
        eliminacion(nodo->getNodoIzq(), k);
    } else if (k > nodo->getDato()) {
        eliminacion(nodo->getNodoDer(), k);
    } else { // k == nodo->getDato()
        NodoB<Key> *Eliminado = nodo;
        if (nodo->getNodoDer() == NULL) {
            nodo = nodo->getNodoIzq();
        } else if (nodo->getNodoIzq() == NULL) {
            nodo = nodo->getNodoDer();
        } else {
            sustituir(Eliminado, nodo->getNodoIzq());
        }
        delete (Eliminado);
    }
}

template<class Key>
void ABB<Key>::sustituir (NodoB<Key> *eliminado, NodoB<Key> *sustituto) {

    if (sustituto->getNodoDer() != NULL) {
        sustituir(eliminado, sustituto->getNodoDer());
    } else {
        eliminado->setDato(sustituto->getDato()); 
        eliminado = sustituto;
        sustituto = sustituto->getNodoIzq();

    }

}


template<class Key>
bool ABB<Key>::insertar (const Key& k) {
    if (buscar(k)) {
        return false;
    }
    if (AB<Key>::getRaiz() == NULL) {
        AB<Key>::setRaiz3(k);
    } else {
        insertarEquilRama(k, AB<Key>::getRaiz());
    }
    return true; 
}

template<class Key>
void ABB<Key>::insertarEquilRama(const Key& k, NodoB<Key> *nodo) {
    //int tam_izq = AB<Key>::Tamano(nodo->getNodoIzq());
    //int tam_der = AB<Key>::Tamano(nodo->getNodoDer());

    if (nodo == NULL) {
        nodo = new NodoB<Key> (k);
    } else if (k < nodo->getDato()) {
        insertarEquilRama(k, nodo->getNodoIzq());
    } else {
        insertarEquilRama(k, nodo->getNodoDer());
    }



    
    /*if (tam_izq <= tam_der) {
        if (nodo->getNodoIzq() != NULL) {
            insertarEquilRama(k, nodo->getNodoIzq());
        } else {
            nodo->setNodoIz(k);
        }
    } else {
        if (nodo->getNodoDer() != NULL){
            insertarEquilRama(k, nodo->getNodoDer());
        } else {            
            nodo->setNodoDe(k);
        }
    }*/
}

template<class Key>
bool ABB<Key>::buscar (const Key& k) {
    return busqueda(k, AB<Key>::getRaiz());
}

template<class Key>
bool ABB<Key>::busqueda (const Key& k, NodoB<Key> *nodo) {

    if (nodo == NULL) {
        return false;
    }
    if (k == nodo->getDato()) {
        return true;
    } 
    if (k > nodo->getDato()) {
        return busqueda(k, nodo->getNodoIzq());
    }
    return busqueda(k, nodo->getNodoDer());


    /*if (k == nodo->getDato()) {
        return true;
    } else {
        if (busqueda(k, nodo->getNodoIzq())){
            return true;
        } else {
            return busqueda(k, nodo->getNodoDer());
        }
    }
    return false;*/
}



