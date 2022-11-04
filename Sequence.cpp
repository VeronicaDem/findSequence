#include "Sequence.h"
bool Sequence::existElemInPos(int elem) {
	if (this->offset == -1) this->offset = 0;
	if (this->elemsInSeq[this->offset] == elem) {
		this->offset++;
		return true;
	}
	this->offset = 0;
	if (this->elemsInSeq[0] == elem) {
		this->offset++;
		return true;
	}
	return false;
}
Sequence::Sequence() {

};
void Sequence::addElem(int elem) {
	int* elemsInSeq = new int[this->length + 1];
	if (!this->isEmpty()) {
		for (int i = 0; i < this->length; i++) {
			elemsInSeq[i] = this->elemsInSeq[i];
		}
	}
	this->length++;
	elemsInSeq[this->length - 1] = elem;
	this->elemsInSeq = elemsInSeq;
};
bool Sequence::isBound() {
	return this->offset == this->length;
}
bool Sequence::isEmpty() {
	return this->length == 0;
}
int Sequence::size() {
	return this->length;
}
