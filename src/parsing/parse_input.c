// the three-pass parse
// 1. First non-comment, non-empty line = n_ants. Reject if <= 0 -> ERROR
// 2. Every subsequent line is euther:
    // a comment starting with # - special-case ##start/##end which set a flag for the next room
    // a room line: name x y - three tokens, x/ integers
    // a link line: name1-name2, only valid once room parsing is "done"(first line containing - and no spaces signals the link section began)

// 3. Stop at EOF
// ponter is a variable that stores an address
// double pointer is a varible thta stores an address that holds the address of another variable that stores an address
// it points to anoher pointer instead of variable
// duh if the pointer is a variable it should have an address
int parse_farm(t_farm *farm, char *buf)
{
    char *cursor;
    char *line;
    int pending_flag; // 0none, 1start, 2end

    cursor = buf;
    pending_flag = 0;
    if(!parse_ant_count(farm, &cursor))
        return (0);
    while(line = next_line(&cursor))
    {
        if(line[0] == '\0')
            continue;
        if(line[0] == '#' && line[1] == '#')
            pending_flag = handle_meta(line);
        else if(line[0] == '#') // regular comment skip
            continue;
        else if(ft_strchr(line, '-')){
            if(!parse_link(farm, line)) // once a link line is seen every subsequent room line is invalid
                return (0); // per subject: room lines must precede link lines
        }
        else{
            if(!parse_room(farm, line, pending_flag))
                return (0);
            pending_flag = 0;
        }
    }
    return (validate_farm(farm));
}