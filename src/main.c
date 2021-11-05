#include "../inc/pathfinder.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        return -1;
    }
    
    char *file_str = mx_file_to_str(argv[1]);
    check_endlines(file_str);
    char **splitted_str = mx_strsplit(file_str, '\n');
    t_main *main = malloc(sizeof(t_main));
    main->splitted = splitted_str;

    parse_file(splitted_str, main);
    mat_init(main);
    cost_matrix(main);
    algorithm(main);
    paths_main(main);
    free(file_str);
    dealocate_mem(main);
    free(main);

    return 0;
}
