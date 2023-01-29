
function hasValue(values: number[], predicate: (value: number) => boolean): boolean {
    for (const value of values)
        if (predicate(value))
            return true;
    return false;
}

function main() {
    const target = 2;
    const values = [1, 2, 3];
    const containsTarget = hasValue(values, (value) => value == target);
    if (containtsTarget)
        console.log(`containts ${target}`);
}

main();

