#include "field.h"

Saper::Field::Field()
{

}
void Saper::Field::show()
{
    _isVisible = true;
}

bool Saper::Field::isVisible()
{
    return _isVisible;
}

void Saper::Field::setMine()
{
    _isMine = true;
}

bool Saper::Field::isMine()
{
    return _isMine;
}
void Saper::Field::setValue(Saper::CountMine val)
{
    _val = val;
}

Saper::CountMine Saper::Field::getValue()
{
    return _val;
}
