cmake_minimum_required(VERSION 3.30)
project(M3OEP_mneves_jpancoas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        Bank.cpp
        Bank.h
        Games/Blackjack.cpp
        Games/Blackjack.h
        Games/Card.h
        Games/Card.cpp
        Casino.cpp
        Casino.h
        Game.h
        main.cpp
        Player.cpp
        Player.h
        StatTracker.cpp
        StatTracker.h
        Games/Roulette.cpp
        Games/Roulette.h
        Games/Slots.cpp
        Games/Slots.h
        Games/War.cpp
        Games/War.h)
add_executable(test
        Bank.cpp
        Bank.h
        Games/Blackjack.cpp
        Games/Blackjack.h
        Games/Card.h
        Games/Card.cpp
        Casino.cpp
        Casino.h
        Game.h
        test.cpp
        Player.cpp
        Player.h
        StatTracker.cpp
        StatTracker.h
        Games/Roulette.cpp
        Games/Roulette.h
        Games/Slots.cpp
        Games/Slots.h
        Games/War.cpp
        Games/War.h)