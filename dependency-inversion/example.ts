
interface Logger {
    write(value: string): void;
}

class PrintLogger implements Logger {
    private indentWidth: number;

    public constructor(indentWidth: number) {
        this.indentWidth = indentWidth;
    }

    public write(value: string): void {
        const indent = " ".repeat(this.indentWidth);
        console.log(indent + value);
    }
}

function doBusiness(logger: Logger) {
    logger.write("prices skyrocket");
    logger.write("greed buying");
    logger.write("prices drop");
    logger.write("panic selling");
}

function main() {
    let logger = new PrintLogger(2);
    doBusiness(logger);
}

main();

