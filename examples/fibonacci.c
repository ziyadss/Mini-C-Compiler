int fib_rec(int n)
{
    return n < 2 ? n : fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_it(int n)
{
    int a = 0, b = 1;
    while (--n)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int x = fib_rec(9), y = fib_it(9);
    return x == y ? 0 : 1;

    // return fib_rec(9) == fib_it(9) ? 0 : 1;
}
