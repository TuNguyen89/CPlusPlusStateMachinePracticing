#include "CommonTestFunctions.h"
#include "AdaptiveCruiseControl.h"

int main (int argc, char *argv[])
{

   std::string inputFile = inputFileName;
   //if ( (argc == 2) )

   if ( (argc == 2) && (std::string(argv[1]) == "--console"))
   {
      AdaptiveCruiseControl control;
      for (;;) {
          std::string action;
          std::string speedValue;
          unsigned int speed = 0;
          cout << "Please in put your action: ";
          cin >> action >> speedValue;
          if (action == "quit" || action == "q" ) break;

          if(action == "" || speedValue == "") continue;
          speed = atoi(speedValue.c_str());
          e_UserInputType accUserInput = getUserInputTypeFromString(action);
          if( accUserInput == INVALID_TYPE ) {
             cout << "INVALID input: failed" << endl;
             continue;
          }
          control.handleAction(convertAccUserInput(accUserInput), 
                         allocateMotorData(speed));
          cout << "-----------------------------" << endl;
        }
        system("PAUSE");
        return 0;

   }
   else if (argc < 3)
   {
      cout << "ERROR: the number of argument is not correct." << endl
           << "   + please pass the file name of input.text and output.txt" << endl;
      cout << "         Usage: " << argv[0] << " inputPath" << " expectedOutputPath " << endl
           << "   + please pass --console to use terminal input" << endl;
      cout << "         Usage: " << argv[0] << " --console " << endl;
      system("PAUSE");
      return 0;
   }

   inputFile = argv[1];
   std::string expectedOutputFile = argv[2];

   //Step 1: Parse the input data
   vector<UserInput> inputList = parseInputFile(inputFile);

   //Step 2: Handle each action
   AdaptiveCruiseControl control;
   //Open and clean the ouput file
   ofstream output(outputFileName, std::ofstream::out, std::ofstream::trunc);

   // FOR each action in the list
   for (vector<UserInput>::iterator item = inputList.begin(); item != inputList.end(); ++item)
   {
      
      control.handleAction(convertAccUserInput(item->type), 
                           allocateMotorData(item->carSpeed));

      //Get the status and put into output file
      output << control.getStatus();
   }

   output.close();
   
   if(equal_files(outputFileName, expectedOutputFile)) {
      cout << "True" << endl;
   } else {
      cout << "False" << endl;
   }
   
   system("PAUSE");
   return 0;
}