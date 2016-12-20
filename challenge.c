#include "suffix_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  //http://stackoverflow.com/questions/7856741/how-can-i-load-a-whole-file-into-a-string-in-c
  // read a file into a string
  char *file_contents;
  long input_file_size;
  FILE *input_file = fopen("input.txt", "rb");
  fseek(input_file, 0, SEEK_END);
  input_file_size = ftell(input_file);
  rewind(input_file);
  file_contents = malloc(input_file_size * (sizeof(char)));
  fread(file_contents, sizeof(char), input_file_size, input_file);
  fclose(input_file);

	/*Create the suffix tree*/
	SUFFIX_TREE* tree = ST_CreateTree(file_contents, input_file_size-1);
	
	/*Print the suffix tree.*/
	//ST_PrintTree(tree);

	printf("{\n");
  int count = recurse(tree->root, tree->tree_string, tree);
  printf("}\n");
  //printf("\nCount is %d.\n\n",count);
	
	/*Delete the tree and all its nodes.*/
	ST_DeleteTree(tree);
  free(file_contents);

  return 0;
}
int recurse(NODE* node, char* str, SUFFIX_TREE* tree){
  if(node->sons == NULL){
    return 1;
  } else {
    int leafCount = 0;
    NODE* child = node->sons;
    while(child != NULL){
      leafCount += recurse(child, str, tree);
      child = child -> right_sibling;
    }
    if(leafCount > 1){
      int end = get_node_label_end(tree,node);
      if(end > node->path_position-1){
        int i, end_spot;
        for(end_spot = node->edge_label_start; end_spot<=end;end_spot++){
          putchar('\"');
          for(i = node->path_position; i <= end_spot; i++){
            putchar(str[i]);
          }
          printf("\":%d,\n",leafCount);
        }
      }
    }
    return leafCount;
  }

}
