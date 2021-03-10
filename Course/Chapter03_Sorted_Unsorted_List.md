ADTs Unsorted List and Sorted List
=====================================
> **ADT Unsorted List operations**
  1) Transformers: MakeEmpty(), InsertItem(), DeleteItem()
  2) Observers: IsFull(), LengthIs, RetrieveItem()
  3) Iterators: ResetList, GetNextItem()

### Generic Data Type
* operations are defined but types of the items being manipulated are not defined!
> **class ItemType**
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

