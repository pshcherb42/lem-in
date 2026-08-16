// include/lem_in.h

typedef struct s_link           // tubes with properties
{
    int             room_id;    // room to which this tunnel leads   
    int             cap;        // 1 for duplicated intermidiate rooms. Unlimited for start/end.
    int             flow;       // flow = 1 means the room or the tunnel is occupied
    struct s_link   *next;      // points to the next link leaving from the same room
}   t_link;

typedef struct s_room           // each room is a node. Here I store it's properties.
{
    char    *name;              // room id
    int     x;                  // coordinates to verify "no duplicates" at the same position
    int     y;
    int     is_start;           // flags to know whether it's start or end room during search algorithms
    int     is_end;
    t_link  *edges;             // tells me which other rooms are connected to this one. "Adjacence list" 
}   t_room;

typedef struct s_farm           // the complete map. "Cerebro" that saves all the global sim info
{
    int     n_ants;             // num of ants to move. To know how many paths to open
    t_room  *rooms;
    int     n_rooms;            // tells me how many real rooms I saved
    int     rooms_cap;          // tells me how much memory I reserved
    int     start_id;           // indice inside of rooms
    int     end_id;             // indice inside of rooms
}   t_farm;

// I do not know how many rooms the map will have
// Edmonds-Karp or Dinic algorithms to find optimal ways between rooms
// BFS modificado algorithm fr searching

// rooms are stored in one growable array: data structure, stores a collection of variables at adjacent memory locations
