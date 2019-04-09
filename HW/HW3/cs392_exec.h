#ifndef EXEC_H
#define EXEC_H
    int countCommands(char * str);
    char ** parseCommand(char * unparsedCommand);
    void executeCommand(char * command);
#endif
