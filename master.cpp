//
//  master.cpp
//  homework2
//
//  Created by Aarju Goyal on 10/23/19.
//  Copyright © 2019 Aarju Goyal. All rights reserved.
//

#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <fstream>
#define board_size 16
using namespace std;

int main()
{
    //char player1 = 'B';
    //char player2 = 'W';
    //float time = 100.00;
    ifstream output_read;
    fstream input_generate;
    char temp;
    string move;
    string board[19];
    
    int initial_X_pos, initial_Y_pos, final_X_pos, final_Y_pos;
    //cout<<"Enter Initial X_pos and Y_pos: ";
    //cin>>initial_X_pos>>initial_Y_pos;
    //cout<<"Enter final X_pos and Y_pos: ";
    //cin>>final_X_pos>>final_Y_pos;

    output_read.open("direct_output.txt");
    getline(output_read, move);
    initial_X_pos = atoi(move.c_str());
    getline(output_read, move);
    initial_Y_pos = atoi(move.c_str());
    getline(output_read, move);
    final_X_pos = atoi(move.c_str());
    getline(output_read, move);
    final_Y_pos = atoi(move.c_str());
    cout<<initial_X_pos;
    cout<<initial_Y_pos;
    cout<<final_X_pos;
    cout<<final_Y_pos;

    input_generate.open("board.txt", ios::in);
    for(int i=0; i<19; i++)
    {
        //cout<<i<<endl;
        getline(input_generate,board[i]);
        //cout<<board[i];
    }
    cout<<endl;
    for (int i =3; i<board_size + 3; i++)
    {
            for (int j=0; j<board_size; j++)
                cout<<board[i][j];
            cout<<endl;
    }
    input_generate.close();
    if(board[1] == "BLACK")
    {
    
        board[1] = "WHITE";
    }
    else if(board[1] == "WHITE")
    {
        board[1] = "BLACK";
    }
    cout<<"initial "<<board[initial_Y_pos+3 ][initial_X_pos]<< " final "<<board[final_Y_pos + 3][final_X_pos]<<endl;
    //cout<<"initial "<<board[0][0]<< " final "<<board[final_Y_pos][final_X_pos];
    temp = board[initial_Y_pos + 3][initial_X_pos];
    board[initial_Y_pos + 3][initial_X_pos] = board[final_Y_pos + 3][final_X_pos];
    board[final_Y_pos + 3][final_X_pos] = temp;
    input_generate.open("board.txt", ios::out);
    for(int i=0; i<19; i++)
    {
        input_generate<<board[i]<<endl;
        //putline(input_generate,board[i]);
    }
    for (int i =3; i<board_size + 3; i++)
    {
            for (int j=0; j<board_size; j++)
                cout<<board[i][j];
            cout<<endl;
    }
    input_generate.close();
    
    return 0;
    
}
