# cmake_minimum_required(VERSION <specify CMake version here>)
project(wargame-b-master)

set(CMAKE_CXX_STANDARD 17)

add_executable(wargame-b-master Board.cpp Board.hpp FootCommander.hpp FootCommander.cpp FootSoldier.hpp FootSoldier.cpp  Paramedic.hpp Paramedic.cpp ParamedicCommander.hpp ParamedicCommander.cpp Sniper.hpp Sniper.cpp SniperCommander.hpp SniperCommander.cpp Soldier.cpp Soldier.hpp  utils.h myrun.cpp)