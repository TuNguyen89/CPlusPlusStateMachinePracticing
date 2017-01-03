
#ifndef COMMONTESTFUNCTION_H_
#define COMMONTESTFUNCTION_H_

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
#include "CruiseControlConfig.h"

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::ofstream;
using std::ifstream;

/// Constant value
const string outputFileName = CruiseControl_OUTPUT_FILE_DIR;
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

const std::ios_base::openmode outputAndDiscardExisingContentMode = (std::ofstream::out | std::ofstream::trunc);

bool equal_files(const std::string& a, const std::string& b);

e_UserInputType getUserInputTypeFromString(const string& a_inputType);

ActionEnum convertUserInput(e_UserInputType a_userInput);

AccActionEnum convertAccUserInput(e_UserInputType a_userInput);

vector<UserInput> parseInputFile(string fileName);

std::string removeAllSpace(string& orgin);

bool compareTwoLinesSpacesRegaless(const std::string& left, const std::string& right);

MotorData* allocateMotorData(int speed = 10);

#endif /*COMMONTESTFUNCTION_H_*/