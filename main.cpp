#include <iostream>
#include <functional>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Thing {
public:
    int id;
    int thingNum;
    string name;
    Thing(int id = 0);
};

Thing::Thing(int id) {
    this->id = id;
}

// return number from 1 to maxValue inclusive
int random(int maxValue) {
    return rand() % maxValue + 1;
}


// ids will range from 1 to maxId
// thingNum will be ascending order
vector<Thing> makeRandomThings(int count, int maxId)
{
    vector<Thing> things;

    for (int i = 0; i < count; i++) {
        things.push_back(Thing{random(maxId)});
    }

    for (int i = 0; i < count; i++) {
        things[i].thingNum = i+1;
    }

    return things;
}
bool compareThingsById(const Thing& a, const Thing& b) {
    return a.id < b.id;
}
bool isMore(const Thing& a, const Thing& b) {
    return a.id > b.id;
}
bool isLess(const Thing& a, const Thing& b) {
    return a.id < b.id;
}

void printThings(vector<Thing> values)
{
    for (int i = 0; i < values.size(); i++) {
        cout << values[i].thingNum <<"(Index "<<i<<") "<< "= " << values[i].id << endl;
    }
}

// assuming already sorted
bool isStable(vector<Thing> values)
{
    for (int i = 0; i < (int)values.size()-1; i++) {
        if (values[i].id == values[i+1].id) {
            if (values[i].thingNum > values[i+1].thingNum) {
                return false;
            }
        }
    }
    return true;
}

bool isSorted(vector<Thing> things, function<bool(const Thing& a, const Thing& b)> lessThan)
{

}






// one option we won't use this time
bool operator<(const Thing& a, const Thing& b) {
    return a.id < b.id;
}

bool isSorted(const vector<int>& values) {
    for (unsigned int i = 1; i < values.size(); i++) {
        if (values[i] < values[i-1]) {
            return false;
        }
    }
    return true;
}

// return true if thing a is less than thing b


bool isSorted(const vector<Thing>& values, function<bool(const Thing& a, const Thing& b)> comp) {
    for (unsigned int i = 1; i < values.size(); i++) {
        if (comp(values[i], values[i-1])) {
            return false;
        }
    }
    return true;
}
void insertValue(const Thing value, vector<Thing>& things){
   things.resize(things.size()+1);

   int insertionPoint =0;

   for(; insertionPoint < things.size(); insertionPoint++){
       if(isLess(value, things[insertionPoint])){
           break;

       }
   }
      things.resize(things.size()+1);




      for(unsigned int i= things.size()-1; i > insertionPoint++;  i--){
          things[i-1]=value;
      }
}
void merge(vector<Thing>& values, int low, int mid, int high, function<bool(const Thing& a, const Thing& b)> comp ){


    vector<Thing> temp;
    temp.resize(high-low+1);
    //temporary vector (result of the merge function)
    int i = low;
    // i is used as a counter for the lower half of the vector
    int k = 0;
    // k is used as a main counter for the new vectors
    int j = mid +1;
    // j is used as a counter for the upper half of the vector

    //merge the first two parts into the temporary vector

    while (i <= mid&& j <= high){
        if(comp(values[i], values[j])){

            //if the value is less than it is placed first in the vector

            temp[k]=values[i];
            i++;

        }
        else{
            //else the other value is placed first
            temp[k]=values[j];
            j++;

        }
        k++;

    }

    //insert all of the remaining values from i to the temp vector if there is anny left
    while(i <= mid)
{
        temp[k]=values[i];
        k++;
        i++;

    }
   //same for j (only either i or j will have any remaining values
    while(j <= high){
        temp[k]=values[j];
        k++;
        j++;
    }

    //copy over the data from the temp vector into the main one
    for(int p= low; p <= high; p++){
        values[p]=temp[p-low];
    }


}






void mergeSort(vector<Thing>& values, int low, int high, function<bool(const Thing& a, const Thing& b)> comp) {
    if(low < high){
            int mid=high/2;
            mergeSort(values, low, mid, isLess );
            //self reference
            mergeSort(values, mid+1, high, isLess);

            //merge to sort the arrays

            merge(values, low,  mid, high, isLess);
    }
}

void insertionSort(vector<Thing>& values, function<bool(const Thing& a, const Thing& b)> comp){

    //create an empty output vector
    // loop through the first vector
    //insert into te output vector in the right spot

    vector<Thing> output;
    for(Thing t: values){
        insertValue(t, output);
    }
    values= output;
}

/*TEST(SortThing, sortNone) {
    vector<Thing> v;
    mergeSort(v, compareThingsById);
    ASSERT_TRUE(isSorted(v, compareThingsById));
}

//**-TEST(SortThing, sortOne) {/
    vector<Thing> v { 5 };    mergeSort(v, compareThingsById);
    ASSERT_TRUE(isSorted(v, c*ompareThingsById));
}

TEST(SortThing, sortTwoA) {
    vector<Thing> v { 3, 4 };
    mergeSort(v, compareThingsById);
    ASSERT_TRUE(isSorted(v, compareThingsById));
}

TEST(SortThing, sortTwoB) {
    vector<Thing> v { 4, 3 };
    mergeSort(v, compareThingsById);
    ASSERT_TRUE(isSorted(v, compareThingsById));
}

TEST(SortThing, sortTwoC) {
    vector<Thing> v { 4, 4 };
    mergeSort(v, compareThingsById);
    ASSERT_TRUE(isSorted(v, compareThingsById));
}

TEST(SortThing, sortThree) {
    vector<Thing> v{ 3, 1, 2 };
    mergeSort(v, compareThingsById);
    ASSERT_TRUE(isSorted(v, compareThingsById);
}

TEST(SortTest, isEmptyVectorSorted) {
    vector<int> v;
    ASSERT_TRUE(isSorted(v));TEST(SortTest, isSingleValueVectorSorted) {
    vector<int> v { 1 };
    ASSERT_TRUE(isSorted(v));
}

TEST(SortTest, isSortedVectorSorted) {
    vector<int> v { 1,3,5,5,9,100 };
    ASSERT_TRUE(isSorted(v));
}

TEST(SortTest, isUnsortedVectorSorted) {
    vector<int> v { 1,3,5,1,9,100 };
    ASSERT_FALSE(isSorted(v));
}
*/


int main(int argc, char **argv) {

    vector<Thing> things;

    things =makeRandomThings(8, 10);

    int a=0;

    int b= things.size();
    printThings(things);
    cout<<endl<<"--------------------------------------"<<endl;
    mergeSort(things, a, b, isLess);
    printThings(things);
   /* ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();*/
}

