#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){

    int img_number;
    // gen_ random numeber based in device time
    srand(static_cast<unsigned int >(time(0)));
    // range 0 to 32767 (platfrom dependent) using modulo operator to get desired range 
    int GeneratedNumber = rand() %100 + 1;
    cout<<"*** WELCOME TO NUMBER GUESSING GAME ***"<<endl;
    do{
        cout<<"Guess a Number from 1 to 100"<<endl;
        cin>>img_number;
        if(int(img_number)){
            if(img_number > GeneratedNumber){
                cout<<"too High !"<<endl;
            }else if(img_number < GeneratedNumber){
                cout<<"Too low !"<<endl;
            }else{
                cout<<"Congratulations! You Guessed it right."<<endl;
            }
           
        }else{
            cout<<"Invalid Input , Please try again"<<endl;
            break;
        }
    }while (img_number != GeneratedNumber);
     
       

    return 0;
}