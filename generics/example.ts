
class Collection<T> {
    private elements: T[];

    public constructor() {
        this.elements = [];
    }

    public append(value: T): void {
        this.elements.push(value);
    }

    public at(index: number): void T | null {
        if (index >= this.elements.length)
            return null;
        return this.elements[index];
    }
}

function main() {
    let myInts = new Collection<number>();
    
    myInts.append(1);
    console.log(myInts.at(0));

    myInts.append(2);
    myInts.append(3);
    console.log(myInts.at(2));
    console.log(myInts.at(1));

    let myStrings = new Collection<string>();
    myStrings.append("hello");
    console.log(`${myStrings.at(1)} world`);
}

main();

