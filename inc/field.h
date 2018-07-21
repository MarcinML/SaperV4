#ifndef FIELD_H
#define FIELD_H

namespace Saper{

enum CountMine {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT
};



class Field
{
public:
    Field();
    CountMine getValue();
    void setValue(CountMine);
    void setMine();

    bool isMine();
    bool isVisible();

    void show();



private:
    CountMine _val = ZERO;
    bool _isMine = false;
    bool _isVisible = false;

    };

}
#endif // FIELD_H
