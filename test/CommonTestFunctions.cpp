
#include <cctype>
#include "CommonTestFunctions.h"


e_UserInputType getUserInputTypeFromString(const string& a_inputType)
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
   ifstream inputFile(fileName.c_str());
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

         //Reset the value
         userInput = "";
         carCurrentSpeed = 0;
      }
   }

   inputFile.close();

   return inputList;
}



std::string removeAllSpace(string& orgin)
{
   orgin.erase(std::remove_if(orgin.begin(), orgin.end(), std::isspace),
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

bool equal_files(const std::string& leftFileName, const std::string& rightFileName)
{
   bool ret = true;
   ifstream file1(leftFileName.c_str());
   ifstream file2(rightFileName.c_str());
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


MotorData* allocateMotorData(int speed)
{
   MotorData* data = new MotorData();
   data->speed = speed;
   return data;
}