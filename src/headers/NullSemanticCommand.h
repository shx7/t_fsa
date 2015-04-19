/**************************************************************
*
*   PURPOSE: Contains empty function
*
***************************************************************/
#ifndef NULL_SEMANTIC_COMMAND
#define NULL_SEMANTIC_COMMAND
#include "SemanticCommand.h"

class NullSemanticCommand : public SemanticCommand {
    public:
        void command(unsigned char input) {};
};
#endif
