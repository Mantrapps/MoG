//
//  Morris.hpp
//  MoG
//
//  Created by Kaiz on 7/19/16.
//  Copyright © 2016 CS6364. All rights reserved.
//

#ifndef Morris_hpp
#define Morris_hpp

#include <stdio.h>
#include <iostream>


class mboard
{
    std::vector<char> position_value;
public:
    //constructor
    mboard();
    //set board position values
    mboard(char board_position_values[]);
    //set value at index
    void setPosition_Value(int index, char value);
    //get value at index
    char getPosition_Value(int index);
    //get Position Values
    std::vector<char> getPosition();
    //display
    std::string display();
    //num of 'W' or 'B' pieces
    int getNum_of_Pieces(char type);
};


class generator
{
    int size;
public:
    // Generate Moves at game opening
    std::vector<mboard> GenerateMovesOpening(mboard board);
    //Used at Opening, Generate moves created by adding a piece
    std::vector<mboard> GenerateAdd (mboard board);
    // Generate Moves at Mid/End game
    std::vector<mboard> GenerateMovesMidEndgame(mboard board);
    // Generate Moves at Mid game
    std::vector<mboard> GenerateMove(mboard board);
    // Generate Moves at End game
    std::vector<mboard> GenerateHopping (mboard board);
    
    // If Mill, remove from board
    std::vector<mboard> GenerateRemove(mboard board, std::vector<mboard> List);
    
    // Generate Move for black piece at game opening
    std::vector<mboard> GenerateMoveOpening_Black(mboard board);
    
    // Generate Move for black piece at mid End game
    std::vector<mboard> GenerateMidEnd_Black(mboard board);
    //get color swapped board
    mboard getBoard_color_swapped(mboard board);

    // Improved Move
    
};

//store estimate value and position evaluated
class computing
{
    // estimate value
    int estimate_value=0;
    
    mboard board_out;
public:

    int comput_static_opening(mboard board);
    
    int comput_static_midend(mboard board);
    
    int comput_static_opening_black(mboard board);
    
    int comput_static_midend_black(mboard board);
    
    //improved opening get more chance of mills
    int comput_static_opening_improved(mboard board);
    //improved midend
    int comput_static_midend_improved(mboard board);
    
    int getEstimate_value();
    
    mboard getBoard();

    void setEstimate(int estimate);

    
    void setBoard(mboard board);
    
};

#endif /* Morris_hpp */
