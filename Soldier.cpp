//
// Created by LioraPinkhasov on 20/05/2020.
//

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

using namespace std;
//using namespace Soldier;



using namespace WarGame;
Soldier::Soldier(int player)
{
    cout<< "Solider Built1" << endl;

}
Soldier::Soldier(int player, Type type, int HP) : playerNumber(player), type(type), HP(HP)
{
    cout<< "Solider Built2" << endl;
}


