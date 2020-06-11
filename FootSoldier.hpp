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
class FootSoldier : public Soldier
{
   static const int Damage = 10;
    static const int MAX_HP = 100;

   /**
    * Position location;
    Board *board;
    unsigned int playerNumber; // Who own me?
    enum class Type {
        FootSolider, FootSoliderCommander, Sniper, SniperCommander, Paramedic, ParamedicCommander
    };
    Type type;
    //initial health points
    static const int InitialHealthPoints;
    int HP;
    */
public:
    FootSoldier(int player) : Soldier(player, Type::FootSolider, MAX_HP)
    {
        cout << "  con FootSolider1" << endl;
    }

    double distance(std::pair<int,int> mySoldier , int x , int y)
    {
        double d = pow(mySoldier.first-x,2) + pow(mySoldier.second-y,2);
        d = sqrt(d);
        return d;
    }

    bool updateHP(int hp)
    {
        int newHP = HP + hp;
        if( newHP > MAX_HP )
        {
            HP = MAX_HP;
            return false;
        }
        else if( newHP <= 0 )
        {
            //delete this;
            return false;
        }
        else
        {
            HP = newHP;
            return true;
        }
    }

    void attack(Board* gameBoard,std::pair<int,int> sLocation)
    {
        //std::vector<std::vector<Soldier*>>& Matrix = (*gameBoard).matrix;
        unsigned int myPlayerNum = (*gameBoard)[sLocation]->playerNumber;
        int numRows = gameBoard->matrix.size();
        int numCols = gameBoard->matrix[0].size();
        double nearest_enemy_distance = 100000000; // Very big Number
        std::pair<int,int> nearest_enemy_location;
        double dis;


        for (int iRow=0; iRow<numRows; iRow++) {
            for (int iCol=0; iCol<numCols; iCol++) {
                if (gameBoard->matrix[iRow][iCol] != nullptr && gameBoard->matrix[iRow][iCol]->playerNumber != myPlayerNum )// If its an enemy Soldier
                {//Calculate Distance
                     dis = distance(sLocation,iRow,iCol);
                   if( dis < nearest_enemy_distance )
                    {   // Update nearest enemy
                        nearest_enemy_distance = dis;
                        nearest_enemy_location.first = iRow;
                        nearest_enemy_location.second = iCol;
                    }
                    else{
                        cout<<"enemy far away"<< endl;
                    }

                }
            }
        }
        // now we have the location of the target
        // use "heal" to change HP.
        //(*gameBoard)[nearest_enemy_location]->updateHP(-1*FootSoldier::Damage);

        if( (*gameBoard)[nearest_enemy_location]->updateHP(-1*FootSoldier::Damage) );// If Target is dead ,delete soldier  and change the pointer to null on the board.
        {
            delete (*gameBoard)[nearest_enemy_location];
            (*gameBoard)[nearest_enemy_location] = nullptr;
            std::cout <<" Should be destructed " << endl;

        }

        std::cout<<"Soldier : {" << sLocation.first <<"," << sLocation.second <<"} Did " << Damage << " Damage to : {" << nearest_enemy_location.first <<","<<nearest_enemy_location.second <<"}"<< endl;
    }


    };



}