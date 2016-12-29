#include "CruiseControlTypeDefs.h"
#include "CruiseControl.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <iterator>
#include "AdaptiveCruiseControl.h"


using namespace std;

const string inputFileName = "test/resource/Input.txt";
const string outputFileName = "test/resource/Output.txt";
const string inputOn = "on";
const string inputSet = "set";
const string inputResume = "resume";
const string inputBrake = "brake";
const string inputAccP = "accP";
const string inputAccR = "accR";
const string inputCancel = "cancel";
const string inputGas = "gas";
const string inputVehicelDetected = "detect";
const string inputNotVehicelDetected = "nodetect";

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
   
   if (a_inputType == inputCancel)
   {
      return CAN;
   }
   
   if (a_inputType == inputGas)
   {
      return GAS;
   }
   
   if (a_inputType == inputVehicelDetected)
   {
      return DETECT;
   }

   if (a_inputType == inputNotVehicelDetected)
   {
      return NODETECT;
   }
   return INVALID_TYPE;
}


ActionEnum convertUserInput(e_UserInputType a_userInput)
{
   switch (a_userInput)
   {
      case ON:
         return E_ACTION_ON;
      
      case SET:
         return E_ACTION_SET;
      
      case RESUME:
         return E_ACTION_RESUME;
      
      case BRAKE:
         return E_ACTION_BRAKE;
      
      case ACCP:
         return E_ACTION_ACC_PRESSED;

      case ACCR:
         return E_ACTION_ACC_RELEASED;

      case INVALID_TYPE:
      default:
         std::cout << "ERROR: Invalid input type" << endl;
         return E_ACTION_INVALID;
         break;
   }

   return E_ACTION_INVALID;
}

AccActionEnum convertAccUserInput(e_UserInputType a_userInput)
{
   switch (a_userInput)
   {
      case ON:
         return E_ACTION_PRESS_ACC_BUTTON;

      case SET:
         return E_ACTION_PRESS_SET_BUTTON;

      case RESUME:
         return E_ACTION_PRESS_RESUME_BUTTON;
      
      case BRAKE:
         return E_ACTION_PUSH_BRAKE_PEDAL;
      
      case CAN:
         return E_ACTION_PUSH_CANCEL_BUTTON;

      case GAS:
         return E_ACTION_PUSH_GAS_PEDAL;

      case DETECT:
         return E_ACTION_DECTECT_VEHICLE;
         
      case NODETECT:
         return E_ACTION_NOT_DECTECT_VEHICLE;

      case INVALID_TYPE:
      default:
         std::cout << "ERROR: Invalid input type" << endl;
         return E_ACTION_ACC_INVALID;
         break;
   }

   return E_ACTION_ACC_INVALID;
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



std::string removeAllSpace(string& orgin)
{
   orgin.erase(std::remove(orgin.begin(), orgin.end(), ' '),
      orgin.end());

   return orgin;
}

bool compareTwoLinesSpacesRegaless(const string& left, const string& right)
{
   std::string copyOfLeft = left;
   std::string copyOfRight = right;

   if (removeAllSpace(copyOfLeft) != removeAllSpace(copyOfRight))
   {
      std::cout << "left >>>>>>>" << endl;
      std::cout << copyOfLeft << endl;
      std::cout << copyOfRight << endl;
      std::cout << "<<<<<< right" << endl;
      return false;
   }
   else
   {
      return true;
   }
}

bool equal_files(const std::string& a, const std::string& b)
{
   bool ret = true;
   ifstream file1(a);
   ifstream file2(b);
   while ((!file1.eof()) && (!file2.eof()))
   {
      std::string line1,line2;
      getline(file1,line1);
      getline(file2,line2);
      if (!compareTwoLinesSpacesRegaless(line1, line2))
      {
         file1.close();
         file2.close();
         return false;
      }
   }

   file1.close();
   file2.close();
   
   return ret;
}


MotorData* allocateMotorData(int speed = 10)
{
   MotorData* data = new MotorData();
   data->speed = speed;
   return data;
}