#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->index = 0;
    this->start=1;
    this->pace=2;
}
//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
void BagIterator::first() {
	this->index = 0;
}

//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
void BagIterator::next() {
	if(this->index < this->bag.nrElemsPositions)
	  this->index+=1;
    else
        throw exception();
}

//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
bool BagIterator::valid() const {
    if(this->index < this->bag.nrElemsPositions)
        return true;
	return false;
}


//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
TElem BagIterator::getCurrent() const
{
    if(valid()){
        return this->bag.liste[this->bag.positions[this->index]];
    }
	else{
        throw exception();
    }
}
//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
void BagIterator::first_ra() {
    this->index=this->start;
}

//best case: θ(1) worst case:θ(1) average case:θ(1) allgemeine Komplexitat:θ(1)
void BagIterator::next_ra() {
    if(this->index + this->pace < bag.nrElemsPositions && this->index +this->pace > this->start)
        this->index+=this->pace;

}
