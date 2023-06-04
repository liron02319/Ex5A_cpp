#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <algorithm>
#include <vector>
using namespace std;
namespace ariel{};

class MagicalContainer {

private:
    std::vector<int> mysticalElements;

public:

    // distructor,default and copy constructors and Assignment operator(tidy ask for more)
    MagicalContainer() = default;
    ~MagicalContainer() = default;
    MagicalContainer(const MagicalContainer& other) = default;
    MagicalContainer(MagicalContainer&& other) = default;
    MagicalContainer& operator=(const MagicalContainer& other) = default;
    MagicalContainer& operator=(MagicalContainer&& other) = default;
   


    std::vector<int> getElements() const; //help function

    // container functions
    void addElement(int element);
    void removeElement(int element);
    int size() const;





    /*
    //class AscendingIterator
    */

    class AscendingIterator {

    public:

        const MagicalContainer& container;
        std::vector<int>::size_type index;  //position

        // distructor,default and copy constructors and Assignment operator(tidy ask for more)
        AscendingIterator(const MagicalContainer& container): container(container), index(0){}   
        AscendingIterator(const AscendingIterator& other): container(other.container), index(other.index){}
        AscendingIterator(AscendingIterator&& other) = default;
        ~AscendingIterator() = default;       
        AscendingIterator& operator=(const AscendingIterator& other) = delete;
        AscendingIterator& operator=(AscendingIterator&& other) = delete;


        // operators:  == , != , > , < , * , ++ 
        bool operator==(const AscendingIterator& other) const{
            return this->index == other.index;
        }
        bool operator!=(const AscendingIterator& other) const{
            return this ->index != other.index;
        }
        bool operator>(const AscendingIterator& other) const{
            return this ->index > other.index;
        }
        bool operator<(const AscendingIterator& other) const{
            return this ->index < other.index;
        }

        int operator*() const{ 
            return 1;
        }

        AscendingIterator& operator++(){
            index++;
            return *this;
        }

        /*
        • begin(type): Returns the appropriate iterator (ascending, cross, or prime)
         pointing to the first element of the container based on the specified type.
        */
         AscendingIterator begin() const{
            return AscendingIterator(container);
        }

        /*
        • end(type): Returns the appropriate iterator (ascending, cross, or prime)
         pointing one position past the last element of the container based on the specified type.
        */
        AscendingIterator end() const{
            AscendingIterator iterator(container);
            iterator.index = container.mysticalElements.size();
            return iterator;
        }

    };






    /*
    //class SideCrossIterator
    */



    class SideCrossIterator {
        
    private:
        const MagicalContainer& container;
        std::vector<int>::size_type index; //position

    public:

         // distructor,default and copy constructors and Assignment operator(tidy ask for more)
        SideCrossIterator(const MagicalContainer& container) : container(container), index(0){}
        SideCrossIterator(const SideCrossIterator& other) : container(other.container), index(other.index){}
        ~SideCrossIterator() = default;
        SideCrossIterator(SideCrossIterator&& other) = default;
        SideCrossIterator& operator=(const SideCrossIterator& other) = delete;
        SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
     
   
        // operators:  == , != , > , < , * , ++ 
        bool operator==(const SideCrossIterator& other) const{
            return this->index == other.index;
        }
        bool operator!=(const SideCrossIterator& other) const{
            return this ->index != other.index;
        }
        bool operator>(const SideCrossIterator& other) const{
            return this ->index > other.index;
        }
        bool operator<(const SideCrossIterator& other) const{
            return this ->index < other.index;
        }
        int operator*() const{
            return 1;
        }

        SideCrossIterator& operator++(){
            index++;
            return *this;
        }


        /*
        • begin(type): Returns the appropriate iterator (ascending, cross, or prime)
         pointing to the first element of the container based on the specified type.
        */
        SideCrossIterator begin() const{
            return SideCrossIterator(container);
        }


        /*
        • end(type): Returns the appropriate iterator (ascending, cross, or prime)
         pointing one position past the last element of the container based on the specified type.
        */
        SideCrossIterator end() const{
            SideCrossIterator iterator(container);
            iterator.index = container.mysticalElements.size();
            return iterator;
        }


     
    };



    /*
    //class PrimeIterator
    */

    class PrimeIterator {

    private:
        const MagicalContainer& container;
        std::vector<int>::size_type index; //position

    public:

         // distructor,default and copy constructors and Assignment operator(tidy ask for more)
        PrimeIterator(const MagicalContainer& container): container(container), index(0){}
        PrimeIterator(const PrimeIterator& other) : container(other.container), index(other.index){}
        ~PrimeIterator() = default;
        PrimeIterator(PrimeIterator&& other) = default;
        PrimeIterator& operator=(const PrimeIterator& other) = delete;
        PrimeIterator& operator=(PrimeIterator&& other) = delete;
        


        // operators:  == , != , > , < , * , ++ 
        bool operator==(const PrimeIterator& other) const{
            return this->index == other.index;
        }
        bool operator!=(const PrimeIterator& other) const{
            return this ->index != other.index;
        }
        bool operator>(const PrimeIterator& other) const{
            return this ->index > other.index;
        }
        bool operator<(const PrimeIterator& other) const{
            return this ->index < other.index;
        }

        int operator*() const{
            return 1;
        }


        PrimeIterator& operator++(){
            index++;
            return *this;
        }



         /*
        • begin(type): Returns the appropriate iterator (ascending, cross, or prime)
         pointing to the first element of the container based on the specified type.
        */
        PrimeIterator begin() const{
            return PrimeIterator(container);
        }


        /*
        • end(type): Returns the appropriate iterator (ascending, cross, or prime)
         pointing one position past the last element of the container based on the specified type.
        */
        PrimeIterator end() const{
            PrimeIterator iterator(container);
            iterator.index = container.mysticalElements.size();
            return iterator;
        }


    };





};


#endif