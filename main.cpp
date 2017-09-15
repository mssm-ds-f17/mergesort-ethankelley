#include <iostream>

using namespace std;

class queue
{
   private:

    string* data;


   public:
    int queueSize;
    queue();

     void enqueue(string value);
     void display();
     void displaySingle(int index);
     string dequeue();
     string front();
     bool isEmpty();
     int size();

};
queue::queue(){
    queueSize= 0;
    data= new string[queueSize];

}
void queue::enqueue(string value){

    queueSize++;


    string newArray[queueSize];


    newArray[0]=value;

    for(int y = 0; y <= queueSize; y++){
        string d = data[y];
        newArray[y+1]=d;

    }

    data=newArray;
    delete[] newArray;




}
void queue::display(){

    for(int x = 0; x <= queueSize-1; x++){
        cout<<"["<<x<<"]"<<"="<<data[x]<<" ";
    }
    cout<<endl;

}
void queue::displaySingle(int index){
    cout<<"Index "<<"["<<index<<"]"<<" Contains "<<data[index]<<endl;
}

string queue::dequeue()
{
    return data[queueSize];

    queueSize--;



}
string queue::front(){
    return data[queueSize];

}
bool queue::isEmpty(){
    if(queueSize = 0)
{
        return true;
    }
    else{
        return false;
    }
}
int queue::size(){
    return queueSize;

}



int main(){
    queue myQueue;
    myQueue.enqueue("a");
    myQueue.enqueue("b");
    myQueue.enqueue("c");
    myQueue.enqueue("d");
    /*int x= myQueue.dequeue();

    cout<<"The value taken off of the queue is "<<x<<endl;*/

    myQueue.display();
    myQueue.displaySingle(2);













}
