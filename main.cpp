// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <random>
#include "world.h"
#include <fstream>
#include "DataParser.h"



int main()
{
    string file = "DOCOData01.xml";
    int width = 0;
    int height = 0;
    int x = 0, y = 0;
    char c;
    DataParser* dp = dp->getInstance(file.c_str());

    width = dp->getDOCOWorldWidth();
    height = dp->getDOCOWorldHeight();
    while (dp->getDOCOData(&c, &x, &y))
    {
        cout << x << endl;
        cout << y << endl;
    }
    return 0;


    std::fstream infile;
    bool run = false;
    string dataFile = "DOCOData01.xml";
    int turns = -1;

    while (!run)
    {
        system("cls");
        string turnString;
        if (turns == -1)
        {
            turnString = "INDEFINITE";
        }
        else
        {
            turnString = to_string(turns);
        }
        
        std::cout << "Simulation will run based on datafile " << dataFile << ", for " << turnString << " turns."
            << std::endl << "1. Run with theses parameters" << std::endl << "2. Change datafile" << std::endl
            << "3. Edit turns" << std::endl;
        int selection;
        cin >> selection;
        switch (selection)
        {
        case 1:
            infile.open(dataFile);
            if (!infile)
            {
                string temp = dataFile;
                dataFile = "***'";
                dataFile.append(temp);
                dataFile.append("' could not be opened***");
            }
            else
            {
                run = true;
            }
            break;
        case 2:
            std::cout << "Enter new datafile name, including the file extension." << std::endl;
            cin >> dataFile;
            break;
        case 3:
            std::cout << "Enter number of turns. For indefinite, use -1." << std::endl;
            cin >> turns;
            break;
        default:
            std::cout << "Invalid selection, please try again" << std::endl;
            break;
        }
    }
    srand((unsigned int)time(0));
    world w(dataFile.c_str());
    system("cls");
    w.run(turns);


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
