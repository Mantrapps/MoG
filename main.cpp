//
//  main.cpp
//  Morris Game Project
//
//  Created by Kaiz on 7/1/16.
//  Copyright © 2016 CS6364. All rights reserved.
//

#include <iostream>

bool closeMill(int i, char board[])
{
    char C;
    C=board[i];
    switch (i) {
        case 0:
            //0-1-2
            //0-3-6
            //0-8-20
            if((board[1]==C && board[2]==C)||(board[3]==C && board[6]==C)||(board[8]==C && board[20]==C))
                return true;
            else return false;
            break;
        case 1:
            //0-1-2
            
            if(board[0]==C && board[2]==C)
                return true;
            else return false;
            break;
        default:
            return false;
            break;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char board="xWWxxxxxxxxxxxxxxxxxxxx";
    if(closeMill(0, &board))
    {
        std::cout << "Hello, World!\n";
    }
    
    return 0;
}




