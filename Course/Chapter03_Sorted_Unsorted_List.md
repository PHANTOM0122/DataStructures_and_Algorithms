ADTs Unsorted List and Sorted List
=====================================
> **ADT Unsorted List operations**
  1) Transformers: MakeEmpty(), InsertItem(), DeleteItem()
  2) Observers: IsFull(), LengthIs, RetrieveItem()
  3) Iterators: ResetList, GetNextItem()

### Generic Data Type
* operations are defined but types of the items being manipulated are not defined!
#### class ItemType
<pre><code>
const int MAX_ITEMS = 5;
enum RealtionType{LESS, EQUAL. GREATER}

class ItemType{
public:
  ItemType();
  RelationType ComparedTo(ItemType other) const;
  void Print() const;
  void Initialize(int number);
private:
  int value; // could be any different type!
}

ItemType::ItemType()
{ 
  value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number) 
{
  value = number;
}

void ItemType::Print(std::ostream& out) const 
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << value;
}
</code></pre>

#### class UnsortedType
<pre><code>
class SortedType {
public:
	SortedType();
	bool IsFull();
	int LengthIs();
	void RetrieveItem(ItemType& target, bool& found);
	void InsertItem(const ItemType& item);
	void DeleteItem(const ItemType& target);
	void ResetItem();
	void GetNextItem(ItemType& result);
private:
	int length;
	ItemType info[MAX_ITEMS];
	int currentPos;
};

SortedType::SortedType()
{
	length = 0; currentPos = -1;
}

bool SortedType::IsFull()
{
	return (length == MAX_ITEMS);
}

int SortedType::LengthIs()
{
	return length;
}

void SortedType::RetrieveItem(ItemType& target, bool& found) // linear-search!
{
	bool moreToSearch;
	int location = 0;
	found = false;
	moreToSearch = (location < length); // linear-search!
	
	while (moreToSearch && !found) {
		switch (target.ComparedTo(info[location]))
		{
		case LESS:
		case GREATER:
			location++;
			moreToSearch = (location < length);
			break;
		case EQUAL:
			found = true;
			target = info[location];
			break;
		}
	}
}

void SortedType::InsertItem(const ItemType& item)
{	// if list is not Full!
	info[length] = item;
	length++;
}

void SortedType::DeleteItem(const ItemType& target) 
{
	int location = 0;
	// find location to delete!
	while (target.ComparedTo(info[location]) != EQUAL) {
		location++;
	}

	info[location] = info[length - 1];
	length--;
}

void SortedType::ResetItem()
{
	currentPos = -1;
}

void SortedType::GetNextItem(ItemType& result)
{
	currentPos++;
	result = info[currentPos];
}
</code></pre>

#### class mySortedType
<pre><code>
class mySortedType {
	mySortedType(int MAX);
	bool IsFull();
	int LengthIs();
	void RetrieveItem(const ItemType&, bool&);
	void InsertItem(const ItemType& item);
	void DeleteItem(const ItemType& target);
	void Reset();
	ItemType GetNextItem();
private:
	// int length;
	ItemType* info;
	int endCursor;
	int startCursor;
};

mySortedType::mySortedType(int MAX = 10)
{
	int length;
	cin >> length;

	info = new ItemType[MAX];
	startCursor = 0;
	endCursor = length-1;
}

bool mySortedType::IsFull() { // using without length!
	try {
		info[endCursor++];
		return false;
	}
	catch (out_of_range){
		return true;
	}
}

int mySortedType::LengthIs() {
	return endCursor;
}

void mySortedType::RetrieveItem(const ItemType& target, bool& found) {
	// Same as original!
}

void mySortedType::InsertItem(const ItemType& item) {
    if (endCursor >= MAX_ITEMS) { throw OutOfRange(); } // when list if full!
    else {
	   info[endCursor] = item;
	   endCursor++;
	}
}

void mySortedType::DeleteItem(const ItemType& target) {
	int location = 0;
	bool found = false;
	// check whether target is in the list
	RetrieveItem(target, found);

	if (!found) { cout << "Items are not in the list!" << endl; }
	else { // target is in the list!
		// find location to delete
		while (target.ComparedTo(info[location]) != EQUAL)
			location++;

		info[location] = info[endCursor];
		endCursor--;
	}
}

void mySortedType::Reset() {
	startCursor = 0;
}
ItemType mySortedType::GetNextItem() {
	return info[startCursor];
	startCursor++;
}</code></pre>
