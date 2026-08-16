// src/parsing/read_stdin.c

char *read_all_stdin(void)
{
    char    *buf;
    size_t  cap;
    size_t  len;
    ssize_t r;

    cap = 1 << 20; // 1MB start, doubles as needed
    buf = malloc(cap);
    if (!buf)
        exit_error("malloc");
    len = 0;
    while ((r = read(0, buf + len, cap - len)) > 0)
    {
        len += (size_t)r;
        if (len == cap)
        {
            cap *= 2;
            buf = realloc(buf, cap);
            if (!buf)
                exit_error("realloc");
        }
    }
    buf[len] = '\0';
    return (buf);
}

// this gives me a whole file as one string

// returns pointer to start of next line, advances *cursor, mutates buf
// by writing '\0' at the newline (in-place tkenization, no allocs)
char *next_line(char **cursor)
{
    char *start;

    if(!**cursor)
        return (NULL);
    start = *cursor; // first character
    while(**cursor && **cursor != '\n') // advance till new line
        *cursor++;
    if(**cursor == '\n')
    {
        **cursor = '\0'; // mutate buf
        (*cursor)++; // advance cursor
    }
    return (start); 
}
