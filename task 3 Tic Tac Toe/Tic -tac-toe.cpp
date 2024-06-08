#include<iostream>
#include<cstdlib>
using namespace std;

char token;
char index[3][3];
bool tie;
void reset(){                                           // If player again play then reset array(due to global)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           index[i][j]=' ';
        }
    }
}
int funcheck()                              //  // check is any player win or tie or ongoing
{
    for(int i=0; i<3; i++){
        if(((index[i][0]=='X' || index[i][0]=='O')&&index[i][0]==index[i][1])&&(index[i][0]==index[i][2]) || (index[0][i]=='X' || index[0][i]=='O')&&(index[0][i]==index[1][i])&&(index[0][i]==index[2][i]))   
        return true;
    }
        if((index[0][0]==index[1][1])&&(index[0][0]==index[2][2])&&(index[0][0]=='X'||index[0][0]=='O') || (index[0][2]==index[1][1])&&(index[0][2]==index[2][0])&&(index[0][2]=='X'||index[0][2]=='O'))
        return true; 

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(index[i][j]!='X' && index[i][j]!='O')
            return false;
        }
    }
    tie=true;
    return false;
}
void input()                        // input from user and decide row & column number (for i & j)
{
    top:
    int row,column;
    int N;
    if(token=='X'){
    cout<<"Player:X The number:-";
    cin>>N;
    }
    else{
    cout<<"Player:O The number:-";
    cin>>N;
    }
    switch(N){
    case 1:
        row=0;
        column=0;
        break;
    case 2:
        row=0;
        column=1;
        break;
    case 3:
        row=0;
        column=2;
        break;
    case 4:
        row=1;
        column=0;
        break;
    case 5:
        row=1;
        column=1;
        break;
    case 6:
        row=1;
        column=2;
        break;
    case 7:
        row=2;
        column=0;
        break;
    case 8:
        row=2;
        column=1;
        break;
    case 9:
        row=2;
        column=2;
        break;
    default :
        cout<<"\n😒 Oops Wrong input please Try again!\n";
        goto top;   
    }
    if(token=='X'&& (index[row][column]!='X'&& index[row][column]!='O')){               // put in array if already not filled
        index[row][column]='X';
        token='O';                                          // after put change the player
    }
    else if(token=='O'&& (index[row][column]!='X'&& index[row][column]!='O')){
        index[row][column]='O';
        token='X';
    }
    else {
         cout<<"\nAlredy Filled retry";                             // if filed then retry
        goto top;
    }

}

int main()
{
    first:
    reset();
    tie=0;
    int a;
    char ch;
    cout<<endl;
    cout<<"      |       |     \n";
    cout<<"      |       |     \n";
    cout<<"      |       |     \n";
    cout<<"||_\n";
    cout<<"      |       |     \n";
    cout<<"      |       |     \n";
    cout<<"      |       |     \n";
    cout<<"||_\n";
    cout<<"      |       |     \n";
    cout<<"      |       |     \n";
    cout<<"      |       |     \n";
    cout<<endl<<endl;
    cout<<"🎉🎉🎉🎉WELLcome To TIC-TAC-TOE Gam🎮🎱🎉🎉🎉🎉\n";
    cout<<"Please choose (1-9)..!";
    token='X';
    top:
    input();                               // CAll input function to input And initialize in array(name:index[][]) 
    a= funcheck();                          // check is any player win or tie or ongoing
    if(a){
        cout<<"-------------------------------------------------\n";
        cout<<"\n👍Congratulation..! You Win😍..\n\n";
        cout<<"-------------------------------------------------\n";
        cout<<"Do You Want To Play More (y/n)?";
        cin>>ch;
        if(ch=='y'|| ch=='Y'){
            goto first;
        }
        else return 0;
    }
    else {
        if(tie){                                // When tie found
            cout<<"\nOhh.. It's Tie.. \n";
            cout<<"Do You Want To Play More (y/n)?";
        cin>>ch;
        if(ch=='y'|| ch=='Y'){
            goto first;
        }
        else return 0;
        }
        
    }                            
    cout<<endl;
    cout<<"      |      |     \n";
    cout<<"    "<<index[0][0]<<" |   "<<index[0][1]<<"  |  "<<index[0][2]<<" ; \n";
    cout<<"||\n";
    cout<<"      |      |     \n";
    cout<<"    "<<index[1][0]<<" |   "<<index[1][1]<<"  |  "<<index[1][2]<<" ; \n";
    cout<<"||\n";
    cout<<"      |      |     \n";
    cout<<"    "<<index[2][0]<<" |   "<<index[2][1]<<"  |  "<<index[2][2]<<" ; \n";
    cout<<"      |      |     \n";
    goto top;
}


