#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


//6.ADT Bag  reprsentiert als ein dynamisches Array von eindeutigen Elementen (E) und ein
//dynamisches Array von Positionen (P) in E der Elemente des Bags. Zum Beispiel, das Bag [5, 10, -1, 2, 3, 10, 5, 5, -5] wird
//folgendermaen reprsentiert:U = [5, 10, -1, 2, 3, -5]P = [0, 1, 2, 3, 4, 1, 0, 0, 5]


//best case: θ(1) worst case:θ(1) average case:θ(1)
Bag::Bag() {
    this->cap_list = 10;
    this->cap_pos= 10;
	this-> nrElemsListe = 0;
	this-> liste = new TElem [cap_list];
    this-> nrElemsPositions=0;
    this-> positions= new int [cap_pos];

}

//best case:θ(1)  worst case:θ(n) average case: allgemeine Komplexitat:O(n)
void Bag::add(TElem elem) {

    int already_added=0;
	for(int index=0;index<this->nrElemsListe;index+=1)
        if(this->liste[index]==elem) {

            //make space positions
            if(this->nrElemsPositions == this->cap_pos){
                this->cap_pos = this->cap_pos * 2;
                int* new_array = new int[this->cap_pos];
                for(int index_pos=0;index_pos<this->nrElemsPositions;index_pos+=1){
                    new_array[index_pos] = this->positions[index_pos];
                }
                delete[] this->positions;
                this->positions = new_array;
            }
            this->positions[nrElemsPositions] = index;
            nrElemsPositions+=1;
            already_added = 1;
            break;
        }
    if(already_added == 0) {
        //make space elements
        if (this->nrElemsListe == this->cap_list) {
            this->cap_list = this->cap_list * 2;
            int *new_array = new int[this->cap_list];
            for (int index_list = 0; index_list < this->nrElemsListe; index_list += 1) {
                new_array[index_list] = this->liste[index_list];
            }
            delete[] this->liste;
            this->liste = new_array;
        }
        this->liste[nrElemsListe] = elem;
        nrElemsListe += 1;

        //make space positions
        if (this->nrElemsPositions == this->cap_pos) {
            this->cap_pos = this->cap_pos * 2;
            int *new_array = new int[this->cap_pos];
            for (int index_pos = 0; index_pos < this->nrElemsPositions; index_pos += 1) {
                new_array[index_pos] = this->positions[index_pos];
            }
            delete[] this->positions;
            this->positions = new_array;
        }

        this->positions[nrElemsPositions] = nrElemsListe - 1;
        nrElemsPositions += 1;
    }

}
//best case:θ(n)  worst case:θ(n) average case: allgemeine Komplexitat:θ(n)
bool Bag::remove(TElem elem) {
    int counter=0;
    int pos_elem=INT_MIN;
    int last_pos=INT_MIN;
    for(int index=0;index<nrElemsListe;index+=1)
        if(this->liste[index] == elem) {
            pos_elem = index;
            break;
        }
    for(int index=0;index<nrElemsPositions;index+=1)
        if(this->positions[index] == pos_elem) {
            counter += 1;
            last_pos = index;
        }
    if(counter>1){
        for(int index=last_pos;index<nrElemsPositions;index++){
            this->positions[index] = this->positions[index+1];
        }
        nrElemsPositions--;

        //make less space positions
        if (this->nrElemsPositions < this->cap_pos / 4) {
            this->cap_pos = this->cap_pos / 2;
            int *new_array = new int[this->cap_pos];
            for (int index_pos = 0; index_pos < this->nrElemsPositions; index_pos += 1) {
                new_array[index_pos] = this->positions[index_pos];
            }
            delete[] this->positions;
            this->positions = new_array;
        }
        return true;
    }
    else {
        if (counter == 1) {
            for (int index = last_pos; index < nrElemsPositions; index++) {
                this->positions[index] = this->positions[index + 1];
            }
            nrElemsPositions--;

            //make less space positions
            if (this->nrElemsPositions < this->cap_pos / 4) {
                this->cap_pos = this->cap_pos / 2;
                int *new_array = new int[this->cap_pos];
                for (int index_pos = 0; index_pos < this->nrElemsPositions; index_pos += 1) {
                    new_array[index_pos] = this->positions[index_pos];
                }
                delete[] this->positions;
                this->positions = new_array;
            }

            for (int index = pos_elem; index < nrElemsListe; index++) {
                this->liste[index] = this->liste[index + 1];
            }
            nrElemsListe--;

            //make less space elements
            if (this->nrElemsListe < this->cap_list / 4) {
                this->cap_list = this->cap_list / 2;
                int *new_array = new int[this->cap_list];
                for (int index_list = 0; index_list < this->nrElemsListe; index_list += 1) {
                    new_array[index_list] = this->liste[index_list];
                }
                delete[] this->liste;
                this->liste = new_array;
            }

            return true;

        } else {
            return false;
        }
    }
}

//best case:θ(1)  worst case:θ(n) average case:θ(n) allgemeine Komplexitat:O(n)
bool Bag::search(TElem elem) const {
	for(int index=0;index<this->nrElemsListe;index+=1)
        if(this->liste[index] == elem)
            return true;
	return false;
}
//best case:θ(1)  worst case:θ(n) average case:θ(n) allgemeine Komplexitat:O(n)
int Bag::nrOccurrences(TElem elem) const {
	int counter=0;
    int pos_elem = INT_MIN;
    for(int index=0;index<nrElemsListe;index+=1)
        if(this->liste[index] == elem)
            pos_elem = index;
	for(int index=0;index<nrElemsPositions;index+=1)
        if(this->positions[index] == pos_elem)
            counter+=1;

	return counter;
}

//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
int Bag::size() const {

	return this->nrElemsPositions;
}

//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
bool Bag::isEmpty() const {
	if (nrElemsListe == 0)
        return true;
	return false;
}


BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
Bag::~Bag() {
	delete[] liste;
    delete[] positions;
}

