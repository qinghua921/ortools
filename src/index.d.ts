declare module 'addon'
{
    export class Calculator
    {
        constructor(initialValue: number);

        add(value: number): number;
        subtract(value: number): number;
    }
}