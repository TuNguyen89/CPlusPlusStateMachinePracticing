/*
 * CruiseControl_test.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: bxdai
 */


#include "CruiseControl.h"
#include "common.cpp"

int main (int argc, char *argv[])
{

   std::string inputFile = inputFileName;
   //if (argc < 3) {
   //   cout << "ERROR: the number of argument is not correct, "
   //        << "please pass the file name of input.text and output.txt" << endl;

   //   cout << "Usage: " << argv[0] << " inputPath" << " expectedOutputPath " << endl;
   //   
   //   system("PAUSE");
   //   return 0;
   //}

   //inputFile = argv[1];
   //std::string expectedOutputFile = argv[2];

   //Step 1: Parse the input data
   vector<UserInput> inputList = parseInputFile(inputFile);

   //Step 2: Handle each action
   CruiseControl control;
   //Open and clean the ouput file
   ofstream output(outputFileName, std::ofstream::out, std::ofstream::trunc);

   // FOR each action in the list
   for (vector<UserInput>::iterator item = inputList.begin(); item != inputList.end(); ++item)
   {
      control.handleAction(convertUserInput(item->type), 
                           item->carSpeed);

      //Get the status and put into output file
      output << control.getStatus();
   }

   output.close();
   
   //if(equal_files(outputFileName, expectedOutputFile)) {
   //   cout << "True" << endl;
   //} else {
   //   cout << "False" << endl;
   //}


   system("PAUSE");
   return 0;
}