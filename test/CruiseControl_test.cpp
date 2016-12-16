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
const string outputFileName = "test/Output.txt";
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


ActionEnum convertUserInput(e_UserInputType a_userInput)
{
   switch (a_userInput)
   {
      case ON:
         return OnAction;
      
      case SET:
         return SetAction;
      
      case RESUME:
         return ResumAction;
      
      case BRAKE:
         return BreakAction;
      
      case ACCP:
         return AccPressedAction;

      case ACCR:
         return AccReleasedAction;

      case INVALID_TYPE:
      default:
         std::cout << "ERROR: Invalid input type" << endl;
         return InvalidAction;
         break;
   }

   return InvalidAction;
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

   inputFile.close();

   return inputList;
}



int main (int argc, char *argv[])
{
   //Step 1: Parse the input data
   vector<UserInput> inputList = parseInputFile(inputFileName);

   //Step 2: Handle each action
   CruiseControl control = CruiseControl();
   ofstream output(outputFileName, std::ofstream::out);


   for (vector<UserInput>::iterator item = inputList.begin(); item != inputList.end(); ++item)
   {
      control.handleAction(convertUserInput(item->type), 
                           item->carSpeed);

      output << control.getStatus();
   }

   output.close();

   system("PAUSE");
   return 0;
}