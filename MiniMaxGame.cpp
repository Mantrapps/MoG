//
//  MiniMax Game.cpp
//  Morris Game Project
//
//  Created by Kaiz on 7/1/16.
//  Copyright © 2016 CS6364. All rights reserved.


#include <iostream>
#include <fstream>
#include <vector>
#include "Morris.hpp"

using namespace std;

#define Size_of_board 23


//Position evaluated
int position_evaluated=0;

//initiate generator
generator geo;


//MiniMax
computing MiniMaxGame(int depth,mboard board, bool type)
{
    //need change
    computing comput;
    
    if (depth==0){
        comput.setEstimate(comput.comput_static_midend(board));
        
        position_evaluated++;
        return comput;
    }
    std::vector<mboard> List;
    if (type) //white move - maximize(true)
    {
        List=geo.GenerateMovesMidEndgame(board);

        computing tempcomput;
        comput.setEstimate(-99999);
        for(int i=0;i<List.size();i++)
        {
            
            tempcomput =MiniMaxGame(depth-1, List.at(i), false);
            
            if(comput.getEstimate_value()<tempcomput.getEstimate_value())
            {
                comput.setEstimate(tempcomput.getEstimate_value());
                comput.setBoard(List.at(i));
            }
        }
        
                
    
        return comput;
    }
    else
    {
        List=geo.GenerateMidEnd_Black(board);
        computing tempcomput;
        comput.setEstimate(+99999);
        for(int i=0;i<List.size();i++)
        {

            tempcomput=MiniMaxGame(depth-1, List.at(i), true);
            
            if(comput.getEstimate_value()>tempcomput.getEstimate_value())
            {
                comput.setEstimate(tempcomput.getEstimate_value());
                comput.setBoard(List.at(i));
            }
        }
        return comput;
    }
}



int main(int argc, const char * argv[]) {
    //
    if (argc != 4)
    {
        printf("Missings argument!\n");
        exit(1);
    }
    
    //read inputfile
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);
    int depth=atoi(argv[3]);
    //test only
    //ifstream ifs("/Users/Kaiz/Documents/Xcode/MoG/MoG/input.txt");
    //ofstream ofs("/Users/Kaiz/Documents/Xcode/MoG/MoG/output.txt");
    //int depth=3;

    char board[Size_of_board+1];
    int i=0;
    if(ifs.is_open())
    {
        while (!ifs.eof())
        {
            ifs>>board[i];
            i++;
        }
        ifs.close();
    }
    else{
        std::cout<<"Unable to Open:"<<strerror(errno)<<std::endl;
    }
    

    //std::cout << "Input Board: "<<board<< std::endl;
    
    computing layout=MiniMaxGame(depth, board, true);
    std::cout << "Board Position: "<<layout.getBoard().display()<< std::endl;
    
    std::cout << "Position evaluated by static estimation: "<<position_evaluated<< std::endl;
    std::cout << "MiniMax Estimate: "<<layout.getEstimate_value()<< std::endl;
    
    //write to file
    ofs<<layout.getBoard().display();
    return 0;
}




