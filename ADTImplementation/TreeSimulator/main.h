typedef enum {
    QUIT = 0,
    HELP,
    INSERT,
    PRINT,
    DELETE,
    CLEAR,
    TRAVERSAL,
    INSERT_MANY,
    COMMAND_NUMBER,
    UNKNOWN_COMMAND = 999
} Command;

typedef enum {
    IN_ORDER = 0,
    PRE_ORDER,
    POST_ORDER,
    SUBCOMMAND_NUMBER,
    UNKNOWN_SUBCOMMAND = 999
} Subcommand;