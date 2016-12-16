/*
 * CruiseControl_test.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: bxdai
 */

#include "CruiseControlTypeDefs.h"
#include "CruiseControl.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>



using namespace std;

const string inputFileName = "test/Input.txt";
const string inputOn = "on";
const string inputSet = "set";
const string inputResume = "resume";
const string inputBrake = "brake";
const string inputAccP = "accP";
const string inputAccR = "accR";


e_UserInputType getUserInputTypeFromString(string a_inputType)
{
   if (a_inputType == inputOn) 
   {
      return ON;
   }

   if (a_inputType == inputSet)
   {
      return SET;
   }

   if (a_inputType == inputResume)
   {
      return RESUME;
   }

   if (a_inputType == inputBrake)
   {
      return BRAKE;
   }

   if (a_inputType == inputAccP)
   {
      return ACCP;
   }

   if (a_inputType == inputAccR)
   {
      return ACCR;
   }

   return INVALID_TYPE;
}


vector<UserInput> parseInputFile(string fileName)
{
   ifstream inputFile(fileName);
   vector <UserInput> inputList;
   
   if (!inputFile)
   {
      cout << "ERROR open file: " << fileName << endl;
      return inputList;
   }

   string userInput;
   unsigned int carCurrentSpeed = 0;
   UserInput item;
   while (!inputFile.eof())
   {
      inputFile >> userInput;
      inputFile >> carCurrentSpeed;

      if (getUserInputTypeFromString(userInput) != INVALID_TYPE)
      {
         item.type = getUserInputTypeFromString(userInput);
         item.carSpeed = carCurrentSpeed;

         inputList.push_back(item);
      }
   }

   return inputList;
}



int main (int argc, char *argv[])
{
   //Step 1: Parse the input data
   vector<UserInput> inputList = parseInputFile(inputFileName);

   for (vector<UserInput>::iterator item = inputList.begin(); item != inputList.end(); ++item)
   {
      cout << item->type << "\t" << item->carSpeed << endl;
   }

   CruiseControl control = CruiseControl();

   system("PAUSE");
   return 0;
}