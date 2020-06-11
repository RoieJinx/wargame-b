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
    class ParamedicCommander : public Soldier
    {
        static const int Damage = 0;
        static const int MAX_HP = 200;

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
        ParamedicCommander(int player) : Soldier(player, Type::ParamedicCommander, MAX_HP)
        {
            cout << "  con ParamedicCommander1" << endl;
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



            void attack(Board* gameBoard,std::pair<int,int> sLocation) {
                if ((*gameBoard).has_soldiers(1) && (*gameBoard).has_soldiers(2)) {
                    //std::vector<std::vector<Soldier*>>& Matrix = (*gameBoard).matrix;
                    unsigned int myPlayerNum = (*gameBoard)[sLocation]->playerNumber;
                    int numRows = gameBoard->matrix.size();
                    int numCols = gameBoard->matrix[0].size();
                    int highest_enemy_health = 0; // Very big Number
                    std::pair<int, int> target_location;
                    // int curHealth;

                    //
                    for (int iRow = -1; iRow < 2; iRow++) {
                        for (int iCol = -1; iCol < 2; iCol++) {
                            if (iRow != 0 && iCol != 0) {
                                if ((sLocation.first + iRow > 0 && sLocation.first + iRow < numRows) &&
                                    (sLocation.second + iCol > 0 && sLocation.second + iCol < numCols)) {
                                    if (gameBoard->matrix[sLocation.first + iRow][sLocation.second + iCol] != nullptr &&
                                        gameBoard->matrix[sLocation.first + iRow][sLocation.second +
                                                                                  iCol]->playerNumber ==
                                        myPlayerNum)// If its an enemy Soldier
                                    {//heal
                                        gameBoard->matrix[sLocation.first + iRow][sLocation.second + iCol]->updateHP(
                                                200);


                                    }
                                }
                            }


                        }
                    }




                    // Finding other Snipers and make them attack
                    for (int iRow = 0; iRow < numRows; iRow++) {
                        for (int iCol = 0; iCol < numCols; iCol++) {
                            if (gameBoard->matrix[iRow][iCol] != nullptr &&
                                gameBoard->matrix[iRow][iCol]->playerNumber == myPlayerNum &&
                                gameBoard->matrix[iRow][iCol]->type ==
                                Soldier::Type::Paramedic)// If its an enemy Soldier
                                gameBoard->matrix[iRow][iCol]->attack(gameBoard, {iRow, iCol});
                        }

                    }
                }


            }//New if checker
    };
}