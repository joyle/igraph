/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2009-2012  Gabor Csardi <csardi.gabor@gmail.com>
   334 Harvard street, Cambridge, MA 02139 USA
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef IGRAPH_CLIQUES_H
#define IGRAPH_CLIQUES_H

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

#include "igraph_types.h"
#include "igraph_datatype.h"
#include "igraph_vector_ptr.h"

__BEGIN_DECLS

/* -------------------------------------------------- */
/* Cliques, maximal independent vertex sets           */
/* -------------------------------------------------- */

int igraph_maximal_cliques(const igraph_t *graph, igraph_vector_ptr_t *res,
                   igraph_integer_t min_size, igraph_integer_t max_size);
int igraph_maximal_cliques_file(const igraph_t *graph,
				FILE *outfile,
				igraph_integer_t min_size, 
				igraph_integer_t max_size);
int igraph_maximal_cliques_count(const igraph_t *graph,
				 igraph_integer_t *res, 
				 igraph_integer_t min_size, 
				 igraph_integer_t max_size);
int igraph_maximal_cliques_subset(const igraph_t *graph,
				  igraph_vector_int_t *subset,
				  igraph_vector_ptr_t *res,
				  igraph_integer_t *no,
				  FILE *outfile,
				  igraph_integer_t min_size,
				  igraph_integer_t max_size);

int igraph_cliques(const igraph_t *graph, igraph_vector_ptr_t *res,
                   igraph_integer_t min_size, igraph_integer_t max_size);
int igraph_clique_size_hist(const igraph_t *graph, igraph_vector_t *hist,
                   igraph_integer_t min_size, igraph_integer_t max_size);
int igraph_largest_cliques(const igraph_t *graph, 
			   igraph_vector_ptr_t *cliques);
int igraph_clique_number(const igraph_t *graph, igraph_integer_t *no);
int igraph_weighted_cliques(const igraph_t *graph,
                    const igraph_vector_t *vertex_weights, igraph_vector_ptr_t *res,
                    igraph_real_t min_weight, igraph_real_t max_weight, igraph_bool_t maximal);
int igraph_largest_weighted_cliques(const igraph_t *graph,
                    const igraph_vector_t *vertex_weights, igraph_vector_ptr_t *res);
int igraph_weighted_clique_number(const igraph_t *graph,
                    const igraph_vector_t *vertex_weights, igraph_real_t *res);
int igraph_independent_vertex_sets(const igraph_t *graph,
				   igraph_vector_ptr_t *res,
				   igraph_integer_t min_size,
				   igraph_integer_t max_size);
int igraph_largest_independent_vertex_sets(const igraph_t *graph,
					   igraph_vector_ptr_t *res);
int igraph_maximal_independent_vertex_sets(const igraph_t *graph,
					   igraph_vector_ptr_t *res);
int igraph_independence_number(const igraph_t *graph, igraph_integer_t *no);

/**
 * \typedef igraph_clique_handler_t
 * \brief Type of clique handler functions
 *
 * Callback type, called when a clique was found.
 *
 * See the details at the documentation of \ref
 * igraph_cliques_callback().
 *
 * \param clique The current clique. Destroying and freeing
 *   this vector is left to the user.
 * \param arg This extra argument was passed to \ref
 *   igraph_cliques_callback() when it was called.
 * \return Boolean, whether to continue with the clique search.
 */
typedef igraph_bool_t igraph_clique_handler_t(igraph_vector_t *clique, void *arg);

int igraph_cliques_callback(const igraph_t *graph,
                    igraph_integer_t min_size, igraph_integer_t max_size,
                    igraph_clique_handler_t *cliquehandler_fn, void *arg);


__END_DECLS

#endif
