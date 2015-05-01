#include "Lexer.h"

void Lexer::runParse() {
    // Run test 
    InputSequence input;
    input_ >> std::noskipws;
    while (!input_.eof()) {
        char chr;
        input_ >> chr;
        input.push_back(chr);
    } 
    input.push_back(0);

    Engine engine; 
    EngineReport report = engine.run(transitionGraph, input);
    report.print();

    printTokenContainer();
}

void Lexer::pushToken(Token& token) {
#ifdef LEXER_DEBUG 
    cout << "Lexer::pushToken()" << endl; 
#endif
    tokenContainer_.push_back(token);
}

void Lexer::printTokenContainer() {
    TokenContainer::iterator itr;
    for (itr = tokenContainer_.begin(); itr != tokenContainer_.end(); itr++) {
        (*itr).print();
    }
}

unsigned char Lexer::getNextChar() {
    unsigned char chr = input_.get();
    std::locale loc;
    chr = std::tolower(chr, loc);
    return chr;
}

void Lexer::createTransitionGraph() {
    // Form an finite state machine
    DEFINE_STATE(start_st, STATE_START_FINAL);
    ADD_TRANSITION_P(start_st, P_WHITE, start_st);

    // Any word. Will be preprocessed later
    wordCtrlCmd.assotiateWithLexer(this);
    wordCtrlCmd.assotiateWithCommand(&characterAccumulateCmd, L_IDENTIFIER);
    DEFINE_STATE(word_st, STATE_ORDINARY);
    ADD_TRANSITION_SEM_P(start_st, P_CHARACTER, word_st, characterAccumulateCmd);
    ADD_TRANSITION_SEM_P(word_st, P_CHARACTER, word_st, characterAccumulateCmd);
    ADD_TRANSITION_SEM_P(word_st, P_DIGIT, word_st, characterAccumulateCmd);
    ADD_TRANSITION_SEM_P(word_st, P_WHITE, start_st, wordCtrlCmd);
    ADD_TRANSITION_SEM(word_st, ';', start_st, wordCtrlCmd);
    ADD_TRANSITION_SEM(word_st, '{', start_st, wordCtrlCmd);

    // L_OPEN_PARENTHESIS lexem
    openParenthesisCtrlCmd.assotiateWithLexer(this);
    openParenthesisCtrlCmd.assotiateWithCommand(&nullCmd, L_OPEN_PARENTHESIS);
    ADD_TRANSITION_SEM(start_st, '{', start_st, openParenthesisCtrlCmd);

    // L_CLOSING_PARENTHESIS lexem
    closingParenthesisCtrlCmd.assotiateWithLexer(this);
    closingParenthesisCtrlCmd.assotiateWithCommand(&nullCmd, L_CLOSING_PARENTHESIS);
    ADD_TRANSITION_SEM(start_st, '}', start_st, closingParenthesisCtrlCmd);

    // L_TRANSITION lexem
    transitionCtrlCmd.assotiateWithLexer(this);
    transitionCtrlCmd.assotiateWithCommand(&nullCmd, L_TRANSITION);
    DEFINE_STATE(trans_st1, STATE_ORDINARY);
    ADD_TRANSITION(start_st, '=', trans_st1);
    ADD_TRANSITION_SEM(trans_st1, '>', start_st, transitionCtrlCmd);
    
    // L_SEMICOLON lexem
    semicolonCtrlCmd.assotiateWithLexer(this);
    semicolonCtrlCmd.assotiateWithCommand(&nullCmd, L_SEMICOLON);
    ADD_TRANSITION_SEM(start_st, ';', start_st, semicolonCtrlCmd); 

    // L_CHAR lexem
    charCtrlCmd.assotiateWithLexer(this);
    charCtrlCmd.assotiateWithCommand(&characterAccumulateCmd, L_CHAR);
    DEFINE_STATE(chr_st_0, STATE_ORDINARY);
    DEFINE_STATE(chr_st_1, STATE_ORDINARY);
    ADD_TRANSITION(start_st, '\'', chr_st_0);
    ADD_TRANSITION_SEM_P(chr_st_0, P_CHARACTER, chr_st_1, characterAccumulateCmd);
    ADD_TRANSITION_SEM_P(chr_st_0, P_DIGIT, chr_st_1, characterAccumulateCmd);
    ADD_TRANSITION_SEM(chr_st_1, '\'', start_st, charCtrlCmd); 
}

void Lexer::initReservedWords() {
    reserved_words_["automaton"] = L_AUTOMATON;
    reserved_words_["state"] = L_STATE;
    reserved_words_["final"] = L_FINAL;
    reserved_words_["start"] = L_START;
    reserved_words_["start"] = L_START;
    reserved_words_["{"] = L_OPEN_PARENTHESIS;
    reserved_words_["}"] = L_CLOSING_PARENTHESIS;
    reserved_words_["=>"] = L_TRANSITION;
    reserved_words_[";"] = L_SEMICOLON;
}

LexemType Lexer::parseLexemType(string& word) {
#ifdef LEXER_DEBUG
    cout << "Lexer:::parseLexemType()" << endl;
#endif
    if (reserved_words_.find(word) != reserved_words_.end()) {
        return reserved_words_[word];
    }
    return L_IDENTIFIER;
}

bool Lexer::match(LexemType) {
    return false;
}
