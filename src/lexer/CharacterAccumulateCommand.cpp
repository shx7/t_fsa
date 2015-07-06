#include "CharacterAccumulateCommand.h"
void CharacterAccumulateCommand::command(unsigned char input) {
#ifdef CHARACTER_ACCUMULATE_COMMAND_DEBUG
    cout << "CharacterAccumulateCommand::command(" << input << ")" << endl;
#endif
    buffer += input;
}

string CharacterAccumulateCommand::getBuffer() {
    return buffer;
}

void CharacterAccumulateCommand::clearBuffer() {
    buffer.clear();
} 
