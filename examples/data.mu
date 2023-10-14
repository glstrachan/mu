link io

int a : 10
real b : 10.0, c : 5.0

bar f : bar(a, a)

data bar
    int a, b
    bar(int a, b) @a : a @b : b|
    sum() -> (int sum : a + b)||

main out("hello world")|

main () -> () out("hello world)|