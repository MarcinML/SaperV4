#include "sapermap.h"
#include "gtest/gtest.h"

class UT_BoardTest :
    public ::testing::TestWithParam<std::pair<unsigned int, unsigned int> > {

};


std::vector<std::pair<unsigned int, unsigned int> > inputs { {5,5}, {3,8}, {8,3} };


TEST_P(UT_BoardTest, testindDifferentSizesOfMaps)
{


    Saper::Map m ( GetParam().first, GetParam().second );

    EXPECT_EQ(m.map.size(), GetParam().first);
    for(unsigned i =0; i<GetParam().first; i++)
    {
        EXPECT_EQ(m.map[i].size(), GetParam().second );
    }
}

TEST(mapShould, takesNumberOfBombsAndSetThemOnMapInProperWay)
{
    Saper::Map m(10,10);
    m.setBombsOnMap(5);
    int bombs=0;

    for(unsigned j=0; j < 10; j++)
    {
        for(unsigned k = 0; k < 10; k++)
        {
            if (m.map[k][j].isMine())
            {
                bombs++;
            }
        }
    }
    EXPECT_EQ(bombs, 5);
}

TEST(mapShould, takesNumbefrOfBombsAndSetThemOnMapInProperWay)
{
    Saper::Map m(10,10);


    EXPECT_ANY_THROW(m.setBombsOnMap(1000));
}

TEST(mapShould, countHowManyMinesNeighborsHasEveryField)
{
    Saper::Map m(2,2);
    m.map[1][1].setMine();

    m.countMinesNeighbors();

    EXPECT_EQ(m.map[0][0].getValue(), Saper::CountMine::ONE);
    EXPECT_EQ(m.map[0][1].getValue(), Saper::CountMine::ONE);
    EXPECT_EQ(m.map[1][0].getValue(), Saper::CountMine::ONE);


}




INSTANTIATE_TEST_CASE_P(mapShould, UT_BoardTest,
                        ::testing::ValuesIn(inputs));
