// Project:     BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author:      Carlos Rodriguez
// Date:        July 9, 2022
// Purpose:     Bubble sort data obtained from a text file


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>


using namespace std;


// Forward Declarations
void fileStream();                  // function used to grab data from text file
void bubbleSort();                  // function used to sort data with bubble sort method
void randNumGen(int, int, int);     // Crate random numbers for text file and write to it

vector<string> vDataList;           // data obtained from text file


int main()
{
    int num;
    printf("Enter Number >> ");
    cin >> num;
    randNumGen(num, 0, 100);
    fileStream();                   // call function to obtain data
    bubbleSort();
}


void fileStream()
{
    ifstream fileStream;                // file handler
    string fileName = "Data.txt";
    string temp = "";

    try {
        fileStream.open(fileName);      // open file

        if (!fileStream.is_open())
            throw "e";

        while (fileStream.good())       // while file has content
        {
            getline(fileStream, temp);  // grab content from file and store it in temp
            vDataList.push_back(temp);  // store temp in vector list
        }
        fileStream.close();             // close file

    }
    catch(string){
        printf("Error file missing!");
    }
}



void bubbleSort()
{
    string temp = "";
    for (int x = 0; x < vDataList.size(); x++)                  // outter for loop
    {
        for (int y = 0; y < vDataList.size()-2; y++)            // inner for loop
        {
            if (stoi(vDataList[y]) > stoi(vDataList[y + 1]))                // if previous is greater than next switch
            {
                temp = vDataList[y];
                vDataList[y] = vDataList[y + 1];
                vDataList[y + 1] = temp;
            }
        }
    }
    for(int x = 0; x < vDataList.size(); x++)
        cout << vDataList[x] << " ";
}


void randNumGen(int loopies, int iMin, int iMax) {
    ofstream fileWrite;                             // file handler
    string fileName = "Data.txt";

    fileWrite.open(fileName);                       //open is the method of ofstream

    for (int x = 0; x < loopies; x++)
    {
        random_device rd;								// non-deterministic generator
        mt19937 gen(rd());								// to seed mersenne twister.
        uniform_int_distribution<> dist(iMin, iMax);	// distribute results inside center rect

        fileWrite << dist(gen) << endl;
    }

    fileWrite.close();

}