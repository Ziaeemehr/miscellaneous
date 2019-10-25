#include <igraph.h>
#include <stdio.h>

int main() {
  
  igraph_t g;
  igraph_bool_t simple;

  igraph_barabasi_game(/* graph=    */ &g, 
		       /* n=        */ 100,
		       /* power=    */ 1.0,
		       /* m=        */ 2,
		       /* outseq=   */ 0,
		       /* outpref=  */ 0,
		       /* A=        */ 1.0,
		       /* directed= */ IGRAPH_DIRECTED,
		       /* algo=     */ IGRAPH_BARABASI_PSUMTREE,
		       /* start_from= */ 0);
  
  if (igraph_ecount(&g) != 197) { return 1; }
  if (igraph_vcount(&g) != 100) { return 2; }
  igraph_is_simple(&g, &simple);
  if (!simple) { return 3; }
  
  igraph_destroy(&g);
  
  /* ============================== */

  igraph_barabasi_game(/* graph=    */ &g, 
		       /* n=        */ 100,
		       /* power=    */ 1.0,
		       /* m=        */ 2,
		       /* outseq=   */ 0,
		       /* outpref=  */ 0,
		       /* A=        */ 1.0,
		       /* directed= */ IGRAPH_DIRECTED,
		       /* algo=     */ IGRAPH_BARABASI_PSUMTREE_MULTIPLE,
		       /* start_from= */ 0);

  if (igraph_ecount(&g) != 198) { return 4; }
  if (igraph_vcount(&g) != 100) { return 5; }
  igraph_is_simple(&g, &simple);
  if (simple) { return 6; }
  
  igraph_destroy(&g);

  /* ============================== */

  igraph_barabasi_game(/* graph=    */ &g, 
		       /* n=        */ 100,
		       /* power=    */ 1.0,
		       /* m=        */ 2,
		       /* outseq=   */ 0,
		       /* outpref=  */ 0,
		       /* A=        */ 1.0,
		       /* directed= */ IGRAPH_DIRECTED,
		       /* algo=     */ IGRAPH_BARABASI_BAG,
		       /* start_from= */ 0);

  if (igraph_ecount(&g) != 198) { return 7; }
  if (igraph_vcount(&g) != 100) { return 8; }
  igraph_is_simple(&g, &simple);
  if (simple) { return 9; }
  
  igraph_destroy(&g);    
  
  return 0;
}

