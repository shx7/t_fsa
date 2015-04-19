/**************************************************************
*
*   PURPOSE: Interface for Command pattern. Incapsulate hook, 
*            that will run as specific semantics function
*
**************************************************************/
#ifndef SEMANTIC_COMMAND_H
#define SEMANTIC_COMMAND_H

class SemanticCommand {
    public:
        virtual void command(unsigned char input) = 0;
};

#endif
