#include "field.h"
#include "gtest/gtest.h"

TEST(fieldShould, whenFieldIsMarkdIsVisibleShouldReturnTrue)
{
    Saper::Field f;
    EXPECT_FALSE(f.isVisible());

    f.show();

    EXPECT_TRUE(f.isVisible());
}

TEST(fieldShould, whenFieldIsSetAsMineShouldReturnTrue)
{
    Saper::Field f;
    EXPECT_FALSE(f.isMine());

    f.setMine();

    EXPECT_TRUE(f.isMine());
}
TEST(fieldShould, )
{
    Saper::Field f;

    f.setValue(Saper::CountMine::FIVE);

    EXPECT_EQ(f.getValue(), Saper::CountMine::FIVE);
}
