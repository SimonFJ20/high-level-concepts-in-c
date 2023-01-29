#include <stdio.h>

typedef struct Logger {
    void (*destroy)(struct Logger*);
    void (*write)(struct Logger*, const char*);
} Logger;

typedef struct PrintLogger {
    void (*destroy)(struct PrintLogger*);
    void (*write)(struct PrintLogger*, const char*);
    int indent_amount;
} PrintLogger;

void destroy_print_logger(struct PrintLogger* self) { (void)self; }

void print_logger_write(PrintLogger* self, const char* value)
{
    for (int i = 0; i < self->indent_amount; ++i)
        fputc(' ', stdout);
    printf("%s\n", value);
}

void create_print_logger(PrintLogger* self, int indent_amount)
{
    *self = (PrintLogger) {
        .destroy = destroy_print_logger,
        .write = print_logger_write,
        .indent_amount = indent_amount,
    };
}

void do_business(Logger* logger)
{
    logger->write(logger, "prices skyrocket");
    logger->write(logger, "greed buying");
    logger->write(logger, "prices drop");
    logger->write(logger, "panic selling");
}

int main()
{
    PrintLogger logger;
    create_print_logger(&logger, 2);

    do_business((Logger*)&logger);

    destroy_print_logger(&logger);
    // logger->destroy(&logger); does the same, but +1 instruction
}
