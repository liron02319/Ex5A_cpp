#include "doctest.h"
#include <stdexcept>
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("Iterating empty container") {

        SUBCASE("iterating on empty container") {
            MagicalContainer container;
            MagicalContainer::AscendingIterator iterator(container);
            CHECK_EQ(iterator.begin() , iterator.end());

        }

      
    }

TEST_CASE("Check addElement, removeElement and size function"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(1);
    container.addElement(2);
    CHECK(container.size() == 2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 5);
    container.removeElement(5);
    CHECK(container.size() == 4);
    container.removeElement(5);
    CHECK(container.size() == 4);
    container.removeElement(4);
    CHECK(container.size() == 3);
     container.removeElement(3);
    CHECK(container.size() == 2);
     container.removeElement(2);
    CHECK(container.size() == 1);

}

TEST_CASE("Check the AscendingIterator"){
    MagicalContainer container;
    container.addElement(14);
    container.addElement(5);
    container.addElement(4);
    container.addElement(2);
    container.addElement(1);
    
    MagicalContainer ::AscendingIterator ascending(container);
    
    auto current = ascending.begin();
    CHECK(*current == 1);
    ++current;
    CHECK(*current == 2);
    ++current;
    CHECK(*current == 4);
    ++current;
    CHECK(*current == 5);
    ++current;
    CHECK(*current == 14);
    
}



TEST_CASE("Check the SideCrossIterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);
    
    MagicalContainer ::SideCrossIterator side(container);
    
    auto current = side.begin();
    CHECK(*current == 1);
    ++current;
    CHECK(*current == 14);
    ++current;
    CHECK(*current == 2);
    ++current;
    CHECK(*current == 5);
    ++current;
    CHECK(*current == 4);
    
}


TEST_CASE("Check the PrimeIterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);
    
    MagicalContainer ::PrimeIterator prime(container);
    
    auto current = prime.begin();
    CHECK(*current == 2);
    ++current;
    CHECK(*current == 5);
    
}

TEST_CASE("Check equal"){
    MagicalContainer container1;
    container1.addElement(1);
    container1.addElement(2);
    container1.addElement(4);
    container1.addElement(5);

    MagicalContainer container2;
    container2.addElement(1);
    container2.addElement(2);
    container2.addElement(4);
    container2.addElement(5);

    MagicalContainer ::AscendingIterator ascending1(container1);
    MagicalContainer ::AscendingIterator ascending2(container2);

    CHECK(ascending1 == ascending2);
    

}

TEST_CASE("Compare operaters AscendingIterator") {
        
        SUBCASE("pre-increment and operators") {
            MagicalContainer container;
            container.addElement(2);
            container.addElement(7);
            container.addElement(4);
            container.addElement(16);
            container.addElement(13);

            MagicalContainer::AscendingIterator iterator1(container);
            MagicalContainer::AscendingIterator iterator2(container);

            //{2.4.7.13.16} , iterator1=2, iterator2=2
            CHECK(iterator1 == iterator2); //2=2
            CHECK_FALSE(iterator1 != iterator2); 
            CHECK_FALSE(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator1; // iterator1=4, iterator2=2
            CHECK_FALSE(iterator1 == iterator2);
            CHECK_FALSE(iterator1 < iterator2);
            CHECK(iterator1 != iterator2);
            CHECK(iterator1 > iterator2);

            ++iterator2; // iterator1=4, iterator2=4
            CHECK(iterator1 == iterator2);
            CHECK_FALSE(iterator1 != iterator2);
            CHECK_FALSE(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator1; //iterator1=7, iterator2=4
            CHECK_FALSE(iterator1 == iterator2);
            CHECK(iterator1 > iterator2);
            CHECK(iterator1 != iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator2;  //iterator1=7, iterator2=7
            CHECK(iterator1 == iterator2);
            CHECK_FALSE(iterator1 != iterator2);
            CHECK_FALSE(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator1; //iterator1=13 iterator2=7
            CHECK_FALSE(iterator1 == iterator2);
            CHECK_FALSE(iterator1 < iterator2);
            CHECK(iterator1 != iterator2);
            CHECK(iterator1 > iterator2);

        }
    }


TEST_CASE("Compare operaters PrimeIterator") {

        SUBCASE("pre-increment and operators") {
            MagicalContainer container;
            container.addElement(1);
            container.addElement(2);
            container.addElement(4);
            container.addElement(5);
            container.addElement(14);

            MagicalContainer::PrimeIterator iterator1(container);
            MagicalContainer::PrimeIterator iterator2(container);

            //{2.5} , iterator1=2, iterator2=2
            CHECK(iterator1 == iterator2);
            CHECK_FALSE(iterator1 != iterator2);
            CHECK_FALSE(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator1;  //iterator1=5 iterator2=2
            CHECK_FALSE(iterator1 == iterator2);
            CHECK(iterator1 != iterator2);
            CHECK(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator2;  //iterator1=5 iterator2=5
            CHECK(iterator1 == iterator2);
            CHECK_FALSE(iterator1 != iterator2);
            CHECK_FALSE(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

          
        }
    }

TEST_CASE("Compare operaters SideCrossIterator ") {

        SUBCASE("pre-increment and operators") {
            MagicalContainer container;
            container.addElement(1);
            container.addElement(2);
            container.addElement(4);
            container.addElement(5);
            container.addElement(14);

            MagicalContainer::SideCrossIterator iterator1(container);
            MagicalContainer::SideCrossIterator iterator2(container);

            //{1.14.2.5.4} , iterator1=1, iterator2=1
            CHECK(iterator1 == iterator2); 
            CHECK_FALSE(iterator1 != iterator2);
            CHECK_FALSE(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator1; //iterator1=14 iterator2=1
            CHECK_FALSE(iterator1 == iterator2);
            CHECK(iterator1 != iterator2);
            CHECK(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator2;  //iterator1=14 iterator2=14
            CHECK(iterator1 == iterator2);
            CHECK_FALSE(iterator1 != iterator2);
            CHECK_FALSE(iterator1 > iterator2);
            CHECK_FALSE(iterator1 < iterator2);

            ++iterator1; //iterator1=2 iterator2=14
            CHECK_FALSE(iterator1 == iterator2);
            CHECK(iterator1 != iterator2);
            CHECK_FALSE(iterator1 > iterator2);
            CHECK(iterator1 < iterator2);

       
          
        }
    }    




