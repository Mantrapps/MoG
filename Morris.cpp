//
//  Morris.cpp
//  MoG
//
//  Created by Kaiz on 7/19/16.
//  Copyright © 2016 CS6364. All rights reserved.
//
#include <iostream>
#include <vector>
#include "Morris.hpp"

#define Size_of_board 23


//Check if Mill exist
bool closeMill(int i, mboard board)
{
    char C;
    C=board.getPosition_Value(i);
    if(C=='x') {return false;}
    switch (i) {
        case 0:
            //0-1-2
            //0-3-6
            //0-8-20
            if((board.getPosition_Value(1)==C && board.getPosition_Value(2)==C)||(board.getPosition_Value(3)==C && board.getPosition_Value(6)==C)||(board.getPosition_Value(8)==C && board.getPosition_Value(20)==C))
                return true;
            else return false;
            break;
        case 1:
            //0-1-2
            if(board.getPosition_Value(0)==C && board.getPosition_Value(2)==C)
                return true;
            else return false;
            break;
        case 2:
            if((board.getPosition_Value(0)==C && board.getPosition_Value(1)==C)||(board.getPosition_Value(5)==C && board.getPosition_Value(7)==C)||(board.getPosition_Value(13)==C && board.getPosition_Value(22)==C))
                return true;
            else return false;
            break;
        case 3:
            if((board.getPosition_Value(0)==C && board.getPosition_Value(6)==C)||(board.getPosition_Value(4)==C && board.getPosition_Value(5)==C)||(board.getPosition_Value(9)==C && board.getPosition_Value(17)==C))
                return true;
            else return false;
            break;
        case 4:
            if(board.getPosition_Value(3)==C && board.getPosition_Value(5)==C)
                return true;
            else return false;
            break;
        case 5:
            if((board.getPosition_Value(4)==C && board.getPosition_Value(3)==C)||(board.getPosition_Value(12)==C && board.getPosition_Value(19)==C)||(board.getPosition_Value(2)==C && board.getPosition_Value(7)==C))
                return true;
            else return false;
            break;
        case 6:
            if((board.getPosition_Value(3)==C && board.getPosition_Value(0)==C)||(board.getPosition_Value(10)==C && board.getPosition_Value(14)==C))
                return true;
            else return false;
            break;
        case 7:
            if((board.getPosition_Value(11)==C && board.getPosition_Value(16)==C)||(board.getPosition_Value(5)==C && board.getPosition_Value(2)==C))
                return true;
            else return false;
            break;
        case 8:
            if((board.getPosition_Value(0)==C && board.getPosition_Value(20)==C)||(board.getPosition_Value(9)==C && board.getPosition_Value(10)==C))
                return true;
            else return false;
            break;
        case 9:
            if((board.getPosition_Value(17)==C && board.getPosition_Value(3)==C)||(board.getPosition_Value(8)==C && board.getPosition_Value(10)==C))
                return true;
            else return false;
            break;
        case 10:
            if((board.getPosition_Value(8)==C && board.getPosition_Value(9)==C)||(board.getPosition_Value(6)==C && board.getPosition_Value(14)==C))
                return true;
            else return false;
            break;
        case 11:
            if((board.getPosition_Value(16)==C && board.getPosition_Value(7)==C)||(board.getPosition_Value(12)==C && board.getPosition_Value(13)==C))
                return true;
            else return false;
            break;
        case 12:
            if((board.getPosition_Value(19)==C && board.getPosition_Value(5)==C)||(board.getPosition_Value(11)==C && board.getPosition_Value(13)==C))
                return true;
            else return false;
            break;
        case 13:
            if((board.getPosition_Value(11)==C && board.getPosition_Value(12)==C)||(board.getPosition_Value(22)==C && board.getPosition_Value(2)==C))
                return true;
            else return false;
            break;
        case 14:
            if((board.getPosition_Value(10)==C && board.getPosition_Value(6)==C)||(board.getPosition_Value(17)==C && board.getPosition_Value(20)==C)||(board.getPosition_Value(15)==C && board.getPosition_Value(16)==C))
                return true;
            else return false;
            break;
        case 15:
            if((board.getPosition_Value(18)==C && board.getPosition_Value(21)==C)||(board.getPosition_Value(14)==C && board.getPosition_Value(16)==C))
                return true;
            else return false;
            break;
        case 16:
            if((board.getPosition_Value(14)==C && board.getPosition_Value(15)==C)||(board.getPosition_Value(11)==C && board.getPosition_Value(7)==C)||(board.getPosition_Value(19)==C && board.getPosition_Value(22)==C))
                return true;
            else return false;
            break;
        case 17:
            if((board.getPosition_Value(20)==C && board.getPosition_Value(14)==C)||(board.getPosition_Value(18)==C && board.getPosition_Value(19)==C)||(board.getPosition_Value(9)==C && board.getPosition_Value(3)==C))
                return true;
            else return false;
            break;
        case 18:
            if((board.getPosition_Value(21)==C && board.getPosition_Value(15)==C)||(board.getPosition_Value(17)==C && board.getPosition_Value(19)==C))
                return true;
            else return false;
            break;
        case 19:
            if((board.getPosition_Value(16)==C && board.getPosition_Value(22)==C)||(board.getPosition_Value(12)==C && board.getPosition_Value(5)==C)||(board.getPosition_Value(17)==C && board.getPosition_Value(18)==C))
                return true;
            else return false;
            break;
        case 20:
            if((board.getPosition_Value(8)==C && board.getPosition_Value(0)==C)||(board.getPosition_Value(17)==C && board.getPosition_Value(14)==C)||(board.getPosition_Value(21)==C && board.getPosition_Value(22)==C))
                return true;
            else return false;
            break;
        case 21:
            if((board.getPosition_Value(18)==C && board.getPosition_Value(15)==C)||(board.getPosition_Value(22)==C && board.getPosition_Value(20)==C))
                return true;
            else return false;
            break;
        case 22:
            if((board.getPosition_Value(19)==C && board.getPosition_Value(16)==C)||(board.getPosition_Value(13)==C && board.getPosition_Value(2)==C)||(board.getPosition_Value(21)==C && board.getPosition_Value(20)==C))
                return true;
            else return false;
            break;
            
        default:
            return false;
            break;
    }
}

//Check Neighbours
std::vector<int> neighbours(int i)
{
    std::vector<int> neighbs;
    switch (i) {
        case 0:
            neighbs.push_back(1);
            neighbs.push_back(3);
            neighbs.push_back(8);
            break;
        case 1:
            neighbs.push_back(0);
            neighbs.push_back(2);
            neighbs.push_back(4);
            break;
        case 2:
            neighbs.push_back(1);
            neighbs.push_back(5);
            neighbs.push_back(13);
            break;
        case 3:
            neighbs.push_back(0);
            neighbs.push_back(4);
            neighbs.push_back(6);
            neighbs.push_back(9);
            break;
        case 4:
            neighbs.push_back(1);
            neighbs.push_back(3);
            neighbs.push_back(5);
            break;
        case 5:
            neighbs.push_back(2);
            neighbs.push_back(4);
            neighbs.push_back(12);
            neighbs.push_back(7);
            break;
        case 6:
            neighbs.push_back(3);
            neighbs.push_back(7);
            neighbs.push_back(10);
            break;
        case 7:
            neighbs.push_back(5);
            neighbs.push_back(6);
            neighbs.push_back(11);
            break;
        case 8:
            neighbs.push_back(0);
            neighbs.push_back(9);
            neighbs.push_back(20);
            break;
        case 9:
            neighbs.push_back(3);
            neighbs.push_back(8);
            neighbs.push_back(10);
            neighbs.push_back(17);
            break;
        case 10:
            neighbs.push_back(6);
            neighbs.push_back(9);
            neighbs.push_back(14);
            break;
        case 11:
            neighbs.push_back(7);
            neighbs.push_back(12);
            neighbs.push_back(16);
            break;
        case 12:
            neighbs.push_back(5);
            neighbs.push_back(11);
            neighbs.push_back(13);
            neighbs.push_back(19);
            break;
        case 13:
            neighbs.push_back(2);
            neighbs.push_back(12);
            neighbs.push_back(22);
            break;
        case 14:
            neighbs.push_back(10);
            neighbs.push_back(15);
            neighbs.push_back(17);
            break;
        case 15:
            neighbs.push_back(14);
            neighbs.push_back(16);
            neighbs.push_back(18);
            break;
        case 16:
            neighbs.push_back(11);
            neighbs.push_back(15);
            neighbs.push_back(19);
            break;
        case 17:
            neighbs.push_back(9);
            neighbs.push_back(14);
            neighbs.push_back(18);
            neighbs.push_back(20);
            break;
        case 18:
            neighbs.push_back(15);
            neighbs.push_back(17);
            neighbs.push_back(19);
            neighbs.push_back(21);
            break;
        case 19:
            neighbs.push_back(12);
            neighbs.push_back(16);
            neighbs.push_back(18);
            neighbs.push_back(22);
            break;
        case 20:
            neighbs.push_back(8);
            neighbs.push_back(17);
            neighbs.push_back(21);
            break;
        case 21:
            neighbs.push_back(18);
            neighbs.push_back(20);
            neighbs.push_back(22);
            break;
        case 22:
            neighbs.push_back(13);
            neighbs.push_back(19);
            neighbs.push_back(21);
            break;
            
        default:
            return neighbs;
            break;
    }
    return neighbs;
}

//swap color
mboard swap_color(mboard board)
{
    mboard temp=board;
    for(int i=0;i<temp.getPosition().size();i++)
    {
        if (temp.getPosition_Value(i)=='W')
        {
            temp.setPosition_Value(i,'B');
        }
        else if (temp.getPosition_Value(i)=='B')
        {
            temp.setPosition_Value(i,'W');
        }
    }
    return  temp;
    
}
//swap color for array
std::vector<mboard> swap_color_List(std::vector<mboard> List)
{
    for(int i=0;i<List.size();i++)
    {
        mboard temp;
        temp=swap_color(List.at(i));
        //???
        List.at(i)=temp;
    }
    return  List;
}



mboard::mboard()
{

    int i;
    for(i=0;i<Size_of_board;i++)
    {
        position_value.push_back('x');
    }
   
    
}
mboard::mboard(char values[])
{
    int i;
    if((strlen(values))==Size_of_board)
    {
        for(i=0;i<Size_of_board;i++)
        {
            position_value.push_back(values[i]);
        }
    }
}
std::string mboard::display()
{
    char temp[Size_of_board+1];
    std::string output;
    for (int i=0; i<Size_of_board; i++) {
        temp[i]=position_value.at(i);
    }
    output=(std::string)temp;
    return output;
}

std::vector<char> mboard::getPosition()
{
    
    return position_value;
}

void mboard::setPosition_Value(int index, char value)
{
    position_value.at(index)=value;
}

char mboard::getPosition_Value(int index)
{
    return position_value.at(index);
}

int mboard::getNum_of_Pieces(char type)
{
    int num=0;
    
    for(int i=0;i<position_value.size();i++)
    {
        if(position_value.at(i)==type)
        {
            num++;
        }
    }
    return num;
}

mboard generator::getBoard_color_swapped(mboard board)
{
    return swap_color(board);
}

//open game
std::vector<mboard> generator::GenerateMovesOpening(mboard board)
{
    //return the list of board positions produced by generatedadd
    return GenerateAdd(board);
}

std::vector<mboard> generator::GenerateAdd(mboard board)
{

    int i=0;
    //a list of board positions
    std::vector<mboard> List;
    for(i=0;i<board.getPosition().size();i++)
    {
        if(board.getPosition_Value(i)=='x')
        {

            mboard board_copy=board;
            board_copy.setPosition_Value(i, 'W');
            if(closeMill(i, board_copy))
            {
                List = GenerateRemove(board_copy, List);
            }
            else
            {
                List.push_back(board_copy);
            }
        }
    }
    return List;
    
}

//mid end game
std::vector<mboard> generator::GenerateMovesMidEndgame(mboard board)
{
    if(board.getNum_of_Pieces('W')==3) //hopping
    {
        return GenerateHopping(board);
    }
    else{return GenerateMove(board);}

}

//Move
std::vector<mboard> generator::GenerateMove(mboard board)
{
    int i=0;
    //a list of board positions
    std::vector<mboard> List;
    for(i=0;i<board.getPosition().size();i++)
    {
        if(board.getPosition_Value(i)=='W')
        {
            
            std::vector<int> nbs=neighbours(i);
            for (int j=0; j<nbs.size(); j++) {
                int k=nbs.at(j);
                if(board.getPosition_Value(k)=='x')
                {
                    mboard board_copy=board;
                    board_copy.setPosition_Value(i, 'x');
                    board_copy.setPosition_Value(k, 'W');
                    if(closeMill(k, board_copy))
                    {
                        List = GenerateRemove(board_copy, List);
                    }
                    else
                    {
                        List.push_back(board_copy);
                    }
                }
            }
        }
    }
    return List;
    
}

//Hopping
std::vector<mboard> generator::GenerateHopping(mboard board)
{
    int i=0;
    //a list of board positions
    std::vector<mboard> List;
    for(i=0;i<board.getPosition().size();i++)
    {
        if(board.getPosition_Value(i)=='W')
        {
            for (int j=0; j<board.getPosition().size(); j++)
            {
                //any place 'x'
                if(board.getPosition_Value(j)=='x')
                {
                    mboard board_copy=board;
                    board_copy.setPosition_Value(i, 'x');
                    board_copy.setPosition_Value(j, 'W');
                    if(closeMill(j, board_copy))
                    {
                        List = GenerateRemove(board_copy, List);
                    }
                    else
                    {
                        List.push_back(board_copy);
                    }
                }
            }
        }
    }
    return List;
}

std::vector<mboard> generator::GenerateMoveOpening_Black(mboard board)
{
    std::vector<mboard> List;
    mboard board_swapped;
    board_swapped=swap_color(board);
    List=GenerateMovesOpening(board_swapped);
    
    std::vector<mboard> List2;
    List2=swap_color_List(List);
    return List2;
}

std::vector<mboard> generator::GenerateMidEnd_Black(mboard board)
{
    std::vector<mboard> List;
    mboard board_swapped;
    board_swapped=swap_color(board);
    List =GenerateMovesMidEndgame(board_swapped);
    std::vector<mboard> List2;
    List2=swap_color_List(List);
    return List2;
}

std::vector<mboard> generator::GenerateRemove(mboard board, std::vector<mboard> List)
{
    int i;
    
    for(i=0;i<board.getPosition().size();i++)
    {
        if(board.getPosition_Value(i)=='B')
        {
            if(!closeMill(i, board))
            {
                //???
                mboard board_copy=board;
                board_copy.setPosition_Value(i, 'x');
                List.push_back(board_copy);
            }
        }
    }
    return List;
}

int computing::comput_static_opening(mboard board)
{
    int sum_w=0;
    int sum_b=0;
    for(int i=0;i<board.getPosition().size();i++)
    {
        if (board.getPosition_Value(i)=='W')
        {
            sum_w++;
        }
        else if (board.getPosition_Value(i)=='B')
        {
            sum_b++;
        }
        
    }
    return sum_w - sum_b;
}

int computing::comput_static_midend(mboard board)
{
    generator gen;
    int numBlackMoves=0;
    //board position generated by black
    
    std::vector<mboard> List=gen.GenerateMidEnd_Black(board);
    numBlackMoves= static_cast<int>(List.size());

    //???
    int numWhitePieces;
    numWhitePieces=board.getNum_of_Pieces('W');
    int numBlackPieces;
    numBlackPieces=board.getNum_of_Pieces('B');
    if(numBlackPieces<=2)
    {
        return 10000;
    }
    else if (numWhitePieces<=2)
    {
        return -10000;
    }
    else if(numBlackMoves==0)
    {
        return 10000;
    }
    else return (1000*(numWhitePieces-numBlackPieces)-numBlackMoves);
}

int computing::comput_static_opening_improved(mboard board)
{
    //get more mills chance for white
    int number_mills=0;
    for(int i=0;i<Size_of_board;i++)
    {
        if (board.getPosition_Value(i)=='x') {
            mboard tmp=board;
            tmp.setPosition_Value(i, 'W');
            if (closeMill(i, tmp)) {
                number_mills++;
            }
        }
    }
    return comput_static_opening(board)+ number_mills;
}

int computing::comput_static_midend_improved(mboard board)
{
    //get more mills chance for white
    int number_mills=0;
    for(int i=0;i<Size_of_board;i++)
    {
        if (board.getPosition_Value(i)=='x') {
            mboard tmp=board;
            tmp.setPosition_Value(i, 'W');
            if (closeMill(i, tmp)) {
                number_mills++;
            }
        }
    }
    generator gen;
    int numBlackMoves=0;
    //board position generated by black
    
    std::vector<mboard> List=gen.GenerateMidEnd_Black(board);
    numBlackMoves= static_cast<int>(List.size());
    
    int numWhitePieces;
    numWhitePieces=board.getNum_of_Pieces('W');
    int numBlackPieces;
    numBlackPieces=board.getNum_of_Pieces('B');
    if(numBlackPieces<=2)
    {
        return 10000;
    }
    else if (numWhitePieces<=2)
    {
        return -10000;
    }
    else if(numBlackMoves==0)
    {
        return 10000;
    }
    
    else return (1000*(numWhitePieces+number_mills-numBlackPieces)-numBlackMoves);
}

//Est for black open game
int computing::comput_static_opening_black(mboard board)
{
    int sum_w=0;
    int sum_b=0;
    for(int i=0;i<board.getPosition().size();i++)
    {
        if (board.getPosition_Value(i)=='W')
        {
            sum_w++;
        }
        else if (board.getPosition_Value(i)=='B')
        {
            sum_b++;
        }
        
    }
    return sum_b-sum_w;
}
//Est for black mid/end game
int computing::comput_static_midend_black(mboard board)
{
    generator gen;
    int numWhiteMoves=0;
    //board position generated by white
    
    std::vector<mboard> List=gen.GenerateMovesMidEndgame(board);
    numWhiteMoves= static_cast<int>(List.size());
    
    int numWhitePieces;
    numWhitePieces=board.getNum_of_Pieces('W');
    int numBlackPieces;
    numBlackPieces=board.getNum_of_Pieces('B');
    if(numWhitePieces<=2)
    {
        return 10000;
    }
    else if (numBlackPieces<=2)
    {
        return -10000;
    }
    else if(numWhiteMoves==0)
    {
        return 10000;
    }
    else return (1000*(numBlackPieces - numWhitePieces)-numWhiteMoves);
}

int computing::getEstimate_value()
{
    return estimate_value;
}


mboard computing::getBoard()
{
    return board_out;
}

void computing::setEstimate(int estimate)
{
    estimate_value=estimate;
}


void computing::setBoard(mboard board)
{
    board_out=board;
}




