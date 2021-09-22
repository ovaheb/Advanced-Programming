#ifndef CATCH_MAIN
#define CATCH_MAIN
#endif

#include "catch.hpp"
#include "utrello_interface.hpp"
#include <stdexcept>
#include <string>

TEST_CASE("test")
{
    UTrelloInterface sampleInterface;
    cout << "simple :\n";
    cout << sampleInterface.addUser("omid") << endl;
    cout << sampleInterface.addUser("amid") << endl;
    cout << sampleInterface.addUser("damon") << endl;
    cout << sampleInterface.addList("chore") << endl;
    cout << sampleInterface.addList("fun") << endl;
    cout << sampleInterface.addList("work") << endl;
    cout << sampleInterface.addTask("fun", "play game", 1, 1, "play DOTA") << endl;
    cout << sampleInterface.addTask("fun", "watch movie", 2, 2, "joker") << endl;
    cout << sampleInterface.addTask("chore", "wash dishes", 1, 1, ":(") << endl;
    cout << sampleInterface.addTask("work", "write project 2", 12, 6, "comment where needed") << endl;
    cout << sampleInterface.addTask("work", "practice coding", 4, 3, "practice coding from stackoverflow") << endl;
    cout << sampleInterface.assignTask("play game", "omid") << endl;
    cout << sampleInterface.assignTask("write project 2", "amid") << endl;
    cout << sampleInterface.assignTask("practice coding", "amid") << endl;
    cout << sampleInterface.assignTask("watch movie", "damon") << endl;
    cout << sampleInterface.completeTask("practice coding") << endl;
    cout << sampleInterface.completeTask("play game") << endl;
    cout << sampleInterface.completeTask("watch movie") << endl;
    REQUIRE(sampleInterface.printTotalEstimatedTime() == 16);
    REQUIRE(sampleInterface.printTotalRemainingTime() == 12);
    REQUIRE(sampleInterface.printUserWorkload("omid") == 1);
    REQUIRE(sampleInterface.printUserWorkload("amid") == 16);
    REQUIRE(sampleInterface.printUserWorkload("damon") == 2);
    cout << "with delete :\n";
    cout << sampleInterface.deleteList("chore") << endl;
    cout << sampleInterface.deleteTask("write project 2") << endl;
    REQUIRE(sampleInterface.printTotalEstimatedTime() == 4);
    REQUIRE(sampleInterface.printTotalRemainingTime() == 0);
    REQUIRE(sampleInterface.printUserWorkload("omid") == 1);
    REQUIRE(sampleInterface.printUserWorkload("amid") == 4;
    REQUIRE(sampleInterface.printUserWorkload("damon") == 2);
    cout << "with edit :\n";
    cout << sampleInterface.editTask("practice coding", 10, 9, "use geeksforgeeks") << endl;
    cout << sampleInterface.editTask("play game", 5, 5, "play COD4") << endl;
    REQUIRE(sampleInterface.printTotalEstimatedTime() == 10);
    REQUIRE(sampleInterface.printTotalRemainingTime() == 0);
    REQUIRE(sampleInterface.printUserWorkload("omid") == 5);
    REQUIRE(sampleInterface.printUserWorkload("amid") == 10);
    REQUIRE(sampleInterface.printUserWorkload("damon") == 2);
}