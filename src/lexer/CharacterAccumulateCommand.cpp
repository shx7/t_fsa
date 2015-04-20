#include "CharacterAccumulateCommand.h"
void CharacterAccumulateCommand::command(unsigned char input) {
    buffer += input;
}

string CharacterAccumulateCommand::getBuffer() {
    return buffer;
}

void CharacterAccumulateCommand::clearBuffer() {
    buffer.clear();
} 
