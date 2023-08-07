#include "Marsh.h"

istream& operator>>(istream& in, Toy& ob)
{
	in >> ob.cost >> ob.name >> ob.category >> ob.limitation;
	return in;
}
ostream& operator<<(ostream& out, const Toy& ob)
{
	out << ob.cost << " " << ob.name << " " << ob.category << " " << ob.limitation;
	return out;
}
// ср имена, потом сортировка
bool Toy::CompareToyname(Toy Toy) {
	if (lexicographical_compare(name.begin(), name.end(), Toy.name.begin(), Toy.name.end()))
		return false;
	// правду если наоборот
	else
		return true;
};
bool Toy::CompareToycost(Toy Toy) {
	if (cost <= Toy.cost) // cost > Toy.cost
		return false;
	// правду если наоборот
	else
		return true;
};
bool Toy::CompareToycategory(Toy Toy) {
	if (lexicographical_compare(category.begin(), category.end(),Toy.category.begin(), Toy.category.end()))
		return false;
	// правду если наоборот
	else
		return true;
};
bool Toy::CompareToylimitation(Toy Toy) {
	if (limitation > Toy.limitation)
		return false;
	// правду если наоборот
	else
		return true;
};