#include "Bag.h"

class BagIterator
{
	//DO NOT CHANGE THIS PART
	friend class Bag;

private:
	const Bag& bag;
	int index;
    int start;
    int pace;

	BagIterator(const Bag& c);
public:
	void first();
	void next();
    void first_ra();
    void next_ra();
	TElem getCurrent() const;
	bool valid() const;
};
