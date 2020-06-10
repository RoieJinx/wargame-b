#pragma once

#include <stdexcept>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

/**
 * FootSoldier: initial health points=100, damage per activity=10.
 *FootSoldier - רגלי - יכול ללכת משבצת אחת לכל כיוון. יורה על החייל של האויב שנמצא הכי קרוב אליו (אם יש כמה - הוא יורה על אחד מהם שרירותית)
 *
 */

using namespace std;
namespace WarGame{
    class Sniper : public Soldier
    {
        static const int Damage = 50;
        static const int MAX_HP = 100;


    public:
        Sniper(int player) : Soldier(player, Type::Sniper, MAX_HP)
        {
            cout << "  con Sniper1" << endl;
        }
        double distance(std::pair<int,int> mySoldier , int x , int y)
        {
            double d = pow(mySoldier.first-x,2) + pow(mySoldier.second-y,2);
            d = sqrt(d);
            return d;
        }

        void updateHP(int hp)
        {
            int newHP = HP + hp;
            if( newHP > MAX_HP )
                HP = MAX_HP;
            else if( newHP < 0 )
                HP = 0;
            else
                HP = newHP;
        }

        void attack(Board* gameBoard,std::pair<int,int> sLocation)
        {
            //std::vector<std::vector<Soldier*>>& Matrix = (*gameBoard).matrix;
            unsigned int myPlayerNum = (*gameBoard)[sLocation]->playerNumber;
            int numRows = gameBoard->matrix.size();
            int numCols = gameBoard->matrix[0].size();
            int highest_enemy_health = 0; // Very big Number
            std::pair<int,int> target_location;
           int curHealth;


            for (int iRow=0; iRow<numRows; iRow++) {
                for (int iCol=0; iCol<numCols; iCol++) {
                    if (gameBoard->matrix[iRow][iCol] != nullptr && gameBoard->matrix[iRow][iCol]->playerNumber != myPlayerNum )// If its an enemy Soldier
                    {//Calculate the enemy with most health
                        curHealth = gameBoard->matrix[iRow][iCol]->HP;
                        if( curHealth > highest_enemy_health )
                        {   // Update nearest enemy
                            highest_enemy_health = curHealth;
                            target_location.first = iRow;
                            target_location.second = iCol;
                        }
                        else{
                            cout<<"enemy far away"<< endl;
                        }

                    }
                }
            }
            // now we have the location of the target
            // use "heal" to change HP.
            (*gameBoard)[target_location]->updateHP(-1*Sniper::Damage);
            std::cout<<"Soldier : {" << sLocation.first <<"," << sLocation.second <<"} Did " << Damage << " Damage to : {" << target_location.first <<","<<target_location.second <<"}"<< endl;
        }



    };
}