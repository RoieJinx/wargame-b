/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

#include <cassert>

namespace WarGame {

		DemoGame::DemoGame(): board (numRows, numCols) {
		// Add soldiers for player 1:
			//assert(!board.has_soldiers(1));
			board[{0,1}] = new SniperCommander(1);
			board[{0,0}] = new Sniper(1);
			//board[{0,3}] = new FootCommander(1);
		//	board[{0,0}] = new FootSoldier(1);
			//assert(board.has_soldiers(1));
            std::cout<<"player one soldiers ready!"<<endl;
			// Add soldiers for player 2:
			//assert(!board.has_soldiers(2));
			board[{5,1}] = new FootSoldier(2);
			//board[{2,1}] = new FootCommander(2);
			board[{6,2}] = new Paramedic(2);
           // board[{7,7}] = new ParamedicCommander(2);
			//assert(board.has_soldiers(2));
            std::cout<<"player two soldiers ready!"<<endl;

			// In your game, you can put more soldier types, such as the sniper and the paramedic types.
		}

		uint DemoGame::play() {
            std::cout<<"Start play()"<<endl;
			board.move(1, {0,1}, Board::MoveDIR::Up);
            std::cout << "it moved" << endl;
            board.move(2, {7,7}, Board::MoveDIR::Down);

           /* std::cout<<"line 40"<<endl;
			// FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
			if (!board.has_soldiers(2)) return 1;
            std::cout<<"line 43"<<endl;
			board.move(2, {7,1}, Board::MoveDIR::Down);
            std::cout<<"line 45"<<endl;// FootSoldier of player 2 moves forward and attacks from {7,1} to {6,1}.
			if (!board.has_soldiers(1)) return 2;
            std::cout<<"line 47"<<endl;
			board.move(1, {0,3}, Board::MoveDIR::Up);
            std::cout<<"line 49"<<endl;// FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack.
			if (!board.has_soldiers(2)) return 1;
            std::cout<<"line 51"<<endl;

			board.move(2, {7,3}, Board::MoveDIR::Left);
            std::cout<<"line 54"<<endl;// FootCommander of player 2 moves left from {7,3} to {7,2}, and all soldiers of player 2 attack.
			if (!board.has_soldiers(1)) return 2;
            std::cout<<"line 56"<<endl;*/

			/// Write more moves here..

			// If no player won, return "tie":
			return 0;

		}

		DemoGame::~DemoGame() {
			for (int iRow=0; iRow<numRows; ++iRow) {
				for (int iCol=0; iCol<numCols; ++iCol) {
					Soldier* soldier = board[{iRow,iCol}];
					if (soldier)
						delete soldier;
				}
			}
		}

}
