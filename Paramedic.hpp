#pragma once

#include <stdexcept>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include <assert.h>

/**
 * FootSoldier: initial health points=100, damage per activity=10.
 *FootSoldier - רגלי - יכול ללכת משבצת אחת לכל כיוון. יורה על החייל של האויב שנמצא הכי קרוב אליו (אם יש כמה - הוא יורה על אחד מהם שרירותית)
 *
 */

using namespace std;
namespace WarGame{
    class Paramedic : public Soldier
    {
        static const int Damage = 0;
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
        Paramedic(int player) : Soldier(player, Type::Paramedic, MAX_HP)
        {
            cout << "  con Paramedic1" << endl;
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
           // int curHealth;


            for (int iRow= -1 ; iRow < 2; iRow++) {
                for (int iCol= -1; iCol< 2; iCol++) {
                    if( (sLocation.first+iRow > 0 && sLocation.first+iRow < numRows) && (sLocation.second+iCol > 0 && sLocation.second+iCol < numCols) )
                    {
                        if (gameBoard->matrix[sLocation.first+iRow][sLocation.second+iCol] != nullptr && gameBoard->matrix[sLocation.first+iRow][sLocation.second+iCol]->playerNumber == myPlayerNum )// If its an enemy Soldier
                        {//heal
                            gameBoard->matrix[sLocation.first+iRow][sLocation.second+iCol]->updateHP(200);


                        }
                    }

                }
            }



        }


    };
}