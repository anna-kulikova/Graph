#include <gtest.h>
#include "graph.h"

TEST(Graph, can_create_graph)
{
	ASSERT_NO_THROW(Graph *g = new Graph(5, 10));
}

TEST(Graph, throws_when_created_graph_with_number_of_vertices_bigger_than_MAX_VERTICE_NUM)
{
	ASSERT_ANY_THROW(Graph *g = new Graph(5, 100));
}

TEST(Graph, can_get_set_of_edges)
{
	Graph g(5, 10);
	ASSERT_NO_THROW(g.GetEdge(1));
}

TEST(Graph, created_graph_is_empty)
{
	Graph g(5, 10);
	EXPECT_EQ(10, g.GetEdgesSize());
}

TEST(Graph, can_fill_rand_graph)
{
	Graph g(5, 10);
	ASSERT_NO_THROW(g.CreateGraph(1, 5));
}

TEST(Graph, can_get_number_of_vertices)
{
	Graph g(5, 10);
	g.CreateGraph(1, 5);
	EXPECT_EQ(g.GetRealSize(), 10);
}

TEST(Graph, can_add_edge_to_graph)
{
	Graph g(5, 10);
	ASSERT_NO_THROW(g.Push(1, 2, 3));
}

TEST(Graph, throws_when_set_weight_have_incorrect_first_or_second_argument)
{
	Graph g(5, 10);
	ASSERT_ANY_THROW(g.Push(2, 100, 1));
}

TEST(Graph, can_get_weight)
{
	Graph g(5, 10);
	g.CreateGraph(1, 5);
	ASSERT_NO_THROW(g.GetWeight(1, 2));
}

TEST(Graph, throws_when_get_weight_have_incorrect_first_or_second_argument)
{
	Graph g(5, 10);
	g.CreateGraph(1, 5);
	ASSERT_ANY_THROW(g.GetWeight(1, 20));
}

TEST(Graph, get_weight_works_properly)
{
	Graph g(5, 10);
	g.Push(1, 2, 1);
	EXPECT_EQ(1, g.GetWeight(1, 2));
}

TEST(Graph, can_erase_edge)
{
	Graph g(5, 10);
	g.CreateGraph(-100, 100);
	ASSERT_NO_THROW(g.Remove(1, 2));
}
