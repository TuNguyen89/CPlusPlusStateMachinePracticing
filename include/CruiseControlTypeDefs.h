
#ifndef CRUISECONTROLTYPEDEFS_H_
#define CRUISECONTROLTYPEDEFS_H_

typedef enum UserInputType {
   ON = 0,
   SET,
   RESUME,
   BRAKE,
   ACCP,
   ACCR,
   INVALID_TYPE
} e_UserInputType;

typedef struct UserInput
{
   e_UserInputType type;
   unsigned int    carSpeed;
} UserInput;

#endif /*CRUISECONTROLTYPEDEFS_H*/